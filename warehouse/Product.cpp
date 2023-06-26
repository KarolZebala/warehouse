#include "Product.h"

Product::Product(
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
    std::string productId
)
{
    
    if (productId == "") {
        ProductIdGuid = GuidProvider::GetGuidString();
    }
    else {
        ProductIdGuid = productId;
    }
    if (name.empty()) {
        throw std::exception("Nazwa produktu jest wymagana");
    }
    Name = name;
    Condition = condition;
    if (price <= 0) {
        throw std::exception("Cena nie moze byc mniejsz od 0");
    }
    Price = price;
    if (price <= 0) {
        throw std::exception("Cena nie moze byc mniejsz od 0");
    }
    Quantity = quantity;
    if (xDimension <= 0) {
        throw std::exception("Szerokosc nie moze byc mniejsz od 0");
    }
    XDimension = xDimension;
    if (yDimension <= 0) {
        throw std::exception("Dlugosc nie moze byc mniejsz od 0");
    }
    YDimension = yDimension;
    if (zDimension <= 0) {
        throw std::exception("wyskosc nie moze byc mniejsz od 0");
    }
    ZDimension = zDimension;
    if (name.empty()) {
        throw std::exception("Id magazynu jest wymagane");
    }
    WarehouseId = warehouseId;
    StorageMethod = storageMethod;
    Coments = comments;
}

std::string Product::getName()
{
    return Name;
}


std::string Product::getProductId()
{
    return this->ProductIdGuid;
}

int Product::getVolume()
{
    auto res = this->XDimension * this->YDimension * this->ZDimension;
    return res;
}

std::string Product::getConditon()
{
    return this->Condition;
}

std::string Product::getComents()
{
    return this->Coments;
}

int Product::getPrice()
{
    return this->Price;
}

int Product::getQuantity()
{
    return this->Quantity;
}

int Product::getXDimension()
{
    return this->XDimension;
}
int Product::getYDimension()
{
    return this->YDimension;
}

int Product::getZDimension()
{
    return this->ZDimension;
}


std::string Product::getStorageMethod()
{
    return this->StorageMethod;
}

std::string Product::getWarehouseId()
{
    return this->WarehouseId;
}
