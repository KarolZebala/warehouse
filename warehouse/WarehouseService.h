#ifndef WAREHOUSESERVICE_H
#define WAREHOUSESERVICE_H

#include <string>
#include "Warehouse.h"
#include "WarehouseDbContext.h"
#include "WarehouseDto.h"
#include "WarehouseRepository.h"
class IWarehouseService {
public:
    virtual std::string CreateWarehouse(std::shared_ptr<WarehouseDto> dto) { return std::string(); };

    virtual std::vector<std::shared_ptr<WarehouseDto>>  GetAllWarehouses() { return std::vector<std::shared_ptr<WarehouseDto>>(); };
    virtual std::shared_ptr<WarehouseDto> GetWarehosueById(std::string id) { return std::shared_ptr<WarehouseDto>(); };
};
class WarehouseService : public IWarehouseService
{
public:
    explicit WarehouseService();

    std::string CreateWarehouse(std::shared_ptr<WarehouseDto> dto);

    std::vector<std::shared_ptr<WarehouseDto>> GetAllWarehouses();
    std::shared_ptr<WarehouseDto> GetWarehosueById(std::string id);

private:
    std::shared_ptr<WarehouseRepository> _warehouseRepository;

    std::shared_ptr<WarehouseDto> MapWarehouse(std::shared_ptr<Warehouse> warehouse);

};

#endif // WAREHOUSESERVICE_H
