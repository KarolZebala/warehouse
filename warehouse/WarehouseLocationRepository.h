#pragma once
#include "WarehouseLocation.h"
#include "sqlite3.h"
#include <ctime>
#include "WarehouseLocationFilo.h"
#include <iomanip>
#include <sstream>
#include "WarehouseLocationFifo.h"
/**!
 * \brief Klasa IWarehouseLocationRepository jest klas� abstrakcyjn�, kt�ra odpowiada za zapis i odczyt lokalizacji
 */
class IWarehouseLocationRepository {
public:
	virtual void addLocatation(std::shared_ptr<WarehouseLocation> location) = 0;
	virtual std::shared_ptr<WarehouseLocation> getById(std::string id, std::string warehouseId) = 0;
	virtual std::vector<std::shared_ptr<WarehouseLocation>> getAll(std::string warehouseId) = 0;
	virtual void createLocationProduct(std::shared_ptr<WarehouseLocationProduct> product) = 0;
	virtual void removeLocationProduct(std::string productId, std::string locationId) = 0;
};

/**!
 * \brief Klasa WarehouseLocationRepository odpowiada za zapis i odczyt lokalizacji z bazy danych
 */
class WarehouseLocationRepository : public IWarehouseLocationRepository
{
public:
	/**
	* Funkcja dodaje lokalizacje do bazy
	* \param location lokalizacja do dodania
	*/
	void addLocatation(std::shared_ptr<WarehouseLocation> location);
	/**
	* Funkcja pobiera lokalizacje z bazy po id
	* \param id id lokalizaji
	* \param warehouseId id magazynu
	*/
	std::shared_ptr<WarehouseLocation> getById(std::string id, std::string warehouseId);
	/**
	* Funkcja pobiera wszystkie lokalizacje z bazy
	* \param warehouseId id magazynu
	*/
	std::vector<std::shared_ptr<WarehouseLocation>> getAll(std::string warehouseId);
	/**
	* Funkcja dodaje produkt do danej lokalizacji
	* \param product produkt do dodania
	*/
	void createLocationProduct(std::shared_ptr<WarehouseLocationProduct> product);
	/**
	* Funkcja usuwa produkt z danej lokalizacji do bazy
	* \param productId id produktu
	* \param locationId id lokalizacji
	*/
	void removeLocationProduct(std::string productId, std::string locationId);
private:
	void addLocationProduct(std::shared_ptr<WarehouseLocationProduct> product, sqlite3* db);
	/**
	* Funkcja pobiera produkty danej lokalizacji z bazy
	* \param locationId id lokalizacji
	*/
	std::vector<std::shared_ptr<WarehouseLocationProduct>> getAllLocationProdut(std::string locationId, sqlite3* db);
};

