#include "WarehouseApp.h"


WarehouseApp::WarehouseApp()
{
	service = new WarehouseService();
}

int WarehouseApp::CreateWarehouse(WarehosueDto* dto)
{
	int id = service->CreateWarehouse(dto);
	return id;
}

std::vector<WarehosueDto> WarehouseApp::GetAll()
{
	return service->GetAllWarehouses();
}

