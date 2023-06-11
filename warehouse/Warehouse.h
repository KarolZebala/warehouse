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

    void AddWarehouseLocations(
        std::string name,
        int width,
        int depth,
        int height
    );
    void UpdateStorageArea();


    void AddWarehouseDocument(std::shared_ptr<WarehouseDocument> document);
    void UpdateWarehosueDocument();


    std::string getName();
    std::string getId();

    void setId(std::string id) {
        IdGuid = id;
    }

    std::shared_ptr<WarehouseLocation>  GetLocationById(std::string id);
    std::vector<std::shared_ptr<WarehouseLocation> > getAllLocations() {
        return this->_warehouseLocations;
    }


   /* std::vector<WarehouseDocumentReception*> GetAllWarehouseDocumentReceptions() {
        return _warehouseDocumentReceptions;
    }
    std::vector<WarehouseDocumentRelease*> GetAllWarehouseDocumentReleases() {
        return _warehouseDocumentReleases;
    }*/

   /* WarehouseDocumentReception* GetWarehouseDocumentReceptionById(std::string docuementId ) {

        for (auto it = _warehouseDocumentReceptions.begin(); it != _warehouseDocumentReceptions.end(); ++it) {
            if ((*it)->getDocuemntId() == docuementId) {
                return (*it);
            }
        }
        throw new std::exception("Not found reception");
    }*/
    /*WarehouseDocumentRelease* GetWarehouseDocumentReleaseById(std::string docuementId) {

        for (auto it = _warehouseDocumentReleases.begin(); it != _warehouseDocumentReleases.end(); ++it) {
            if ((*it)->getDocuemntId() == docuementId) {
                return (*it);
            }
        }
        throw new std::exception("Not found realse");
    }*/

    std::string AddProdcut(std::shared_ptr<Product> product);
    /*Product* GetProductById(std::string productId);
    std::vector<Product*> GetAllProducts() {
        return _warehouseProducts;
    }*/


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
