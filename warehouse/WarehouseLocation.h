#ifndef WAREHOUSELOCATION_H
#define WAREHOUSELOCATION_H

#include <string>
#include <vector>
#include <memory>
#include "Product.h"

class WarehouseLocation {
public:
    explicit WarehouseLocation(const std::string& name);

    std::string getName() const; 

    void AddStorageConditon();
    void UpdateStorageConditon();
    bool CheckIfLocationHasStorageCondition();


private:
    std::string Name;
    std::vector<Product> _products;
    std::vector<StorageConditions> _storageConditions;
    
};

#endif // WAREHOUSELOCATION_H
