#ifndef WAREHOUSEDBCONTEXT_H
#define WAREHOUSEDBCONTEXT_H

#include <vector>
#include <memory>
#include "Warehouse.h"

class WarehouseDbContext {
public:
    void addWarehouse(Warehouse* warehouse);
    void saveChanges();

private:
    std::vector<Warehouse*> warehouses;
};

#endif // WAREHOUSEDBCONTEXT_H
