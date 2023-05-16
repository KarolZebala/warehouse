#ifndef WAREHOUSEDOCUMENT_H
#define WAREHOUSEDOCUMENT_H

#include <vector>
#include <memory>
#include "Product.h"

class WarehouseDocument {
public:
    virtual ~WarehouseDocument() = default;
    void addProduct(const std::shared_ptr<Product>& product);

protected:
    std::vector<std::shared_ptr<Product>> products;
};

#endif // WAREHOUSEDOCUMENT_H
