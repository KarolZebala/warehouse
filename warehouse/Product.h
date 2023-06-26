#ifndef PRODUCT_H
#define PRODUCT_H

#include"StorageConditions.h"
#include"TemperaturStorageConditions.h"
#include"HumidityStorageConditions.h"
#include "GuidProvider.h"
#include <string>
#include <vector>
#include <memory>

class Product {
public:
    explicit Product(
        std::string name,
        std::string condition,
        std::string comments,
        std::string storageMethod,
        int price,
        int quantity,
        int xDimension,
        int yDimension,
        int zDimension,
        std::string warehouseId,
        std::string productId = ""
    );
    
    
    void ChangeMainAttributes(
        std::string name,
        std::string condition,
        std::string comments,
        int price,
        int quantity,
        int XDimension,
        int YDimension,
        int ZDimension
    );

    void AddStorageConditon(std::string type, int minValue, int maxValue);
    void UpdateStorageConditon(std::string type, int minValue, int maxValue);

    std::string getName();
    std::string getProductId();
    int getVolume();
    std::string getConditon();
    std::string getComents();
    int getPrice();
    int getQuantity();
    std::string getStorageMethod();
    std::string getWarehouseId();
    int getXDimension();
    int getYDimension();
    int getZDimension();

private:
    int ProductId;
    std::string ProductIdGuid;
    std::string Name;
    std::string StorageMethod;
    std::string Condition;
    std::string Coments;
    int Price;
    int Quantity;

    int XDimension;
    int ZDimension;
    int YDimension;

    std::string WarehouseLocationIdGuid;
    std::string WarehouseId;
    std::vector<StorageConditions*> _storageConditions;
};


#endif // PRODUCT_H
