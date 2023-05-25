#pragma once
#include "WarehouseService.h"
#include "WarehosueDto.h"
class WarehouseApp
{
public:
	 WarehouseApp();
	 int CreateWarehouse(WarehosueDto* dto);
	 std::vector<WarehosueDto> GetAll();
	 

private:
	WarehouseService* service;


private:
	
};

