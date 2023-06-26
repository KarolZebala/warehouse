#pragma once
#include <iostream>
#include <string>
#include "WarehouseProductService.h"
#include "WarehouseDocumentService.h"
#include "WarehouseLocationService.h"
#include "WarehouseLocationRepository.h"
#include "WarehouseDocumentRepository.h"

class UIManager
{
public:
	virtual void ShowAll() {};
	virtual void ShowById() {};
	virtual void AddNew() {};

};

class UIProductManager : public UIManager
{
public:
	UIProductManager() {
		_productRepository = std::make_shared<ProuductRepository>(ProuductRepository());
	}
	void ShowAll();
	void ShowById();
	void AddNew();
	void ShowByName();

private:
	std::shared_ptr<IProuductRepository> _productRepository;

	void PrintProduct(std::shared_ptr<Product> Product);
	void PrintProductRowTitle();
};

class UIDocumentManager :public UIManager
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

class UILocationManager :public UIManager
{
public:
	UILocationManager() {
		_locationRepository = std::make_shared<WarehouseLocationRepository>(WarehouseLocationRepository());

	}
	void ShowAll();
	void ShowById();

	void AddNew();

private:
	std::shared_ptr<IWarehouseLocationRepository> _locationRepository;
	void PrintLocation(std::shared_ptr<WarehouseLocation> location);
	void PrintLocationRowTitle();
};