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

    std::vector<std::shared_ptr<WarehouseDto>> GetAllWarehouses();
    std::shared_ptr<WarehouseDto> GetWarehosueById(std::string id);

private:
    std::shared_ptr<WarehouseRepository> _warehouseRepository;

    std::shared_ptr<WarehouseDto> MapWarehouse(std::shared_ptr<Warehouse> warehouse);

};

#endif // WAREHOUSESERVICE_H
