#include "WarehouseLocation.h"

WarehouseLocation::WarehouseLocation(
    std::string name,
    int width,
    int depth,
    int height
)
{
    Name = name;
    //to do: add validation
    Width = width;
    Depth = depth;
    Height = height;
}

std::string WarehouseLocation::getName() const
{
    return Name;
}

int WarehouseLocation::GetId()
{
    return this->WarehouseLocationId;
}

void WarehouseLocation::AddProduct(Product* product)
{
    //warunki do dodania produktu
    _products.push_back(product);
}

void WarehouseLocation::RemoveProduct(Product* product)
{
    auto productIdToRemove = product->getProductId();
    //trzeba dopisa� logik� do usuwania produktu na r�zne sposoby
    for (auto curentProduct = _products.begin(); curentProduct != _products.end(); ++curentProduct) {
        if ((*curentProduct)->getProductId() == productIdToRemove) {
            delete* curentProduct;
            _products.erase(curentProduct);
            break;
        }
    }
}
