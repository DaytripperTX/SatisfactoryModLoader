#pragma once

#include "Modules/ModuleManager.h"

class FConfigLoaderModule : public FDefaultGameModuleImpl {
public:
	virtual void StartupModule() override;

	virtual bool IsGameModule() const override { return true; }
};