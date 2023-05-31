#include "WarehouseService.h"

WarehouseService::WarehouseService()
{
    dbContext = new WarehouseDbContext();
}

std::string WarehouseService::CreateWarehouse(WarehosueDto* dto)
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

    dbContext->addWarehouse(warehouse);
    dbContext->saveChanges();
    return warehouse->getId();
}

std::vector<WarehosueDto> WarehouseService::GetAllWarehouses()
{
    auto warehouses = dbContext->GetAllWarehouses1();
    std::vector<WarehosueDto> res;
    for (auto warehouse : warehouses) {
        WarehosueDto warehouseDto;
        warehouseDto.Name = warehouse->getName();
        warehouseDto.WarehouseId = warehouse->getId();
        res.push_back(warehouseDto);
    }
    return res;
}

WarehosueDto WarehouseService::GetWarehosueById(std::string id)
{
    auto wareshouse = dbContext->GetById(id);
    return WarehosueDto();
}
