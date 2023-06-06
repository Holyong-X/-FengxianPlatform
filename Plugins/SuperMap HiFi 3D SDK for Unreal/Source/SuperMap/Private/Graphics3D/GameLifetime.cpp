#include "Graphics3D/GameLifetime.h"
#include "Graphics3D/GameTexture.h"
#include "UObject/Object.h"
#include <algorithm>
#include "Engine/StaticMesh.h"
#include "Engine/Texture2D.h"
#include "PhysicsEngine/BodySetup.h"
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_DISABLE_OPTIMIZATION
#endif
namespace SuperMapSDK
{
    /*static*/
    SMDestructor GameLifetime::smDestructor = SMDestructor();

    /*static*/ Gamevoid GameLifetime::Destory(UObject* pObject) {
        smDestructor.Destroy(pObject);
    }

    Gamevoid GameLifetime::Destory(GameFuture* pGameFuture)
    {
        smDestructor.Destroy(pGameFuture);
    }

    Gamevoid SMDestructor::Tick(Gamefloat DeltaTime) { ProcessPending(); }

    ETickableTickType SMDestructor::GetTickableTickType() const {
        return ETickableTickType::Always;
    }

    Gamebool SMDestructor::IsTickableWhenPaused() const { return true; }

    Gamebool SMDestructor::IsTickableInEditor() const { return true; }

    TStatId SMDestructor::GetStatId() const { return TStatId(); }

    Gamevoid SMDestructor::Destroy(UObject* pObject) {
        if (!TickDestruction(pObject)) {
            AddToPending(pObject);
        }
    }

    Gamevoid SMDestructor::Destroy(GameFuture* pGameFuture)
    {
        m_FutureDeleteResult.Add(pGameFuture);
    }

    Gamebool SMDestructor::TickDestruction(UObject* pObject) const 
    {
        if (!pObject)
        {
            return true;
        }

#if SM_FOR_UE_FIVE
        pObject->MarkAsGarbage();
#else
        
        if (!pObject->IsPendingKill()) {
            pObject->MarkPendingKill();
        }
#endif

        if (pObject->HasAnyFlags(RF_FinishDestroyed)) {
            return true;
        }

        if (!pObject->HasAnyFlags(RF_BeginDestroyed)) {
            pObject->ConditionalBeginDestroy();
        }

        if (!pObject->HasAnyFlags(RF_FinishDestroyed) &&
            pObject->IsReadyForFinishDestroy()) {
            FinalizeDestroy(pObject);
            return true;
        }

        return false;
    }

    Gamevoid SMDestructor::DestroyGameFutures()
    {
        TArray<GameFuture*> result;

        Gameint nCount = m_FutureDeleteResult.Num();
        for (Gameint n = 0 ; n < nCount; n++)
        {
            GameFuture* pGameFuture = m_FutureDeleteResult[n];
            if (pGameFuture->m_DeleteTexture.IsReady())
            {
                UTexture* pTexture = pGameFuture->m_DeleteTexture.Get();
                if (pTexture)
                {
                    pTexture->RemoveFromRoot();
                    Destroy(pTexture);
                }

                delete pGameFuture;
            }
            else
            {
                result.Add(pGameFuture);
            }
        }

        std::swap(m_FutureDeleteResult, result);
        result.Empty();
    }

    Gamevoid SMDestructor::AddToPending(UObject* pGameTexture) {
        m_arrPending.Add(pGameTexture);
    }

    Gamevoid SMDestructor::ProcessPending() {
        std::swap(m_arrNextPending, m_arrPending);
        m_arrPending.Empty();

        Gameint nCount = m_arrNextPending.Num();
        for (Gameint i = 0; i < nCount; i++) {
            Destroy(m_arrNextPending[i].Get(true));
        }

        DestroyGameFutures();
    }

    Gamevoid SMDestructor::FinalizeDestroy(UObject* pObject) const {
        UTexture2D* pTexture2D = Cast<UTexture2D>(pObject);
        if (pTexture2D) {
            delete pTexture2D->PlatformData;
            pTexture2D->PlatformData = nullptr;
        }

        UStaticMesh* pMesh = Cast<UStaticMesh>(pObject);
        if (pMesh) {
            pMesh->SetRenderData(nullptr);
        }

        UBodySetup* pBodySetup = Cast<UBodySetup>(pObject);
        if (pBodySetup) {
            pBodySetup->UVInfo.IndexBuffer.Empty();
            pBodySetup->UVInfo.VertPositions.Empty();
            pBodySetup->UVInfo.VertUVs.Empty();
            pBodySetup->FaceRemap.Empty();
            pBodySetup->ClearPhysicsMeshes();
        }
    }

}
#ifdef SUPERMAP_DEVELOPER_DEBUG
PRAGMA_ENABLE_OPTIMIZATION
#endif