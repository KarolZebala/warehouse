#ifndef WAREHOUSEDOCUMENT_H
#define WAREHOUSEDOCUMENT_H

#include <vector>
#include <string>
#include "Product.h"
#include "GuidProvider.h"

class WarehouseDocument {
public:
    explicit WarehouseDocument(std::string documentName);
    virtual void addProductToDocunent(Product* product);

    std::string getName() {
        return this->DocumentName;
    }
    std::string getDocuemntId() {
        return this->DocumentIdGuid;
    }

protected:
    int DocuementId;
    std::string DocumentIdGuid;
    std::string DocumentName;
    
    std::vector<Product*> _products;
};

#endif // WAREHOUSEDOCUMENT_H
