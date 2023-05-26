#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include "StorageArea.h"
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


    //void AddWarehouseDocument(WarehouseDocument* document);
    void UpdateWarehosueDocument();


    std::string getName();
    int getId();
    WarehouseLocation* GetLocationById(int id);

private:
    int Id;
    std::string Name;
    std::time_t CreateDate;
    std::time_t LastUpdateDate;
    std::vector<WarehouseLocation*> _warehouseLocations;
    
};

#endif // WAREHOUSE_H
