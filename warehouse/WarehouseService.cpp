#include "WarehouseService.h"

WarehouseService::WarehouseService()
{
    _warehouseRepository = std::make_shared<WarehouseRepository>(WarehouseRepository());
}

std::string WarehouseService::CreateWarehouse(WarehouseDto* dto)
{
    auto warehouse = Warehouse(dto->Name);
    auto warehousePtr = std::make_shared<Warehouse>(warehouse);
    for (auto& location : dto->WarehosueLocations)
    {
        warehousePtr->AddWarehouseLocations(
            location.WarehouseLocationName,
            location.Width,
            location.Depth,
            location.Height
        );
    }
    _warehouseRepository->addWarehouse(warehousePtr);
    
    return warehousePtr->getId();
}

std::vector<std::shared_ptr<WarehouseDto>> WarehouseService::GetAllWarehouses()
{
    auto warehouses = _warehouseRepository->GetAll();
    auto res = std::vector<std::shared_ptr<WarehouseDto>>();
    for (auto warehouse : warehouses) {
        auto warehouseDto = MapWarehouse(warehouse);
        res.push_back(warehouseDto);
    }
    return res;
}

std::shared_ptr<WarehouseDto> WarehouseService::GetWarehosueById(std::string id)
{
    auto wareshouse = _warehouseRepository->GetById(id);
    auto warehouseDto = MapWarehouse(wareshouse);
    return warehouseDto;
}

std::shared_ptr<WarehouseDto> WarehouseService::MapWarehouse(std::shared_ptr<Warehouse> warehouse) {
    auto warehouseDto = WarehouseDto();
    warehouseDto.IdGuid = warehouse->getId();
    warehouseDto.Name = warehouse->getName();

    auto res = std::make_shared<WarehouseDto>(warehouseDto);
    return res;
}
