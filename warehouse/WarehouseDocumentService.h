#pragma once
#include "WarehouseDocumentDto.h"
#include "WarehouseDocument.h"
#include "vector"
#include "WarehouseDbContext.h"
#include "WarehouseDocumentRepository.h"
#include "WarehouseLocationRepository.h"
#include "WarehouseRepository.h"
#include "WarehouseReceptionDocumentDto.h"
class IWarehouseDocumentService {
public:
    virtual std::vector<WarehouseDocumentDto*> GetAllWarehouseDocumentReleasesDocuements(std::string warehouseId) { return std::vector<WarehouseDocumentDto*>(); };
    virtual std::vector<WarehouseDocumentDto*> GetAllWarehouseDocumentReceptionsDocuements(std::string warehosueId) { return std::vector<WarehouseDocumentDto*>(); };
    //virtual WarehouseDocumentDto* GetWarehosueDocumentReceptionById(std::string warehouseId, std::string documentId) { return new WarehouseDocumentDto; };
    //virtual WarehouseDocumentDto* GetWarehosueDocumentReleaseById(std::string warehouseId, std::string documentId) { return new WarehouseDocumentDto; };
};
class WarehouseDocumentService
{
public:
    explicit WarehouseDocumentService();

    void CreateWarehouseDocument(WarehouseReleseDocumentDto dto);
    void CreateWarehouseDocument(WarehouseReceptionDocumentDto dto);
   

    std::vector<std::shared_ptr<WarehouseDocumentDto>> GetAllWarehouseDocumentReleasesDocuements(std::string warehouseId);
    std::vector< std::shared_ptr<WarehouseDocumentDto>> GetAllWarehouseDocumentReceptionsDocuements(std::string warehosueId);

    std::shared_ptr<WarehouseDocumentDto> GetWarehosueDocumentReceptionById(std::string warehouseId, std::string documentId);
    std::shared_ptr<WarehouseDocumentDto> GetWarehosueDocumentReleaseById(std::string warehouseId, std::string documentId);

private:
    std::shared_ptr<WarehouseRepository> _warehouseRepository;
    std::shared_ptr<WarehouseDocumentRepository> _documentRepository;
    std::shared_ptr<WarehouseLocationRepository> _locationRepository;

};

