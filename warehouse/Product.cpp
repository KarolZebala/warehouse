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
        throw new std::exception("Nazwa produktu jest wymagana");
    }
    Name = name;
    Condition = condition;
    if (price <= 0) {
        throw new std::exception("Cena nie moze byc mniejsz od 0");
    }
    Price = price;
    if (price <= 0) {
        throw new std::exception("Cena nie moze byc mniejsz od 0");
    }
    Quantity = quantity;
    if (xDimension <= 0) {
        throw new std::exception("Szerokosc nie moze byc mniejsz od 0");
    }
    XDimension = xDimension;
    if (yDimension <= 0) {
        throw new std::exception("Dlugosc nie moze byc mniejsz od 0");
    }
    YDimension = yDimension;
    if (zDimension <= 0) {
        throw new std::exception("wyskosc nie moze byc mniejsz od 0");
    }
    ZDimension = zDimension;
    if (name.empty()) {
        throw new std::exception("Id magazynu jest wymagane");
    }
    WarehouseId = warehouseId;
    StorageMethod = storageMethod;
    Coments = comments;
}

std::string Product::getName()
{
    return Name;
}

void Product::ChangeMainAttributes(
    std::string name,
    std::string condition,
    std::string comments,
    int price,
    int quantity,
    int xDimension,
    int yDimension,
    int zDimension
)
{
    Name = name;
    Condition = condition;
    Price = price;
    Quantity = quantity;
    XDimension = xDimension;
    YDimension = yDimension;
    ZDimension = zDimension;

}

void Product::AddStorageConditon(std::string type, int minValue, int maxValue)
{
    if (type == "TEMPERATURE" || type == "temperature") {
        auto storageConditon = new TemperatureStorageConditions();
        _storageConditions.push_back(storageConditon);
    }else if (type == "HUMIDITY" || type == "humidity") {
        auto storageConditon = new TemperatureStorageConditions();
        _storageConditions.push_back(storageConditon);
    }
    else {
        throw new std::exception("Invalid storage condition type passed");
    }

    auto storageConditon = new StorageConditions();
    _storageConditions.push_back(storageConditon);
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
