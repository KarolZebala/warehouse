#pragma once
#include "WarehouseService.h"
#include "WarehosueDto.h"
class WarehouseApp
{
public:
	 WarehouseApp();
	 std::string CreateWarehouse(WarehosueDto* dto);
	 std::vector<WarehosueDto> GetAll();
	 WarehosueDto GetById(std::string id);
	 

private:
	WarehouseService* service;


private:
	
};

