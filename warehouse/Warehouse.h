#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include "StorageArea.h"
#include "WarehouseDocumentReception.h"
#include "WarehouseDocumentRelease.h"
#include "GuidProvider.h"
#include <vector>
#include <memory>
#include <ctime>
//#include"WarehouseDocument.h"
class Warehouse {
public:
    explicit Warehouse(const std::string name, const std::string warehouseId = "");

    void UpdateStorageArea();


    void AddWarehouseDocument(std::shared_ptr<WarehouseDocument> document);


    std::string getName();
    std::string getId();
    std::string getCreateDate() {
        return std::to_string(this->CreateDate);
    }

    void setId(std::string id);
    std::shared_ptr<WarehouseLocation> GetLocationById(std::string id);
    std::vector<std::shared_ptr<WarehouseLocation>> getAllLocations();

    std::vector<std::shared_ptr<WarehouseDocumentReception>> GetAllWarehouseDocumentReceptions();

    std::vector<WarehouseDocumentRelease> GetAllWarehouseDocumentReleases();

    std::shared_ptr<WarehouseDocumentReception> GetWarehouseDocumentReceptionById(std::string docuementId);

    std::shared_ptr<WarehouseDocumentRelease> GetWarehouseDocumentReleaseById(std::string docuementId);
    

    std::string AddProdcut(std::shared_ptr<Product> product);
    std::shared_ptr<Product> GetProductById(std::string productId);
    std::vector<std::shared_ptr<Product>> GetAllProducts();
    


private:
    std::string Name;
    std::string IdGuid;
    std::time_t CreateDate;
    std::time_t LastUpdateDate;
    std::vector<std::shared_ptr<WarehouseLocation>> _warehouseLocations;
    std::vector<std::shared_ptr<WarehouseDocument>> _warehouseDocuments;
    std::vector<std::shared_ptr<Product>> _warehouseProducts;
    
    
};

#endif // WAREHOUSE_H
