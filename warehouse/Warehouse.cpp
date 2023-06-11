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

void Warehouse::AddWarehouseLocations(
    std::string name,
    int width,
    int depth,
    int height
)
{
   /* auto location = new WarehouseLocation(
        name,
        width,
        depth,
        height
    );
    _warehouseLocations.push_back(location);*/
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

//std::shared_ptr<WarehouseLocation> Warehouse::GetLocationById(std::string id)
//{
//    for (const auto& obj : _warehouseLocations) {
//        if (obj->GetId() == id) {
//            return obj;
//        }
//    }
//    return nullptr;
//}

std::string Warehouse::AddProdcut(Product* product)
{
    _warehouseProducts.push_back(product);
    return product->getProductId();
}
//
//Product* Warehouse::GetProductById(std::string productId)
//{
//    for (const auto& product : _warehouseProducts) {
//        if (product->getProductId() == productId){
//            return product;
//        }
//    }
//    return nullptr;
//}
