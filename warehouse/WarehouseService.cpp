#include "WarehouseService.h"

WarehouseService::WarehouseService()
{
    dbContext = new WarehouseDbContext();
}

int WarehouseService::CreateWarehouse(WarehosueDto* dto)
{
    auto warehouse = new Warehouse(dto->Name);
    for (auto location : dto->WarehosueLocations)
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
        res.push_back(warehouseDto);
    }
    return res;
}
