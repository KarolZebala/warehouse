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
    virtual void CreateWarehouseDocument(WarehouseReleseDocumentDto dto) {};
    virtual void CreateWarehouseDocument(WarehouseReceptionDocumentDto dto) {};
    virtual std::vector<std::shared_ptr<WarehouseDocumentDto>> GetAllWarehouseDocumentReleasesDocuements(std::string warehouseId) { return std::vector<std::shared_ptr<WarehouseDocumentDto>>(); };
    virtual std::vector<std::shared_ptr<WarehouseDocumentDto>> GetAllWarehouseDocumentReceptionsDocuements(std::string warehosueId) { return std::vector<std::shared_ptr<WarehouseDocumentDto>>(); };
    virtual std::shared_ptr<WarehouseDocumentDto> GetWarehosueDocumentReceptionById(std::string warehouseId, std::string documentId) { return std::shared_ptr<WarehouseDocumentDto>(); };
    virtual std::shared_ptr<WarehouseDocumentDto> GetWarehosueDocumentReleaseById(std::string warehouseId, std::string documentId) { return std::shared_ptr<WarehouseDocumentDto>(); };
};
class WarehouseDocumentService : public IWarehouseDocumentService
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
    std::shared_ptr<IWarehouseRepository> _warehouseRepository;
    std::shared_ptr<IWarehouseDocumentRepository> _documentRepository;
    std::shared_ptr<IWarehouseLocationRepository> _locationRepository;

};

