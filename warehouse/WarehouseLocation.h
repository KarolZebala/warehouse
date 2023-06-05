#ifndef WAREHOUSELOCATION_H
#define WAREHOUSELOCATION_H

#include <string>
#include <vector>
#include <memory>
#include "Product.h"
#include "GuidProvider.h"
#include "WarehouseLocationProduct.h"
#include "DocumentProduct.h"

class WarehouseLocation {
public:
    explicit WarehouseLocation(
        std::string name,
        int width,
        int depth,
        int height
    );

    

    void AddStorageConditon();
    void UpdateStorageConditon();
    bool CheckIfLocationHasStorageCondition();
    
    void AddProductFromDocument(DocumentProduct* product);
    void RemoveProduct(DocumentProduct* product);


    std::string GetId();
    std::string getName();
    int getWidth() {
        return this->Width;
    }
    int getDepth() {
        return this->Depth;
    }
    int getHeight() {
        return this->Height;
    }
    int getMaxVolume() {
        return this->Width * this->Depth * this->Height;
    }
    int getOccupiedVolume();

private:
    int WarehouseLocationId;
    std::string WarehouseLocationIdGuid;
    std::string Name;
    int Width;
    int Depth;
    int Height;

    std::vector<WarehouseLocationProduct*> _products;
    std::vector<StorageConditions*> _storageConditions;
    
};

#endif // WAREHOUSELOCATION_H
