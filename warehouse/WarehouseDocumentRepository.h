#pragma once
#include "WarehouseDocumentReception.h"
#include "WarehouseDocumentRelease.h"
#include <sqlite3.h>
class WarehouseDocumentRepository
{
public:
	void addRecepiton(WarehouseDocumentReception* reception);
	std::vector<WarehouseDocumentReception*> getAllReceptions();
	WarehouseDocumentReception* getRecepitonById(std::string receptionId);

	void addRecepiton(WarehouseDocumentRelease* release);
	std::vector<WarehouseDocumentRelease*> getAllReleases();
	WarehouseDocumentRelease* getReleaseById(std::string releaseId);
};

