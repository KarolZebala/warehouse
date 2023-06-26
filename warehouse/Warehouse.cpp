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


void Warehouse::UpdateStorageArea()
{
}

void Warehouse::AddWarehouseDocument(std::shared_ptr<WarehouseDocument> document)
{
    _warehouseDocuments.push_back(document);
}


std::string Warehouse::getName()
{
    return this->Name;
}

std::string Warehouse::getId()
{ 
    return IdGuid;
}
void Warehouse::setId(std::string id) {
    IdGuid = id;
}

std::shared_ptr<WarehouseLocation> Warehouse::GetLocationById(std::string id)
{
    for (const auto& obj : _warehouseLocations) {
        if (obj->GetId() == id) {
            return obj;
        }
    }
    return nullptr;
}
std::vector<std::shared_ptr<WarehouseLocation>> Warehouse::getAllLocations() {
    return this->_warehouseLocations;
}



std::string Warehouse::AddProdcut(std::shared_ptr<Product> product)
{
    _warehouseProducts.push_back(product);
    return product->getProductId();
}

