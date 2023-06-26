#pragma once
#include "WarehouseDocumentReception.h"
#include "WarehouseDocumentRelease.h"
#include <sqlite3.h>
/**!
 * \brief Klasa IWarehouseDocumentRepository jest klas¹ abstrakcyjn¹, która odpowiada za zapis i odczyt dokumentów magazynowych
 */
class IWarehouseDocumentRepository {
public:
	virtual void addRecepiton(std::shared_ptr<WarehouseDocumentReception>) = 0;
	virtual std::vector<std::shared_ptr<WarehouseDocumentReception>> getAllReceptions() = 0;
	virtual std::shared_ptr<WarehouseDocumentReception> getRecepitonById(std::string receptionId) = 0;

	virtual void addRelease(std::shared_ptr<WarehouseDocumentRelease> release) = 0;
	virtual std::vector<std::shared_ptr<WarehouseDocumentRelease>> getAllReleases() = 0;
	virtual std::shared_ptr<WarehouseDocumentRelease> getReleaseById(std::string releaseId) = 0;
};

/**!
 * \brief Klasa WarehouseDocumentRepository  odpowiada za zapis i odczyt dokumentów magazynowych
 */
class WarehouseDocumentRepository : public IWarehouseDocumentRepository
{
public:
	/**
	* Funkcja dodaje przyjêcie do bazy
	* \param reception przyjecie do dodania
	*/
	void addRecepiton(std::shared_ptr<WarehouseDocumentReception>  reception);
	/**
	* Funkcja pobiera przyjêcia z bazy
	*/
	std::vector<std::shared_ptr<WarehouseDocumentReception>> getAllReceptions();
	/**
	* Funkcja pobiera przyjêcie z bazy po id przyjecia
	*/
	std::shared_ptr<WarehouseDocumentReception> getRecepitonById(std::string receptionId);
	/**
	* Funkcja dodaje wydanie do bazy
	* \param release wydanie do dodania
	*/
	void addRelease(std::shared_ptr<WarehouseDocumentRelease> release);
	/**
	* Funkcja pobiera wydania z bazy
	*/
	std::vector<std::shared_ptr<WarehouseDocumentRelease>> getAllReleases();
	/**
	* Funkcja pobiera wydanie z bazy po id wydania
	*/
	std::shared_ptr<WarehouseDocumentRelease> getReleaseById(std::string releaseId);

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


