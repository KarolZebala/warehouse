#include "WarehouseService.h"

WarehouseService::WarehouseService()
{
    dbContext = new WarehouseDbContext();
}

int WarehouseService::createWarehouse(WarehosueDto* dto)
{
    auto warehouse = new Warehouse(dto->Name);
    dbContext->addWarehouse(warehouse);
    dbContext->saveChanges();
    return warehouse->getId();
}