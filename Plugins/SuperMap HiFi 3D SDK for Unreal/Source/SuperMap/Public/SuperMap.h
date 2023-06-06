// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Modules/ModuleManager.h"

class FSuperMapModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	// »ñÈ¡DLL¾ä±ú
	void* GetDLLHandle();

	void* GetCloudLicenseDLLHandle();
	/**
	* Singleton-like access to this module's interface.  This is just for convenience!
	* Beware of calling this during the shutdown phase, though.  Your module might have been unloaded already.
	*
	* @return Returns singleton instance, loading the module on demand if needed
	*/
	static inline FSuperMapModule& Get()
	{
		return FModuleManager::LoadModuleChecked< FSuperMapModule >("SuperMap");
	}
private:
	/** Handle to the test dll we will load */
	void*	m_pSupermapDLLHandle;
	void*	m_pCloudLicenseDLLHandle;
};
