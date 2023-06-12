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
        std::string warhouseId,
        std::string locationId = ""
    );

    

    void AddStorageConditon();
    void UpdateStorageConditon();
    bool CheckIfLocationHasStorageCondition();
    bool CheckIfLocationHasSpace(int volume);
    
    virtual void AddProductFromDocument(DocumentProduct* product);
    virtual void RemoveProduct(DocumentProduct* product);


    std::string GetId();
    std::string getName();
    int getWidth();
    /*{
        return this->Width;
    }*/
    int getDepth();
    /*{
        return this->Depth;
    }*/
    int getHeight();
   /* {
        return this->Height;
    }*/
    int getMaxVolume();
  /*  {
        return this->Width * this->Depth * this->Height;
    }*/
    virtual int getOccupiedVolume() { return 0; };
    std::string getWarehouseId();
    //{ return this->WarehouseIdGuid; };

private:
    std::string WarehouseLocationIdGuid;
    std::string WarehouseIdGuid;
    std::string Name;
    int Width;
    int Depth;
    int Height;


    std::vector<WarehouseLocationProduct*> _products;
    std::vector<StorageConditions*> _storageConditions;
    
};

#endif // WAREHOUSELOCATION_H
