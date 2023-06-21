#pragma once
#include "WarehouseLocation.h"
#include "sqlite3.h"
#include <ctime>
#include "WarehouseLocationFilo.h"
#include <iomanip>
#include <sstream>
#include "WarehouseLocationFifo.h"
class IWarehouseLocationRepository {
public:
	virtual void addLocatation(std::shared_ptr<WarehouseLocation> location) {};
	virtual std::shared_ptr<WarehouseLocation> getById(std::string id) { return std::shared_ptr<WarehouseLocation>(); };
	virtual std::vector<std::shared_ptr<WarehouseLocation>> getAll() { return std::vector<std::shared_ptr<WarehouseLocation>>(); };
	virtual void createLocationProduct(std::shared_ptr<WarehouseLocationProduct> product) {};
};
class WarehouseLocationRepository : public IWarehouseLocationRepository
{
public:
	void addLocatation(std::shared_ptr<WarehouseLocation> location);
	std::shared_ptr<WarehouseLocation> getById(std::string id);
	std::vector<std::shared_ptr<WarehouseLocation>> getAll();
	
	void createLocationProduct(std::shared_ptr<WarehouseLocationProduct> product);
private:
	void addLocationProduct(std::shared_ptr<WarehouseLocationProduct> product, sqlite3* db);
	WarehouseLocationProduct* getLocationProductById(std::string id);
	std::vector<std::shared_ptr<WarehouseLocationProduct>> getAllLocationProdut(std::string locationId, sqlite3* db);
};

