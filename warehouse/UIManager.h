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
	void ShowAll(); /*{
		std::string IdWarehouse = "";
		std::cout << "podaj id magazynu " << std::endl;
		std::cin >> IdWarehouse;
		try
		{
			auto Products = _ProductService->GetAllProducts(IdWarehouse);
			PrintProductRowTitle();
			for (auto prod : Products) {
				PrintProduct(prod);
			}
		}
		catch (const std::exception&)
		{
			std::cout << "Operacja siê nie powiod³a " << std::endl;
		}
	};*/
	void ShowById(); /*{
		std::string IdWarehouse = "";
		std::cout << "podaj id magazynu " << std::endl;
		std::cin >> IdWarehouse;
		std::string IdProduct = "";
		std::cout << "podaj id produktu " << std::endl;
		std::cin >> IdProduct;

		try
		{
			auto Product = _ProductService->GetProductById(IdWarehouse, IdProduct);
			PrintProductRowTitle();
			PrintProduct(Product);
		}
		catch(const std::exception&)
		{
			std::cout << "Operacja siê nie powiod³a " << std::endl;
		}
	};*/
	void AddNew(); /*{
		auto product = ProductDto();
		std::cout << "podaj nazwe produktu " << std::endl;
		std::cin >> product.Name;
		std::cout << "podaj metode skladowania " << std::endl;
		std::cin >> product.StorageMethod;
		std::cout << "podaj warunki skladowania " << std::endl;
		std::cin >> product.Condition;
		std::cout << "komentarze " << std::endl;
		std::cin >> product.Coments;
		std::cout << "podaj cene produktu " << std::endl;
		std::cin >> product.Price;
		std::cout << "podaj ilosc produktu " << std::endl;
		std::cin >> product.Quantity;
		std::cout << "podaj ojetosc produktu " << std::endl;
		std::cin >> product.Volume;
		std::cout << "podaj wymiar X " << std::endl;
		std::cin >> product.XDimension;
		std::cout << "podaj wymiar Z " << std::endl;
		std::cin >> product.ZDimension;
		std::cout << "podaj wymiar Y " << std::endl;
		std::cin >> product.YDimension;
		std::cout << "podaj id magzynu " << std::endl;
		std::cin >> product.WarehouseIdGuid;
		
		try
		{
			_ProductService->CreateProduct(product);
		}
		catch (const std::exception&)
		{
			std::cout << "Operacja siê nie powiod³a " << std::endl;
		}
	};*/

private:
	std::shared_ptr <IWarehouseProductService> _ProductService;
	void PrintProduct(std::shared_ptr<ProductDto> Product); /*{
		std::cout << Product->ProductId << "	" << Product->Name << "	" << std::endl;
	};*/
	void PrintProductRowTitle(); /*{
		std::cout << "Id	" << "Nazwa	" << std::endl;
	};*/
};

class UIDocumentManager :public UIManager
{
public:
	UIDocumentManager() {
		_DocumentService = std::make_shared <WarehouseDocumentService>(WarehouseDocumentService());
	}
	void ShowAll();
	void ShowById();
	void AddNew();

private:
	std::shared_ptr <IWarehouseDocumentService> _DocumentService;
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