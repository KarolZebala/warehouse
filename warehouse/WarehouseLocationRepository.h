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
	virtual void addLocatation(WarehouseLocation* location) { return; };
	/*virtual WarehouseLocationFifo* getFifoById(std::string id) { return new WarehouseLocationFifo(); };
	virtual WarehouseLocationFilo* getFiloById(std::string id) { return new WarehouseLocationFifo(); };*/
	virtual std::vector<WarehouseLocation*> getAll() { return std::vector<WarehouseLocation*>(); };
};
class WarehouseLocationRepository
{
public:
	void addLocatation(std::shared_ptr<WarehouseLocation> location);
	std::shared_ptr<WarehouseLocation> getById(std::string id);
	/*std::shared_ptr<WarehouseLocationFilo> getFiloById(std::string id);*/
	std::vector<std::shared_ptr<WarehouseLocation>> getAll();
private:
	void addLocationProduct(std::shared_ptr<WarehouseLocationProduct> product, sqlite3* db);
	WarehouseLocationProduct* getLocationProductById(std::string id);
	std::vector<std::shared_ptr<WarehouseLocationProduct>> getAllLocationProdut(std::string locationId, sqlite3* db);
};

