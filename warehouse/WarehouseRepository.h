#pragma once
#include "Warehouse.h"
#include "WarehouseDto.h"
#include <sqlite3.h>
class IWarehouseRepository {
public:
	virtual void addWarehouse(std::shared_ptr<Warehouse> warehouse) {};
	virtual std::vector<std::shared_ptr<Warehouse>> GetAll() { return std::vector<std::shared_ptr<Warehouse>>(); };
	virtual std::shared_ptr<Warehouse> GetById(std::string id) {
		return std::shared_ptr<Warehouse>();
	};
};
class WarehouseRepository : public IWarehouseRepository
{
public:
	void addWarehouse(std::shared_ptr<Warehouse> warehouse);
	std::vector<std::shared_ptr<Warehouse>> GetAll();
	std::shared_ptr<Warehouse> GetById(std::string id);
};

