#ifndef WAREHOUSESERVICE_H
#define WAREHOUSESERVICE_H

#include <string>
#include <memory>
#include "Warehouse.h"
#include "WarehouseDbContext.h"
#include "WarehosueDto.h"

class WarehouseService {
public:
    explicit WarehouseService();

    int createWarehouse(WarehosueDto* dto);

private:
    WarehouseDbContext* dbContext;
};

#endif // WAREHOUSESERVICE_H
