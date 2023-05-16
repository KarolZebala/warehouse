#include "WarehouseDocument.h"


void WarehouseDocument::addProduct(const std::shared_ptr<Product>& product)
{
    products.push_back(product);
}