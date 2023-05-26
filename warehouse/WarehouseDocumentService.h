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
    void UpdateWarehouseDocument(WarehouseDocumentDto* dto);

    std::vector<WarehouseDocumentDto> GetAllWarehouses();
    WarehouseDocumentDto GetWarehosueById();

private:
    WarehouseDbContext* _dbContext;
};

