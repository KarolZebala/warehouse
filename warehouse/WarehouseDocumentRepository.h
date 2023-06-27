#pragma once
#include "WarehouseDocumentReception.h"
#include "WarehouseDocumentRelease.h"
#include <sqlite3.h>
/**!
 * \brief Klasa IWarehouseDocumentRepository jest klasą abstrakcyjną, która odpowiada za zapis i odczyt dokumentów magazynowych
 */
class IWarehouseDocumentRepository {
public:
	/**
	* Funkcja wirtualna dodająca dokument przyjęcie magazynowe do bazy
	* \param reception przyjecie do dodania
	*/
	virtual void addRecepiton(std::shared_ptr<WarehouseDocumentReception>) = 0;
	/**
	* Funkcja wirtualna pobierająca przyjęcia z bazy
	* \param warehouseId id magazynu
	*/
	virtual std::vector<std::shared_ptr<WarehouseDocumentReception>> getAllReceptions(std::string warehouseId) = 0;
	/**
	* Funkcja wirtualna pobierająca przyjęcie z bazy po id przyjecia
	* \param receptionId id wydania
	* \param warehouseId id magazynu
	*/
	virtual std::shared_ptr<WarehouseDocumentReception> getRecepitonById(std::string receptionId, std::string warehouseId) = 0;
	/**
	* Funkcja wirtualna dodająca wydanie do bazy
	* \param release wydanie do dodania
	*/
	virtual void addRelease(std::shared_ptr<WarehouseDocumentRelease> release) = 0;
	/**
	* Funkcja wirtualna pobierająca wydania z bazy
	* \param warehouseId id magazynu
	*/
	virtual std::vector<std::shared_ptr<WarehouseDocumentRelease>> getAllReleases(std::string warehouseId) = 0;
	/**
	* Funkcja wirtualna pobierająca wydanie z bazy po id wydania
	* \param releaseId id wydania
	* \param warehouseId id magazynu
	*/
	virtual std::shared_ptr<WarehouseDocumentRelease> getReleaseById(std::string releaseId, std::string warehouseId) = 0;
};

/**!
 * \brief Klasa WarehouseDocumentRepository  odpowiada za zapis i odczyt dokumentów magazynowych
 */
class WarehouseDocumentRepository : public IWarehouseDocumentRepository
{
public:
	/**
	* Funkcja dodaje dokument przyjęcie magazynowe do bazy
	* \param reception przyjecie do dodania
	*/
	void addRecepiton(std::shared_ptr<WarehouseDocumentReception>  reception);
	/**
	* Funkcja pobiera przyjęcia z bazy
	* \param warehouseId id magazynu
	*/
	std::vector<std::shared_ptr<WarehouseDocumentReception>> getAllReceptions(std::string warehouseId);
	/**
	* Funkcja pobiera przyjęcie z bazy po id przyjecia
	* \param receptionId id wydania
	* \param warehouseId id magazynu
	*/
	std::shared_ptr<WarehouseDocumentReception> getRecepitonById(std::string receptionId, std::string warehouseId);
	/**
	* Funkcja dodaje wydanie do bazy
	* \param release wydanie do dodania
	*/
	void addRelease(std::shared_ptr<WarehouseDocumentRelease> release);
	/**
	* Funkcja pobiera wydania z bazy
	* \param warehouseId id magazynu
	*/
	std::vector<std::shared_ptr<WarehouseDocumentRelease>> getAllReleases(std::string warehouseId);
	/**
	* Funkcja pobiera wydanie z bazy po id wydania
	* \param releaseId id wydania
	* \param warehouseId id magazynu
	*/
	std::shared_ptr<WarehouseDocumentRelease> getReleaseById(std::string releaseId, std::string warehouseId);

private:
	/**
	* Funkcja dodaje produkty z dokumentu do bazy
	*/
	void addDocumentProduct(std::shared_ptr<DocumentProduct> product, sqlite3* db);
	/**
	* Funkcja pobiera produkty dokumentu na podstawie id dokumentu
	*/
	std::vector<std::shared_ptr<DocumentProduct >> getAllDocumentProducts(std::string documentId, sqlite3* db);
};


