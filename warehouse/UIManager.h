#pragma once
#include <iostream>
#include <string>
#include "WarehouseProductService.h"
#include "WarehouseDocumentService.h"
#include "WarehouseLocationService.h"

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
		_ProductService = std::make_shared <WarehouseProductService>(WarehouseProductService());
	}
	void ShowAll();
	void ShowById();
	void AddNew();
	void ShowByName();

private:
	std::shared_ptr<IWarehouseProductService> _ProductService;
	void PrintProduct(std::shared_ptr<ProductDto> Product);
	void PrintProductRowTitle();
};

class UIDocumentManager :public UIManager
{
public:
	UIDocumentManager() {
		_DocumentService = std::make_shared<WarehouseDocumentService>(WarehouseDocumentService());
		_ProductService = std::make_shared<WarehouseProductService>(WarehouseProductService());
	}
	void ShowAll();
	void ShowById();
	void AddNew();

private:
	std::shared_ptr<IWarehouseDocumentService> _DocumentService;
	std::shared_ptr<IWarehouseProductService> _ProductService;
	void printDocumentReception(std::shared_ptr <WarehouseDocumentDto> Document);
	void printDocumentRelease(std::shared_ptr <WarehouseDocumentDto> Document);
	void printDocumentRowTitle();
};

class UILocationManager :public UIManager
{
public:
	UILocationManager() {
		_LocationService=std::make_shared <WarehouseLocationService>(WarehouseLocationService());
	}
	void ShowAll();
	void ShowById();

	void AddNew();

private:
	std::shared_ptr <IWarehouseLocationService> _LocationService;
	void PrintLocation(std::shared_ptr<WarehouseLocationDto> location);
	void PrintLocationRowTitle();
};