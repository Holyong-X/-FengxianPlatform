#include "SpatialAnalyst3D/Facade.h"
#include "GameFramework/PlayerController.h"
#include "GameFramework/Pawn.h"
#include "Runtime/Core/Public/Misc/MessageDialog.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif

namespace SuperMapSDK
{
	namespace UnrealEngine
	{
		namespace SpatialAnalyst3D
		{
			Facade::Facade(UWorld* pWorld, Core::Scene* pScene, ControlUE::CameraControl* pCameraControl) : Analyst3D(pWorld, pScene, pCameraControl)
			{
				m_eAnalyzeMode = Core::Facade_Analyze;
				m_pGeoLine3D = nullptr;
				m_bOutput = false;
				m_dResolution = 0.5;//m/p
				m_dMinHeight  = 0;  //m
				m_dMaxHeight  = 100;//m
				m_dFarDist    = 500;//m
			}

			Facade::~Facade()
			{
				
			}

			void Facade::SetOutputPath(FString strOutputPath)
			{
				m_strOutputPath = strOutputPath;
			}

			FString Facade::GetOutputPath()
			{
				return m_strOutputPath;
			}

			void Facade::SetViewLine(GeoLine3D* pGeoLine3D)
			{
				if (m_pGeoLine3D != nullptr)
				{
					delete m_pGeoLine3D;
					m_pGeoLine3D = nullptr;
				}

				m_pGeoLine3D = pGeoLine3D;
			}

			void Facade::SetResolution(Gamedouble dResolution)
			{
				m_dResolution = dResolution;
			}

			Gamedouble Facade::GetResolution()
			{
				return m_dResolution;
			}

			void Facade::GetVisibleHeight(Gamedouble &dMin, Gamedouble &dMax)
			{
				dMin = m_dMinHeight;
				dMax = m_dMaxHeight;
			}

			void Facade::SetVisibleHeight(Gamedouble dMin, Gamedouble dMax)
			{
				m_dMinHeight = dMin;
				m_dMaxHeight = dMax;
			}

			void Facade::SetVisibleFarDistance(Gamedouble dFar)
			{
				m_dFarDist = dFar;
			}

			Gamedouble Facade::GetVisibleFarDistance()
			{
				return m_dFarDist;
			}

			void Facade::DoBuild()
			{
				m_bOutput = true;
			}

			void Facade::DoClear()
			{
				m_bOutput = false;
			}

			void Facade::Render()
			{
				if (m_bOutput)
				{
					// 主相机位置
					FVector  vOldLocation;
					FRotator vOldRotator;
					m_pWorld->GetFirstPlayerController()->GetPlayerViewPoint(vOldLocation, vOldRotator);

					ANSICHAR* strOutputPath = TCHAR_TO_UTF8(*m_strOutputPath);
					_OutputStreetFacade(strOutputPath , m_pGeoLine3D->GetHandler(), m_dResolution, m_dFarDist, m_dMinHeight, m_dMaxHeight);
				
					// 保存主相机
					m_pWorld->GetFirstPlayerController()->GetPawn()->SetActorLocation(vOldLocation);
					m_pWorld->GetFirstPlayerController()->SetControlRotation(vOldRotator);

					FText message = FText::FromString(TEXT("保存成功"));
					FMessageDialog::Open(EAppMsgType::Ok, message);
				}

				m_bOutput = false;
			}
		}
	}
}

#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif