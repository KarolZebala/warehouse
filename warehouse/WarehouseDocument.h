#ifndef WAREHOUSEDOCUMENT_H
#define WAREHOUSEDOCUMENT_H

#include <vector>
#include <string>
#include "Product.h"
#include "GuidProvider.h"
#include "DocumentProduct.h"

class WarehouseDocument {
public:
    explicit WarehouseDocument(std::string documentName, std::string warehosueId, std::string documentId = "");
    virtual void addProductToDocument(std::shared_ptr<DocumentProduct> product) {};

    std::string getName() {
        return this->DocumentName;
    }
    std::string getDocuemntId() {
        return this->DocumentIdGuid;
    }
    std::string getWarehouseId() {
        return this->WarehouseId;
    }

protected:
    std::string DocumentIdGuid;
    std::string DocumentName;
    std::string WarehouseId;
    std::vector<std::shared_ptr<DocumentProduct>> _products;
};

#endif // WAREHOUSEDOCUMENT_H
