#include "WarehouseLocation.h"

WarehouseLocation::WarehouseLocation(
    std::string name,
    int width,
    int depth,
    int height
)
{
    WarehouseLocationIdGuid = GuidProvider::GetGuidString();
    Name = name;
    if (width <= 0) {
        throw std::exception("Invalid value of width");
    }
    if (depth <= 0) {
        throw std::exception("Invalid value of depth");
    }
    if (height <= 0) {
        throw std::exception("Invalid value of height");
    }
    Width = width;
    Depth = depth;
    Height = height;
}

std::string WarehouseLocation::getName()
{
    return this->Name;
}

int WarehouseLocation::getOccupiedVolume()
{
    auto res = 0;
    for (auto product : _products) {
        res += product->getVolume();
    }
    return res;
}

std::string WarehouseLocation::GetId()
{
    return this->WarehouseLocationIdGuid;
}

void WarehouseLocation::AddProduct(Product* product)
{
    //warunki do dodania produktu
    auto locationProduct = new WarehouseLocationProduct(product->getProductId(), product->getVolume());
    _products.push_back(locationProduct);
}

void WarehouseLocation::RemoveProduct(Product* product)
{
    auto productIdToRemove = product->getProductId();
    //trzeba dopisaæ logikê do usuwania produktu na rózne sposoby
    for (auto curentProduct = _products.begin(); curentProduct != _products.end(); ++curentProduct) {
        if ((*curentProduct)->getProductId() == productIdToRemove) {
            delete* curentProduct;
            _products.erase(curentProduct);
            break;
        }
    }
}
