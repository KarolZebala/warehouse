#pragma once
#include "WarehouseService.h"
#include "WarehosueDto.h"
class WarehouseApp
{
public:
	 WarehouseApp();
	 int CreateWarehouse(WarehosueDto* dto);
	 

private:
	WarehouseService* service;


private:
	
};

