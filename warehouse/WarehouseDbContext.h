#ifndef WAREHOUSEDBCONTEXT_H
#define WAREHOUSEDBCONTEXT_H

#include <vector>
#include <memory>
#include "Warehouse.h"
#include "WarehosueDto.h"
#include <sqlite3.h>
class WarehouseDbContext {
public:
    void addWarehouse(Warehouse* warehouse);
    void saveChanges();
    std::vector<Warehouse*> GetAllWarehouses1();
    Warehouse* GetById(std::string id);

private:
    std::vector<Warehouse*> _warehouses;
};

#endif // WAREHOUSEDBCONTEXT_H
