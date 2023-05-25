#ifndef PRODUCT_H
#define PRODUCT_H

#include"StorageConditions.h"
#include"TemperaturStorageConditions.h"
#include"HumidityStorageConditions.h"
#include <string>
#include <vector>
#include <memory>

class Product {
public:
    explicit Product(
        std::string name,
        std::string condition,
        std::string comments,
        int price,
        int quantity,
        int xDimension,
        int yDimension,
        int zDimension
    );

    std::string getName() const;
    
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

private:
    std::string Name;
    std::string StorageMethod;
    std::string Condition;
    std::string Coments;
    int Price;
    int Quantity;

    int XDimension;
    int ZDimension;
    int YDimension;

    std::vector<StorageConditions*> _storageConditions;
};


#endif // PRODUCT_H
