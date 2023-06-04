#pragma once
#include "WarehouseService.h"
#include "WarehouseDto.h"
class WarehouseApp
{
public:
	 WarehouseApp();
	 std::string CreateWarehouse(WarehouseDto* dto);
	 std::vector<WarehouseDto> GetAll();
	 WarehouseDto GetById(std::string id);
	 

private:
	WarehouseService* service;


private:
	
};

