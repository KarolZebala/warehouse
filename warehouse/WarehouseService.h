#ifndef WAREHOUSESERVICE_H
#define WAREHOUSESERVICE_H

#include <string>
#include <memory>
#include "Warehouse.h"
#include "WarehouseDbContext.h"

class WarehouseService {
public:
    explicit WarehouseService(const std::shared_ptr<WarehouseDbContext>& dbContext);

    std::shared_ptr<Warehouse> createWarehouse(const std::string& name);

private:
    std::shared_ptr<WarehouseDbContext> dbContext;
};

#endif // WAREHOUSESERVICE_H
