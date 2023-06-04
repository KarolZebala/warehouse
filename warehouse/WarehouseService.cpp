#include "WarehouseService.h"

WarehouseService::WarehouseService()
{
    dbContext = new WarehouseDbContext();
    _warehouseRepository = new WarehouseRepository();
}

std::string WarehouseService::CreateWarehouse(WarehouseDto* dto)
{
    auto warehouse = new Warehouse(dto->Name);
    for (auto& location : dto->WarehosueLocations)
    {
        warehouse->AddWarehouseLocations(
            location.WarehouseLocationName,
            location.Width,
            location.Depth,
            location.Height
        );
    }

    /*dbContext->addWarehouse(warehouse);
    dbContext->saveChanges();*/
    
    return warehouse->getId();
}

std::vector<WarehouseDto> WarehouseService::GetAllWarehouses()
{
    auto warehouses = dbContext->GetAllWarehouses1();
    std::vector<WarehouseDto> res;
    for (auto warehouse : warehouses) {
        WarehouseDto warehouseDto;
        warehouseDto.Name = warehouse->getName();
        warehouseDto.IdGuid = warehouse->getId();
        res.push_back(warehouseDto);
    }
    return res;
}

WarehouseDto WarehouseService::GetWarehosueById(std::string id)
{
    auto wareshouse = dbContext->GetById(id);
    return WarehouseDto();
}
