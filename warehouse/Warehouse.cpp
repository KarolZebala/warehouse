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

//void Warehouse::AddWarehouseLocations(
//    std::string name,
//    int width,
//    int depth,
//    int height,
//
//)
//{
//    auto location =  WarehouseLocation(
//        name,
//        width,
//        depth,
//        height
//    );
//    auto locationPtr = std::make_shared<WarehouseLocation>(location);
//    _warehouseLocations.push_back(locationPtr);
//}

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


//std::vector<std::shared_ptr<WarehouseDocumentReception>> Warehouse::GetAllWarehouseDocumentReceptions() {
//    return _;
//}
//std::vector< std::shared_ptr<WarehouseDocumentRelease>> Warehouse::GetAllWarehouseDocumentReleases() {
//    return _warehouseDocumentReleases;
//}

//WarehouseDocumentReception Warehouse::GetWarehouseDocumentReceptionById(std::string docuementId) {
//
//    for (auto it = _warehouseDocumentReceptions.begin(); it != _warehouseDocumentReceptions.end(); ++it) {
//        if ((*it)->getDocuemntId() == docuementId) {
//            return (*it);
//        }
//    }
//    throw new std::exception("Not found reception");
//}
//WarehouseDocumentRelease* Warehouse::GetWarehouseDocumentReleaseById(std::string docuementId) {
//
//    for (auto it = _warehouseDocumentReleases.begin(); it != _warehouseDocumentReleases.end(); ++it) {
//        if ((*it)->getDocuemntId() == docuementId) {
//            return (*it);
//        }
//    }
//    throw new std::exception("Not found realse");
//}

std::string Warehouse::AddProdcut(std::shared_ptr<Product> product)
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
