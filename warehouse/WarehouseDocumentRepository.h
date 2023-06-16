#pragma once
#include "WarehouseDocumentReception.h"
#include "WarehouseDocumentRelease.h"
#include <sqlite3.h>
class IWarehouseDocumentRepository {
public:
	void addRecepiton(std::shared_ptr<WarehouseDocumentReception>  reception) {};
	std::vector<std::shared_ptr<WarehouseDocumentReception>> getAllReceptions() { return std::vector<std::shared_ptr<WarehouseDocumentReception>>(); };
	std::shared_ptr<WarehouseDocumentReception> getRecepitonById(std::string receptionId) { return std::shared_ptr<WarehouseDocumentReception>(); };

	void addRelease(std::shared_ptr<WarehouseDocumentRelease> release) {};
	std::vector<std::shared_ptr<WarehouseDocumentRelease>> getAllReleases();
	std::shared_ptr<WarehouseDocumentRelease> getReleaseById(std::string releaseId);
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


