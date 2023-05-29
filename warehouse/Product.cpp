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
    int locationId
)
{
    Name = name;
    Condition = condition;
    Price = price;
    Quantity = quantity;
    XDimension = xDimension;
    YDimension = yDimension;
    ZDimension = zDimension;
    WarehouseLocationId = locationId;
}

std::string Product::getName() const
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

int Product::getProductId()
{
    return this->ProductId;
}
