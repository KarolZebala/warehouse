#pragma once
#include "WarehouseDocumentDto.h"
#include "WarehouseDocument.h"
#include "vector"
#include "WarehouseDbContext.h"
class WarehouseDocumentService
{
public:
    explicit WarehouseDocumentService();

    int CreateWarehouseReceptionDocument(WarehouseDocumentDto* dto);
    int CreateWarehouseReleaseDocument(WarehouseDocumentDto* dto);
    void UpdateWarehouseDocument(WarehouseDocumentDto* dto);

    std::vector<WarehouseDocumentDto*> GetAllWarehouseDocumentReleasesDocuements(int warehouseId);
    std::vector<WarehouseDocumentDto*> GetAllWarehouseDocumentReceptionsDocuements(int warehosueId);

    WarehouseDocumentDto* GetWarehosueDocumentReceptionById(int warehouseId, int documentId);
    WarehouseDocumentDto* GetWarehosueDocumentReleaseById(int warehouseId, int documentId);

private:
    WarehouseDbContext* _dbContext;
};

