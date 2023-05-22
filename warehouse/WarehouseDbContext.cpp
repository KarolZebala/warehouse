#include "WarehouseDbContext.h"

void WarehouseDbContext::addWarehouse(Warehouse* warehouse)
{
    warehouses.push_back(warehouse);
}

void WarehouseDbContext::saveChanges()
{
    // Implementacja zapisu zmian do bazy danych
}