#include "WarehouseService.h"

WarehouseService::WarehouseService(const std::shared_ptr<WarehouseDbContext>& dbContext)
    : dbContext(dbContext)
{
}

std::shared_ptr<Warehouse> WarehouseService::createWarehouse(const std::string& name)
{
    auto warehouse = std::make_shared<Warehouse>(name);
    dbContext->addWarehouse(warehouse);
    dbContext->saveChanges();
    return warehouse;
}