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
	void addRecepiton(std::shared_ptr<WarehouseDocumentReception>  reception);
	std::vector<std::shared_ptr<WarehouseDocumentReception>> getAllReceptions();
	std::shared_ptr<WarehouseDocumentReception> getRecepitonById(std::string receptionId);

	void addRelease(std::shared_ptr<WarehouseDocumentRelease> release);
	std::vector<std::shared_ptr<WarehouseDocumentRelease>> getAllReleases();
	std::shared_ptr<WarehouseDocumentRelease> getReleaseById(std::string releaseId);

private:
	void addDocumentProduct(std::shared_ptr<DocumentProduct> product, sqlite3* db);
	std::vector<std::shared_ptr<DocumentProduct >> getAllDocumentProducts(std::string documentId, sqlite3* db);
};


