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
/**!
 * \brief Klasa Warehouse reprezentuje magazyn
 */
class Warehouse {
public:
    /**
    * Konstruktor klasy Product
    *
    * \param name nazwa magazynu
    * \param id magazynu
    */
    explicit Warehouse(const std::string name, const std::string warehouseId = "");

    std::string getName();
    std::string getId();
    std::string getCreateDate() {
        return std::to_string(this->CreateDate);
    }
    


private:
    std::string Name;
    std::string IdGuid;
    std::time_t CreateDate;
    std::time_t LastUpdateDate;
    
    
};

#endif // WAREHOUSE_H
