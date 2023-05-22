#include "WarehouseApp.h"


WarehouseApp::WarehouseApp()
{
	service = new WarehouseService();
}

int WarehouseApp::CreateWarehouse(WarehosueDto* dto)
{
	int id = service->createWarehouse(dto);
	return id;
}

