#pragma once
#include "WarehouseDocumentReception.h"
#include "WarehouseDocumentRelease.h"
#include <sqlite3.h>
class WarehouseDocumentRepository
{
public:
	void addRecepiton(std::shared_ptr<WarehouseDocumentReception>  reception);
	std::vector<WarehouseDocumentReception*> getAllReceptions();
	WarehouseDocumentReception* getRecepitonById(std::string receptionId);

	void addRelease(WarehouseDocumentRelease* release);
	std::vector<WarehouseDocumentRelease*> getAllReleases();
	WarehouseDocumentRelease* getReleaseById(std::string releaseId);

private:
	void addDocumentProduct(std::shared_ptr<DocumentProduct> product, sqlite3* db);
	std::vector<std::shared_ptr<DocumentProduct >> getAllDocumentProducts(std::string documentId, sqlite3* db);
};


