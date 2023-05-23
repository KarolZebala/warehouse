#pragma once
#include "WarehouseLocation.h"
#include<string>
class StorageArea
{
public:
	void AddWarehouseLocation();
	void UpdateWarehouseLocation();
private:
	std::string StorageAreaName;
	std::vector<WarehouseLocation> _locations;
};

