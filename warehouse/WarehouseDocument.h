#ifndef WAREHOUSEDOCUMENT_H
#define WAREHOUSEDOCUMENT_H

#include <vector>
#include <string>
#include "Product.h"

class WarehouseDocument {
public:
    explicit WarehouseDocument(std::string documentName);
    virtual void addProductToDocunent(Product* product);

protected:
    std::string DocumentName;
    
    std::vector<Product*> _products;
};

#endif // WAREHOUSEDOCUMENT_H
