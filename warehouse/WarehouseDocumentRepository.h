#pragma once
#include "WarehouseDocumentReception.h"
#include "WarehouseDocumentRelease.h"
#include <sqlite3.h>
class IWarehouseDocumentRepository {
public:
	//virtual void addRecepiton(WarehouseDocumentReception* reception) { return std::vector<Product*>(); };
	virtual std::vector<WarehouseDocumentReception*> getAllReceptions() { return std::vector<WarehouseDocumentReception*>(); };
	//virtual WarehouseDocumentReception* getRecepitonById(std::string receptionId) { return new WarehouseDocumentReception(); };

	//virtual void addRelease(WarehouseDocumentRelease* release) { return std::vector<Product*>(); };
	virtual std::vector<WarehouseDocumentRelease*> getAllReleases() { return std::vector<WarehouseDocumentRelease*>(); };
	//virtual WarehouseDocumentRelease* getReleaseById(std::string releaseId) { return new WarehouseDocumentRelease(); };
};
class WarehouseDocumentRepository
{
public:
	void addRecepiton(WarehouseDocumentReception* reception);
	std::vector<WarehouseDocumentReception*> getAllReceptions();
	WarehouseDocumentReception* getRecepitonById(std::string receptionId);

	void addRelease(WarehouseDocumentRelease* release);
	std::vector<WarehouseDocumentRelease*> getAllReleases();
	WarehouseDocumentRelease* getReleaseById(std::string releaseId);

private:
	void addDocumentProduct(DocumentProduct* product, sqlite3* db);
	std::vector<DocumentProduct*> getAllDocumentProducts(std::string documentId, sqlite3* db);
};


