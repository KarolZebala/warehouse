#pragma once
#include "WarehouseLocation.h"
#include "sqlite3.h"
#include <ctime>
#include "WarehouseLocationFilo.h"
#include <iomanip>
#include <sstream>
#include "WarehouseLocationFifo.h"
class WarehouseLocationRepository
{
public:
	void addLocatation(WarehouseLocation* location);
	WarehouseLocationFifo* getFifoById(std::string id);
	WarehouseLocationFilo* getFiloById(std::string id);
	std::vector<WarehouseLocation*> getAll();
private:
	void addLocationProduct(WarehouseLocationProduct* product, sqlite3* db);
	WarehouseLocationProduct* getLocationProductById(std::string id);
	std::vector<WarehouseLocationProduct*> getAllLocationProdut(std::string locationId, sqlite3* db);
};

