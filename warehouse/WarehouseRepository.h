#pragma once
#include "Warehouse.h"
#include "WarehouseDto.h"
#include <sqlite3.h>
class WarehouseRepository
{
public:
	void addWarehouse(Warehouse* warehouse);
	std::vector<Warehouse> GetAll();
	std::vector<WarehouseDto> GetAllDto();
	std::shared_ptr<Warehouse> GetById(std::string id);
	WarehouseDto GetByIddDto(std::string id);
};

