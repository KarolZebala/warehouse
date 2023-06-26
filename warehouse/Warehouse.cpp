#include "Warehouse.h"

Warehouse::Warehouse(const std::string name, std::string warehosueId)
{
    if (warehosueId == "") {
        IdGuid = GuidProvider::GetGuidString();
    }else{
        IdGuid = warehosueId;
    }
    
    Name = name;
    CreateDate = std::time(nullptr);

}
std::string Warehouse::getName()
{
    return this->Name;
}

std::string Warehouse::getId()
{ 
    return IdGuid;
}


