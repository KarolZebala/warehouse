#include "WarehouseApp.h"


WarehouseApp::WarehouseApp()
{
	service = new WarehouseService();
}

std::string WarehouseApp::CreateWarehouse(WarehouseDto* dto)
{
	std::string id = service->CreateWarehouse(dto);
	return id;
}



WarehouseDto WarehouseApp::GetById(std::string id)
{
	auto res = service->GetWarehosueById(id);
	return WarehouseDto();
}

