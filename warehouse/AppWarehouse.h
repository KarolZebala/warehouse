#pragma once
#include <iostream>
#include "UIManager.h"
#include "SeedingService.h"
#include "UIProductManager.h"
#include "UIDocumentManager.h"
#include "UILocationManager.h"

class AppWarehouse 
{
public:
	AppWarehouse() {
		_seedingService = std::make_shared<SeedingService>(SeedingService());
	}
	void Start();

private:
	std::shared_ptr<ISeedingService> _seedingService;
	void SetUpDateBase();
	void ManageProduct();
	void ManageDocument();
	void ManageLocation();
};
