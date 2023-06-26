#pragma once
#include "UIManager.h"
class UIDocumentManager :public IUIManager
{
public:
	UIDocumentManager() {
		_documentRepository = std::make_shared<WarehouseDocumentRepository>(WarehouseDocumentRepository());
		_locationRepository = std::make_shared<WarehouseLocationRepository>(WarehouseLocationRepository());
		_productRepository = std::make_shared<ProuductRepository>(ProuductRepository());
	}
	void ShowAll();
	void ShowById();
	void AddNew();

private:
	std::shared_ptr<IProuductRepository> _productRepository;
	std::shared_ptr<IWarehouseDocumentRepository> _documentRepository;
	std::shared_ptr<IWarehouseLocationRepository> _locationRepository;
	
	void printDocument(std::shared_ptr <WarehouseDocument> Document);
	void printDocumentRowTitle();
};


