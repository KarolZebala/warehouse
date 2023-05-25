#ifndef WAREHOUSESERVICE_H
#define WAREHOUSESERVICE_H

#include <string>
#include "Warehouse.h"
#include "WarehouseDbContext.h"
#include "WarehosueDto.h"

class WarehouseService {
public:
    explicit WarehouseService();

    int CreateWarehouse(WarehosueDto* dto);
    void UpdateWarehouse(WarehosueDto* dto);

    std::vector<WarehosueDto> GetAllWarehouses();
    WarehosueDto GetWarehosueById();

private:
    WarehouseDbContext* dbContext;
};

#endif // WAREHOUSESERVICE_H
