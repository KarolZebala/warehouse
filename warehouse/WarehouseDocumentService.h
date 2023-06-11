#pragma once
#include "WarehouseDocumentDto.h"
#include "WarehouseDocument.h"
#include "vector"
#include "WarehouseDbContext.h"
#include "WarehouseDocumentRepository.h"
#include "WarehouseLocationRepository.h"
#include "WarehouseRepository.h"
class WarehouseDocumentService
{
public:
    explicit WarehouseDocumentService();

    void CreateWarehouseReceptionDocument(WarehouseDocumentDto dto);
    void CreateWarehouseReleaseDocument(WarehouseDocumentDto dto);
   

    std::vector<std::shared_ptr<WarehouseDocumentDto>> GetAllWarehouseDocumentReleasesDocuements(std::string warehouseId);
    std::vector< std::shared_ptr<WarehouseDocumentDto>> GetAllWarehouseDocumentReceptionsDocuements(std::string warehosueId);

    std::shared_ptr<WarehouseDocumentDto> GetWarehosueDocumentReceptionById(std::string warehouseId, std::string documentId);
    std::shared_ptr<WarehouseDocumentDto> GetWarehosueDocumentReleaseById(std::string warehouseId, std::string documentId);

private:
    std::shared_ptr<WarehouseRepository> _warehouseRepository;
    std::shared_ptr<WarehouseDocumentRepository> _documentRepository;
    std::shared_ptr<WarehouseLocationRepository> _locationRepository;

};

