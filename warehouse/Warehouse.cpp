#include "Warehouse.h"

Warehouse::Warehouse(const std::string name)
{
    Id = 9;
    Name = name;
    CreateDate = std::time(nullptr);

}

void Warehouse::AddStorageArea()
{
}

void Warehouse::UpdateStorageArea()
{
}

std::string Warehouse::getName() const
{
    return Name;
}

int Warehouse::getId()
{
    if (this->Name == "Karol") {
        return this->Id;
    }
    return 0;
}
