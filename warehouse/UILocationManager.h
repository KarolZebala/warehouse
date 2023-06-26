#pragma once
#include "UIManager.h"
class UILocationManager :public IUIManager
{
public:
	UILocationManager() {
		_locationRepository = std::make_shared<WarehouseLocationRepository>(WarehouseLocationRepository());

	}
	void ShowAll();
	void ShowById();

	void AddNew();

private:
	std::shared_ptr<IWarehouseLocationRepository> _locationRepository;
	void PrintLocation(std::shared_ptr<WarehouseLocation> location);
	void PrintLocationRowTitle();
};
