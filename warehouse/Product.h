#ifndef PRODUCT_H
#define PRODUCT_H

#include"StorageConditions.h"
#include <string>
#include <vector>
#include <memory>

class Product {
public:
    explicit Product(const std::string& name, int quantity);

    std::string getName() const;
    
    void AddStorageConditon();
    void UpdateStorageConditon();
    

private:
    std::string Name;

    int XDimension;
    int ZDimension;
    int YDimension;

    std::vector<StorageConditions> _storageConditions;
};

#endif // PRODUCT_H
