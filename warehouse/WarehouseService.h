#ifndef WAREHOUSESERVICE_H
#define WAREHOUSESERVICE_H

#include <string>
#include "Warehouse.h"
#include "WarehouseDbContext.h"
#include "WarehouseDto.h"
#include "WarehouseRepository.h"
class IWarehouseService {
public:
    virtual std::string CreateWarehouse(WarehouseDto* dto) { return std::string(); };
    //virtual void UpdateWarehouse(WarehouseDto* dto) { return ; };

    virtual std::vector<WarehouseDto> GetAllWarehouses() { return std::vector<WarehouseDto>(); };
    virtual WarehouseDto GetWarehosueById(std::string id) { return WarehouseDto(); };
};
class WarehouseService {
public:
    explicit WarehouseService();

    std::string CreateWarehouse(WarehouseDto* dto);
    void UpdateWarehouse(WarehouseDto* dto);

    std::vector<WarehouseDto> GetAllWarehouses();
    WarehouseDto GetWarehosueById(std::string id);

private:
    WarehouseDbContext* dbContext;
    WarehouseRepository* _warehouseRepository;
};

#endif // WAREHOUSESERVICE_H
