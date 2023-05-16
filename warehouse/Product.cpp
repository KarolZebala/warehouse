#include "Product.h"

Product::Product(const std::string& name, int quantity)
    : name(name), quantity(quantity)
{
}

std::string Product::getName() const
{
    return name;
}

int Product::getQuantity() const
{
    return quantity;
}