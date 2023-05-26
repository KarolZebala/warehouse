#ifndef WAREHOUSELOCATION_H
#define WAREHOUSELOCATION_H

#include <string>
#include <vector>
#include <memory>
#include "Product.h"

class WarehouseLocation {
public:
    explicit WarehouseLocation(
        std::string name,
        int width,
        int depth,
        int height
    );

    std::string getName() const; 

    void AddStorageConditon();
    void UpdateStorageConditon();
    bool CheckIfLocationHasStorageCondition();
    int GetId();
    void AddProduct(Product* product);


private:
    int WarehouseLocationId;
    std::string Name;
    int Width;
    int Depth;
    int Height;
    std::vector<Product*> _products;
    std::vector<StorageConditions*> _storageConditions;
    
};

#endif // WAREHOUSELOCATION_H
