#include "Algorithm3D/MathEngine.h"
#include "Base3D/CommonDefine.h"
#include "Core/ROCacheManager.h"
#include "Core/Georeference.h"
#include "Runtime/Engine/Public/SceneView.h"
#include "Materials/MaterialInstanceDynamic.h"
#include <locale.h>

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

using namespace SuperMapSDK::UnrealEngine::Core;
namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace Algorithm3D
		{
			FVector MathEngine::m_vWorldOffset = FVector(0.0f, 0.0f, 637813700.0f);
			MathEngine::MathEngine()
			{

			}

			MathEngine::~MathEngine()
			{

			}

			FVector MathEngine::SphericalToCartesian(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dHeight)
			{
				Gamedouble dX, dY, dZ;
				_SphericalToCartesian(dLongitude, dLatitude, dHeight, dX, dY, dZ);
				FVector vCartesian = FVector(dX, dY, dZ);
				return vCartesian;
			}

			Vector3d MathEngine::SphericalToCartesian2(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dHeight)
			{
				Gamedouble dX, dY, dZ;
				_SphericalToCartesian(dLongitude, dLatitude, dHeight, dX, dY, dZ);
				Vector3d vCartesian = Vector3d(dX, dY, dZ);
				return vCartesian;
			}

			Vector3d MathEngine::CartesianToSpherical(Gamedouble dX, Gamedouble dY, Gamedouble dZ)
			{
				Vector3d vLonLat;
				_CartesianToSphericalD(dX, dY, dZ, vLonLat.X, vLonLat.Y, vLonLat.Z);
				return vLonLat;
			}

			Gamebool MathEngine::Triangulate(Gamefloat*& pPoint3Ds, Gameint nPointCount, Gameint nSubCount, Gameint* nPolyCounts, Gameint*& arrIntIndex, Gameint& nCount)
			{
				_Triangulate(pPoint3Ds, nPointCount, nSubCount, nPolyCounts, arrIntIndex, nCount);
				return true;
			}

			Gamevoid MathEngine::FreeUGInt(Gameint*& pIndex)
			{
				if (pIndex != nullptr)
				{
					_FreeUGInt(pIndex);
				}
			}

			Gamevoid MathEngine::FreeUGFloat(Gamefloat*& pData)
			{
				if (pData != nullptr)
				{
					_FreeUGFloat(pData);
				}
			}

			Gamevoid MathEngine::FreeUGDouble(Gamedouble*& pData)
			{
				if (pData != nullptr)
				{
					_FreeUGDouble(pData);
				}
			}

			Matrix4d MathEngine::CalRotation(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dAltitude)
			{
				Gamedouble* pRotMat = new Gamedouble[16];
				_RotationMatrix(dLongitude, dLatitude, dAltitude, pRotMat);
				Matrix4d matRot(pRotMat);
				delete[] pRotMat;
				return matRot;
			}

			Gamedouble MathEngine::HorizontalToVerticalFOV(Gamedouble dHFov, Gamedouble dAspect)
			{
				return (2 * FMath::Atan(FMath::Tan((dHFov *0.5)) / dAspect));
			}
			Gamedouble MathEngine::VerticalToHorizontalFOV(Gamedouble dVFov, Gamedouble dAspect)
			{
				return (2 * FMath::Atan(FMath::Tan((dVFov *0.5)) * dAspect));
			}

			Gamevoid MathEngine::UpdateRotationAndLocation(FVector &vLocation, FRotator &vRotator, Matrix4d mat4d)
			{
				FTransform currentTrans;
				currentTrans.SetLocation(vLocation);
				currentTrans.SetRotation(vRotator.Quaternion());

				Matrix4d mat(currentTrans.ToMatrixWithScale());
				mat = mat * mat4d;

				FMatrix matf;
				Matrix4d::ToFMatrix(mat, matf);
				currentTrans.SetFromMatrix(matf);

				vLocation = currentTrans.GetLocation();
				vRotator = currentTrans.GetRotation().Rotator();
			}

			Gamevoid MathEngine::UGCViewMatrixToUEViewMatrix(Matrix4d &ugcViewMatrix, Matrix4d &ueViewMatrix)
			{
				Vector3d vLocation;
				FRotator rRotator;

				UGCViewMatrixToUERotationAndLocation(ugcViewMatrix, vLocation, rRotator);

				// 获取视图矩阵
				FViewMatrices viewMatrices;
				viewMatrices.UpdateViewMatrix(vLocation.ToFVector(), rRotator);
				FMatrix matFViewMatrix = viewMatrices.GetViewMatrix();

				ueViewMatrix = Matrix4d(matFViewMatrix);
			}

			Gamevoid MathEngine::UGCViewMatrixToUERotationAndLocation(Matrix4d ugcViewMatrix, Vector3d &vLocation, FRotator &vRotator)
			{
				Gamedouble dPosX, dPosY, dPosZ;
				Gamedouble dUpX, dUpY, dUpZ;
				Gamedouble dRightX, dRightY, dRightZ;

				Gamedouble * pDoubleMat = new Gamedouble[16];
				Matrix4d::ToDoublePointer(ugcViewMatrix, pDoubleMat);

				_DecomposeViewMatrix2(pDoubleMat, dPosX, dPosY, dPosZ,
					dUpX, dUpY, dUpZ,
					dRightX, dRightY, dRightZ);

				vLocation = Vector3d(dPosY, dPosX, dPosZ);
				vLocation *= M_TO_CM;
				
				// 相机向上的轴(Z)
				FVector vUp(dUpY, dUpX, dUpZ);
				vUp.Normalize();

				// 相机的右轴（Y）
				FVector vRight(dRightY, dRightX, dRightZ);
				vRight.Normalize();

				FMatrix matRoationXY = FRotationMatrix::MakeFromYZ(vRight, vUp);
				vRotator = matRoationXY.Rotator();

				FVector vPot = vLocation.ToFVector();

				Matrix4d matLocation;
				matLocation.SetTrans(vLocation);
				matLocation = matLocation * Georeference::GetECEFtoGeoreference();
				vLocation = matLocation.GetTrans();
				
				MathEngine::UpdateRotationAndLocation(vPot, vRotator, Georeference::GetECEFtoGeoreference());
				vLocation -= FVector(ROCacheManager::m_vecWorldOrigin);
				if (ROCacheManager::m_eSceneType == SceneType::Globe ||
					ROCacheManager::m_eSceneType == SceneType::Ellipsoid_WGS84)
				{
					vLocation -= m_vWorldOffset;
				}
				
				delete[] pDoubleMat;
			}

			Gamevoid MathEngine::SetShaderMatrixParamter(UMaterialInstanceDynamic* pMID, Matrix4d mat, FString strName)
			{
				FLinearColor vX;
				vX.R = mat[0][0];
				vX.G = mat[0][1];
				vX.B = mat[0][2];
				vX.A = mat[0][3];

				FLinearColor vY;
				vY.R = mat[1][0];
				vY.G = mat[1][1];
				vY.B = mat[1][2];
				vY.A = mat[1][3];

				FLinearColor vZ;
				vZ.R = mat[2][0];
				vZ.G = mat[2][1];
				vZ.B = mat[2][2];
				vZ.A = mat[2][3];

				FLinearColor vW;
				vW.R = mat[3][0];
				vW.G = mat[3][1];
				vW.B = mat[3][2];
				vW.A = mat[3][3];

				FString strX = strName + TEXT("X");
				FString strY = strName + TEXT("Y");
				FString strZ = strName + TEXT("Z");
				FString strW = strName + TEXT("W");

				pMID->SetVectorParameterValue(FName(strX), vX);
				pMID->SetVectorParameterValue(FName(strY), vY);
				pMID->SetVectorParameterValue(FName(strZ), vZ);
				pMID->SetVectorParameterValue(FName(strW), vW);
			}

			SceneManagerType MathEngine::ConvertToSceneManagerType(int32 nType)
			{
				SceneManagerType eSceneManagerType = DRAW3D;
				switch (nType)
				{
				case 0:
					eSceneManagerType = DRAW3D;
					break;
				case 1:
					eSceneManagerType = REAL_TIME_RASTER;
					break;
				case 3:
					eSceneManagerType = REAL_TIME_ELEVATION;
					break;
				case 4:
					eSceneManagerType = REAL_TIME_ELEVATION_NORMAL;
					break;
				case 5:
					eSceneManagerType = REAL_TIME_ELEVATION_S3M;
					break;
				case 6:
					eSceneManagerType = REAL_TIME_ELEVATION_RULER;
					break;
				case 7:
					eSceneManagerType = DRAW_SELECTION;
					break;
				case 11:
					eSceneManagerType = REAL_TIME_RASTER_OCEAN;
					break;
				case 16:
					eSceneManagerType = DRAW_SPATIALQUERY;
					break;
				case 17:
					eSceneManagerType = DRAW_SPATIALQUERY_COLOR;
					break;
				default:
					break;
				}

				return eSceneManagerType;
			}

			Gamevoid MathEngine::CalHeadingAndPitch(Gamebool bIsSphere,
				Gamedouble dPosX, Gamedouble dPosY, Gamedouble dPosZ,
				Gamedouble dDirectionX, Gamedouble dDirectionY, Gamedouble dDirectionZ,
				Gamedouble &dHeading, Gamedouble &dPitch)
			{
				_CalHeadingAndPitch(bIsSphere, 
					dPosX, dPosY, dPosZ,
					dDirectionX, dDirectionY, dDirectionZ,
					dHeading, dPitch);
			}

			Matrix4d MathEngine::UGCMatrixPtrToUEMatrix4d(Gamedouble* pDoubleObjectMat)
			{
				Matrix4d doubleObjectMatrix(pDoubleObjectMat);
				doubleObjectMatrix = Matrix4d::XY_REVERSE * doubleObjectMatrix * Matrix4d::XY_REVERSE;

				Matrix4d::ToDoublePointer(doubleObjectMatrix, pDoubleObjectMat);

				doubleObjectMatrix[3][0] *= M_TO_CM;
				doubleObjectMatrix[3][1] *= M_TO_CM;
				doubleObjectMatrix[3][2] *= M_TO_CM;
				return doubleObjectMatrix;
			}

			Gamelong MathEngine::CalHashCodeByChar(FString strName)
			{
				const TCHAR* c = *strName;
				ANSICHAR* cc = TCHAR_TO_UTF8(c);
				return _CalHashCodeByChar(cc);
			}

			FVector MathEngine::SphericalToCartesian_GeoOrigin(FVector vPos)
			{
				Data::Vector3d vTargertCartesian3d = Data::Vector3d(vPos);
				SuperMapSDK::UnrealEngine::Core::_SphericalToCartesian(vPos.X, vPos.Y, vPos.Z,
					vTargertCartesian3d.X, vTargertCartesian3d.Y, vTargertCartesian3d.Z);
				Data::Vector3d vTargertCartesian = vTargertCartesian3d;
				vTargertCartesian = vTargertCartesian * M_TO_CM;

				vTargertCartesian.MultiplyMatrix(Georeference::GetECEFtoGeoreference());
				vTargertCartesian -= m_vWorldOffset;
				vTargertCartesian -= FVector(ROCacheManager::m_vecWorldOrigin);
				return vTargertCartesian.ToFVector();
			}

			Gamevoid MathEngine::FStringToANSIChar(FString Str, ANSICHAR* &pChar)
			{
				const TCHAR* cstrValue = *Str;
#if !PLATFORM_LINUX
				Gameint iLen = 3 * wcslen(cstrValue);
				Gamechar* chRtn = new Gamechar[iLen + 1];
				setlocale(LC_ALL, ".65001");
				wcstombs(chRtn, cstrValue, iLen + 1);
				pChar = chRtn;
				setlocale(LC_ALL, "");
#else
				ANSICHAR* ccstrValue = TCHAR_TO_UTF8(cstrValue);
				Gameint size_str = strlen(ccstrValue);
				pChar = new ANSICHAR[size_str + 1];
				FMemory::Memset(pChar, 0, size_str + 1);
				FMemory::Memmove(pChar, ccstrValue, size_str + 1);
#endif
			}

			Gamevoid MathEngine::Chamfer(TArray<Vector3d>& vCurveds, TArray<Vector3d>& vLines, Gameint nFactor, Gamebool bIsSym, Gameint nSlice)
			{
				Gameint nCount = 0;
				nCount = vLines.Num();
				Gamedouble* dLines = new Gamedouble[nCount * 3];
				for (Gameint i = 0; i < nCount; i++)
				{
					dLines[i * 3] = vLines[i].X;
					dLines[i * 3 + 1] = vLines[i].Y;
					dLines[i * 3 + 2] = vLines[i].Z;
				}
				Gamedouble* dCurveds = nullptr;
				_Chamfer(dCurveds, dLines, nCount, nFactor, bIsSym, nSlice);
				for (Gameint j = 0; j < nCount; j++)
				{
					Vector3d vCurved = Vector3d(dCurveds[j * 3], dCurveds[j * 3 + 1], dCurveds[j * 3 + 2]);
					vCurveds.Add(vCurved);
				}
				delete[] dLines;
				dLines = nullptr;
				if (nCount > 0 && dCurveds != nullptr)
				{
					_FreeUGDouble(dCurveds);
				}
			}

			Gamevoid MathEngine::GetSubdivisionPoints(TArray<FVector>& arrPoints, TArray<FVector>& arrLocations, Gamefloat fDistance)
			{
				for (Gameint i = 0; i < arrPoints.Num() - 1; i++)
				{
					Gamefloat realDistance = FVector::Distance(arrPoints[i + 1], arrPoints[i]);
					Gameint num = realDistance / fDistance;

					if (num == 0)
					{
						arrLocations.Add(arrPoints[i]);
						continue;
					}

					FVector unit = (arrPoints[i + 1] - arrPoints[i]) / num;

					for (Gameint j = 0; j < num; j++)
					{
						arrLocations.Add(arrPoints[i] + j * unit);
					}
				}
			}

			Gamevoid MathEngine::GetSubdivisionPoints2(TArray<Vector3d>& arrPoints, TArray<Vector3d>& arrLocations, Gamefloat fDistance)
			{
				for (Gameint i = 0; i < arrPoints.Num() - 1; i++)
				{
					Gamefloat realDistance = arrPoints[i].Distance(arrPoints[i + 1]);
					Gameint num = realDistance / fDistance;

					if (num == 0)
					{
						arrLocations.Add(arrPoints[i]);
						continue;
					}

					Vector3d unit = (arrPoints[i + 1] - arrPoints[i]) / num;

					for (Gameint j = 0; j < num; j++)
					{
						arrLocations.Add(arrPoints[i] + Vector3d(unit.X * j, unit.Y * j, unit.Z * j));
					}
				}
			}

			Gamebool MathEngine::RayIntersectionWithGlobe(Vector3d vStart, Vector3d vDirection, Vector3d& vIntersect, SceneType sceneType, Gamedouble dRadius)
			{
				vDirection = vDirection.Normalize();
				Gamedouble vIntersectX = 0.0;
				Gamedouble vIntersectY = 0.0;
				Gamedouble vIntersectZ = 0.0;
				switch (sceneType)
				{
					case SceneType::Globe:
					{
						_RayIntersectionWithSphereAndRadius(vStart.Y, vStart.X, vStart.Z, vDirection.Y, vDirection.X, vDirection.Z, vIntersectX, vIntersectY, vIntersectZ, dRadius);
						break;
					}	
					case SceneType::Ellipsoid_WGS84:
					{
						_RayIntersectionWithEllipsoidAndRadius(vStart.Y, vStart.X, vStart.Z, vDirection.Y, vDirection.X, vDirection.Z, vIntersectX, vIntersectY, vIntersectZ, dRadius);
						break;
					}
				}
				if (FMath::IsNearlyZero(vIntersectX) && FMath::IsNearlyZero(vIntersectY) && FMath::IsNearlyZero(vIntersectZ))
				{
					return false;
				}
				vIntersect = Vector3d(vIntersectY, vIntersectX, vIntersectZ);
				FVector v1 = vDirection.ToFVector();
				FVector	v2 = (vIntersect - vStart).ToFVector();
				v2.Normalize();
				Gamefloat dot = FVector::DotProduct(v1, v2);
				if (dot < 0)
				{
					vIntersect = Vector3d(0, 0, 0);
					return false;
				}
				return true;
			}
		
			Gamedouble MathEngine::GetEllipsoidRadius(Gamedouble dLongitude, Gamedouble dLatitude, Gamedouble dAltitude)
			{
				Vector3d location = SphericalToCartesian2(dLongitude, dLatitude, dAltitude);
				FVector vDirection = location.ToFVector();
				vDirection.Normalize();
				Gamedouble vIntersectX = 0.0;
				Gamedouble vIntersectY = 0.0;
				Gamedouble vIntersectZ = 0.0;
				_RayIntersectionWithEllipsoidAndRadius(location.Y, location.X, location.Z, vDirection.Y, vDirection.X, vDirection.Z, vIntersectX, vIntersectY, vIntersectZ, 0);
				Gamedouble r = FMath::Sqrt(vIntersectX * vIntersectX + vIntersectY * vIntersectY + vIntersectZ * vIntersectZ);
				return r;
			}
}
	}
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif