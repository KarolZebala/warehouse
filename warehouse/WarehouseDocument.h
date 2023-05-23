#ifndef WAREHOUSEDOCUMENT_H
#define WAREHOUSEDOCUMENT_H

#include <vector>
#include <memory>
#include "Product.h"

class WarehouseDocument {
public:
    virtual ~WarehouseDocument() = default;
    virtual void addProductToDocunent(Product product);

protected:
    std::string DocumentName;
    
    std::vector<Product> products;
};

#endif // WAREHOUSEDOCUMENT_H
