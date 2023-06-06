#pragma once

#include "CoreMinimal.h"
#include "Base3D/CommonDefine.h"
#include "Base3D/MaterialDefine.h"
#include "Graphics3D/GameStruct.h"
#include "Graphics3D/GameEnum.h"
#include "Graphics3D/GameTexture.h"

class UMaterialInterface;
class UMaterialInstanceDynamic;
class UMaterialInstanceConstant;
namespace SuperMapSDK
{
	struct FSuperMapMaterialMacro
	{
	public:
		//! \brief �Ƿ�Ϊ��ʱ��
		Gamebool m_bMultiTemporalWeight = false;
		//TO DO: ����������ṹ���������
	};

	class FSuperMapMaterialInterfaceCollection
	{
	public:
		FSuperMapMaterialInterfaceCollection();
		~FSuperMapMaterialInterfaceCollection();

		void SetMaterialByUseFlag(UseMaterialFlag useFlag, UMaterialInterface* pMaterialInterface);

		UMaterialInterface* GetMaterialByUseFlag(UseMaterialFlag useFlag) const;
		void SetMacros(GameMaterialParam* pMaterialParam);
		FSuperMapMaterialMacro& GetMacros() { return m_matMacros; }

	private:
		// ����𻮷ֵĲ��ʼ���
		TMap<UseMaterialFlag, UMaterialInterface*> m_mapMaterialByFlag;
		//! \brief Normal���ʵĺ�
		FSuperMapMaterialMacro m_matMacros;
	};


	class GameRenderTexture;
	class SUPERMAP_API GameMaterial
	{
	public:
		GameMaterial();
		GameMaterial(GameMaterialParam* pMaterialParam);
		~GameMaterial();

	public:

		//! \brief ��ȡ���ʲ���
		GameMaterialParam* GetMaterialParam();

		//! \brief ��ȡUE��̬����
		UMaterialInstanceDynamic* GetMID();

		//! \brief ����UE��̬����
		void SetMID(UMaterialInstanceDynamic* pMID);

		//! \brief ��ȡ��������
		UMaterialInstanceDynamic* GetViewportMID();

		//! \brief ��ȡѡ��ʹ�õĲ���
		UMaterialInstanceDynamic* GetSelectionMaterial();

		//! \brief ��ȡ��ѡʹ�õĲ���
		UMaterialInstanceDynamic* GetRectSelectMaterial();

		//! \brief ��ȡ����ԭʼ����
		FString GetMaterialOrginName();

		//! \brief ���²���
		void UpdateMaterial(GameMaterialParam* pMaterialParam);

		//! \brief ���¿�ѡ/�ռ��ѯ����
		void UpdateRectMaterial(GameMaterialParam* pMaterialParam);

		//! \brief ��ȡ��������
		DataType GetDataType();

		//! \brief ����shader����
		void SetMaterialIntParam(Gamechar* strParamName, Gameint nValue);
		void SetMaterialfloatParam(Gamechar* strParamName, Gamefloat nValue);
		void SetMaterialVector3dParam(Gamechar* strParamName, GameVec3d vValue3d);
		void SetMaterialVector4dParam(Gamechar* strParamName, GameVec4d vValue4d);
		void SetMaterialMatrix4dParam(Gamechar* strParamName, void* pValue);
		void SetMaterialTextureParam(Gamechar* strParamName, Gameint nTexIndex);

		//! \brief �������첽��õ�ʱ��������������
		void UpdateTextureParam();
		//! \brief �������첽��õ�ʱ������ò��ʲ���
		void UpdateShaderParam();
		//! \brief �����Ƿ��Ѿ��첽����
		Gameint GetNumUnsetTexture();

		//! \brief ��ʼ������
		void InitMaterial();

		//! \brief ��ȡ������Ⱦ��ʽ
		CullingMode GetCullingMode();
	private:

		//! \brief ��ʼ��MID
		void InitMID();

		//! \brief ��������
		void CreateMID(bool bIsPBR, FString strShaderName);

		//! \brief ����ѡ�����
		//! \brief pColorMaterial ����������ɫ��Ⱦ�Ĳ���
		void CreateSelectionMaterial(UMaterialInterface* pColorMaterial);

		//! \brief ������ѡ����
		void CreateRectSelectMaterial(UMaterialInterface* pRectSelectMaterial);

		//! \brief ���²��ʲ���
		void UpdateMaterialParam();

		//! \brief ���÷�������ʹ�õĲ��ʲ���
		void UpdateAnalyst(UMaterialInstanceDynamic* pMD);

		//! \brief �����������
		void UpdateViewportMID(UMaterialInstanceDynamic* pMID);

		//! \brief ����PBR�������
		void SetPBRTextureParam(GamePBRParam* pPBRParam, FName & strTexture, int32 nTexCount);
		void SetPBRMaterialParam(UMaterialInstanceDynamic* pMID);

		//! \brief �ж��Ƿ���Ҫ����ѡ�����
		bool IsNeedCreateSelectionMaterial(FString strShaderName);
		
		//! \brief �ж��Ƿ���Ҫ������ѡ����
		Gamebool IsNeedCreateRectSelectMaterial(FString strShaderName);

		//! \brief �����Ϊû�����Կ���û��û�������ʵĲ���
		void AddMaterialIntParam(FName name, Gameint value);
		void AddMaterialFloatParam(FName name, Gamefloat value);
		void AddMaterialMatrix4dParam(FName name, void* value);
		void AddMaterialTextureParam(FName name, GameTexture* pTexture);
		void AddMaterialRenderTextureParam(FName name, GameRenderTexture* pTexture);
		void AddMaterialVec4dParam(FName name, GameVec4d vec);
	private:

		//! \brief ���ʲ���
		GameMaterialParam* m_pMaterialParam;

		//! \brief ��̬����
		UMaterialInstanceDynamic* m_pMID;

		//! \brief �������ݲ���
		UMaterialInstanceDynamic* m_pViewportMID;

		//! \brief �������ʶ�Ӧ������ѡ��Ĳ���
		UMaterialInstanceDynamic* m_pSelectionMaterial;

		//! \brief �������ʶ�Ӧ��������ѡ�Ĳ���
		UMaterialInstanceDynamic* m_pRectSelectMaterial;

		//! \brief ����ʵ��
		UMaterialInstanceConstant* m_pMIC;

		//! \brief ���ʶ�Ӧ����������
		DataType m_enDataType;

		//! \brief δ��int����
		TMap<FName, Gameint> m_mapSetMaterialInt;

		//! \brief δ��float����
		TMap<FName, Gamefloat> m_mapSetMaterialFloat;

		//! \brief δ��mat����
		TMap<FName, void*> m_mapSetMaterialMatrix4d;

		//! \brief δ����������
		TMap<FName, GameTexture*> m_mapSetMaterialTextures;


		//! \brief δ����������
		TMap<FName, GameRenderTexture*> m_mapSetMaterialRenderTextures;

		//! \brief δ��FLinearColor����
		TMap<FName, GameVec4d> m_mapSetMaterialVec4d;


		//! \brief δ�������Ԫ����
		TMap<FName, Gameint> m_mapSetTextureIndex;

		//! \brief ��������Ⱦ��ʽ
		CullingMode m_eCullingMode;

		//! \brief �Ƿ��Ѿ���ʼ��
		Gamebool m_bInitial;
	};
}