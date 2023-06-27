#pragma once
#include "Warehouse.h"
#include "WarehouseDto.h"
#include <sqlite3.h>
/**!
 * \brief Klasa IWarehouseRepository jest klas¹ abstrakcyjn¹, która odpowiada za zapis i odczyt magazynu
 */
class IWarehouseRepository {
public:
	/**
	* Funkcja wirtualna dodaj¹ca magazyn do bazy
	*
	* \param warehouse magazyn do dodania
	*/
	virtual void addWarehouse(std::shared_ptr<Warehouse> warehouse) = 0;
	/**
	* Funkcja wirtualna pobieraj¹ca magazyny z bazy
	*
	*/
	virtual std::vector<std::shared_ptr<Warehouse>> GetAll() = 0;
	/**
	* Funkcja wirtualna pobieraj¹ca magazyny z bazy po id
	*
	* \param id  id magazynu
	*/
	virtual std::shared_ptr<Warehouse> GetById(std::string id) = 0;
};
/**!
 * \brief Klasa WarehouseRepository  odpowiada za zapis i odczyt magazynu z bazy danych
 */
class WarehouseRepository : public IWarehouseRepository
{
public:
	/**
	* Funkcja dodaje magazyn do bazy
	* 
	* \param warehouse magazyn do dodania
	*/
	void addWarehouse(std::shared_ptr<Warehouse> warehouse);
	/**
	* Funkcja pobiera magazyny z bazy
	*
	*/
	std::vector<std::shared_ptr<Warehouse>> GetAll();
	/**
	* Funkcja pobiera magazyny z bazy po id
	*
	* \param id  id magazynu
	*/
	std::shared_ptr<Warehouse> GetById(std::string id);
};

