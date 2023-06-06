#pragma once
#include "CoreMinimal.h"
#include "Tickable.h"
#include "Containers/Array.h"
#include "UObject/WeakObjectPtrTemplates.h"
#include "Graphics3D/GameStruct.h"

class UTexture;
class UObject;

namespace SuperMapSDK
{   
	class GameTexture;
	class SUPERMAP_API SMDestructor : FTickableGameObject {
	public:
		Gamevoid Tick(Gamefloat DeltaTime) override;
		ETickableTickType GetTickableTickType() const override;
		Gamebool IsTickableWhenPaused() const override;
		Gamebool IsTickableInEditor() const override;
		TStatId GetStatId() const;
		Gamevoid Destroy(UObject* pObject);
		Gamevoid Destroy(GameFuture* pGameFuture);
		Gamevoid DestroyGameFutures();
	private:
		Gamebool TickDestruction(UObject* pObject) const;
		Gamevoid AddToPending(UObject* pObject);
		Gamevoid ProcessPending();
		Gamevoid FinalizeDestroy(UObject* pObject) const;

		TArray<TWeakObjectPtr<UObject>> m_arrPending;
		TArray<TWeakObjectPtr<UObject>> m_arrNextPending;

		TArray<GameFuture*> m_FutureDeleteResult;
	};

	class SUPERMAP_API GameLifetime {
	public:
		static Gamevoid Destory(UObject* pObject);
		static Gamevoid Destory(GameFuture* pGameFuture);
	private:
		static SMDestructor smDestructor;
	};
}
