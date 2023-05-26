#ifndef WAREHOUSEDBCONTEXT_H
#define WAREHOUSEDBCONTEXT_H

#include <vector>
#include <memory>
#include "Warehouse.h"

class WarehouseDbContext {
public:
    void addWarehouse(Warehouse* warehouse);
    void saveChanges();
    std::vector<Warehouse*> GetAllWarehouses1();
    Warehouse* GetById(int id);

private:
    std::vector<Warehouse*> _warehouses;
};

#endif // WAREHOUSEDBCONTEXT_H
