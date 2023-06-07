#pragma once
#include "WarehouseDocumentDto.h"
#include "WarehouseDocument.h"
#include "vector"
#include "WarehouseDbContext.h"
#include "WarehouseDocumentRepository.h"
#include "WarehouseLocationRepository.h"
class WarehouseDocumentService
{
public:
    explicit WarehouseDocumentService();

    int CreateWarehouseReceptionDocument(WarehouseDocumentDto* dto);
    int CreateWarehouseReleaseDocument(WarehouseDocumentDto* dto);
   

    std::vector<WarehouseDocumentDto*> GetAllWarehouseDocumentReleasesDocuements(std::string warehouseId);
    std::vector<WarehouseDocumentDto*> GetAllWarehouseDocumentReceptionsDocuements(std::string warehosueId);

    WarehouseDocumentDto* GetWarehosueDocumentReceptionById(std::string warehouseId, std::string documentId);
    WarehouseDocumentDto* GetWarehosueDocumentReleaseById(std::string warehouseId, std::string documentId);

private:
    WarehouseDbContext* _dbContext;
    WarehouseDocumentRepository* _documentRepository;
    WarehouseLocationRepository* _locationRepository;

};

