#include "WarehouseDbContext.h"

void WarehouseDbContext::addWarehouse(Warehouse* warehouse)
{
    _warehouses.push_back(warehouse);
}

void WarehouseDbContext::saveChanges()
{
    // Implementacja zapisu zmian do bazy danych
}

std::vector<Warehouse*> WarehouseDbContext::GetAllWarehouses1()
{
    return _warehouses;
}
