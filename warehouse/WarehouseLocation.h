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
        int height,
        std::string storageMethod,
        std::string warhouseId,
        std::string locationId = ""
    );

    void AddStorageConditon();
    void UpdateStorageConditon();
    bool CheckIfLocationHasStorageCondition();
    bool CheckIfLocationHasSpace(int volume);
    
    virtual std::shared_ptr< WarehouseLocationProduct> AddProductFromDocument(std::shared_ptr<DocumentProduct>  product);
    virtual std::shared_ptr< WarehouseLocationProduct> RemoveProduct(std::shared_ptr<DocumentProduct> product);

    void AddRangeProduct(std::vector<std::shared_ptr<WarehouseLocationProduct>> products);

    std::string GetId();
    std::string getName();
    std::string getStorageMethod();
    int getWidth();
    int getDepth();
    int getHeight();
    int getMaxVolume();
    virtual int getOccupiedVolume() { return 0; };
    std::string getWarehouseId();

private:
    std::string WarehouseLocationIdGuid;
    std::string WarehouseIdGuid;
    std::string Name;
    std::string StorageMethod;
    int Width;
    int Depth;
    int Height;


    std::vector<std::shared_ptr<WarehouseLocationProduct>> _products;
    std::vector<std::string> _storageConditions;
    
};

#endif // WAREHOUSELOCATION_H
