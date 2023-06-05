#ifndef WAREHOUSEDOCUMENTRELEASE_H
#define WAREHOUSEDOCUMENTRELEASE_H

#include "WarehouseDocument.h"

class WarehouseDocumentRelease : public WarehouseDocument {
public:
    WarehouseDocumentRelease(const std::string documentName, std::string warehouseId, std::string docuemntId = "");
    void addProductToDocunent(DocumentProduct* product);
};

#endif // WAREHOUSEDOCUMENTRELEASE_H
