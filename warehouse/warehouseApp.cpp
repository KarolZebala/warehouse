#include "WarehouseApp.h"


WarehouseApp::WarehouseApp()
{
	service = new WarehouseService();
}

std::string WarehouseApp::CreateWarehouse(WarehosueDto* dto)
{
	std::string id = service->CreateWarehouse(dto);
	return id;
}

std::vector<WarehosueDto> WarehouseApp::GetAll()
{
	return service->GetAllWarehouses();
}

WarehosueDto WarehouseApp::GetById(std::string id)
{
	auto res = service->GetWarehosueById(id);
	return WarehosueDto();
}

