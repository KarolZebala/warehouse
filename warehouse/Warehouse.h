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
    explicit Warehouse(const std::string name);

    void AddWarehouseLocations(
        std::string name,
        int width,
        int depth,
        int height
    );
    void UpdateStorageArea();


    void AddWarehouseDocument(WarehouseDocumentReception* document);
    void AddWarehouseDocument(WarehouseDocumentRelease* document);
    void UpdateWarehosueDocument();


    std::string getName();
    std::string getId();
    WarehouseLocation* GetLocationById(std::string id);


    std::vector<WarehouseDocumentReception*> GetAllWarehouseDocumentReceptions() {
        return _warehouseDocumentReceptions;
    }
    std::vector<WarehouseDocumentRelease*> GetAllWarehouseDocumentReleases() {
        return _warehouseDocumentReleases;
    }

    WarehouseDocumentReception* GetWarehouseDocumentReceptionById(std::string docuementId ) {

        for (auto it = _warehouseDocumentReceptions.begin(); it != _warehouseDocumentReceptions.end(); ++it) {
            if ((*it)->getDocuemntId() == docuementId) {
                return (*it);
            }
        }
        throw new std::exception("Not found reception");
    }
    WarehouseDocumentRelease* GetWarehouseDocumentReleaseById(std::string docuementId) {

        for (auto it = _warehouseDocumentReleases.begin(); it != _warehouseDocumentReleases.end(); ++it) {
            if ((*it)->getDocuemntId() == docuementId) {
                return (*it);
            }
        }
        throw new std::exception("Not found realse");
    }


private:
    int Id;
    std::string Name;
    std::string IdGuid;
    std::time_t CreateDate;
    std::time_t LastUpdateDate;
    std::vector<WarehouseLocation*> _warehouseLocations;
    std::vector<WarehouseDocumentRelease*> _warehouseDocumentReleases;
    std::vector<WarehouseDocumentReception*> _warehouseDocumentReceptions;
    
    
};

#endif // WAREHOUSE_H
