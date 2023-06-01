#include "Product.h"

Product::Product(
    std::string name,
    std::string condition,
    std::string comments,
    int price,
    int quantity,
    int xDimension,
    int yDimension,
    int zDimension,
    std::string locationId
)
{
    ProductIdGuid = GuidProvider::GetGuidString();
    Name = name;
    Condition = condition;
    Price = price;
    Quantity = quantity;
    XDimension = xDimension;
    YDimension = yDimension;
    ZDimension = zDimension;
    WarehouseLocationIdGuid = locationId;
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
