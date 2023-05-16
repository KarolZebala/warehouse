#ifndef WAREHOUSEDBCONTEXT_H
#define WAREHOUSEDBCONTEXT_H

#include <vector>
#include <memory>
#include "Warehouse.h"

class WarehouseDbContext {
public:
    void addWarehouse(const std::shared_ptr<Warehouse>& warehouse);
    void saveChanges();

private:
    std::vector<std::shared_ptr<Warehouse>> warehouses;
};

#endif // WAREHOUSEDBCONTEXT_H
