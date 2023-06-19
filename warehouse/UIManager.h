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
	void ShowAll() {
		std::string IdWarehouse = "";
		std::cout << "podaj id magazynu " << std::endl;
		std::cin >> IdWarehouse;
		auto Products = _ProductService.GetAllProducts(IdWarehouse);
		PrintProductRowTitle();
		for (auto prod : Products) {
			PrintProduct(prod);
		}
	};
	void ShowById() {
		std::string IdWarehouse = "";
		std::cout << "podaj id magazynu " << std::endl;
		std::cin >> IdWarehouse;
		std::string IdProduct = "";
		std::cout << "podaj id produktu " << std::endl;
		std::cin >> IdProduct;

		auto Product = _ProductService.GetProductById(IdWarehouse, IdProduct);
		PrintProductRowTitle();
		PrintProduct(Product);
	};
	void AddNew() {
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
		
		_ProductService.CreateProduct(product);
	};

private:
	IWarehouseProductService _ProductService;
	void PrintProduct(std::shared_ptr<ProductDto> Product) {
		std::cout << Product->ProductId << "	" << Product->Name << "	" << std::endl;
	};
	void PrintProductRowTitle() {
		std::cout << "Id	" << "Nazwa	" << std::endl;
	};
};

class UIDocumentManager :public UIManager
{
public:
	void ShowAll() {
		std::string IdWarehouse = "";
		std::cout << "podaj id magazynu " << std::endl;
		std::cin >> IdWarehouse;
		auto documentReception = _DocumentService.GetAllWarehouseDocumentReceptionsDocuements(IdWarehouse);
		auto documentRelease = _DocumentService.GetAllWarehouseDocumentReleasesDocuements(IdWarehouse);
		printDocumentRowTitle();
		for (auto doc : documentReception) {
			printDocumentReception(doc);
		};
		
		for (auto doc : documentRelease) {
			printDocumentRelease(doc);
		};
		
	};
	void ShowById() {
		std::string IdWarehouse = "";
		std::cout << "podaj id magazynu " << std::endl;
		std::cin >> IdWarehouse;
		
		std::cout << "podaj typ dokumentu\n ";
		std::cout << "1 - dokumenty WZ\n" ;
		std::cout << "2 - dokumenty PZ\n" ;
		std::string typ;
		std::cin >> typ;

		std::cout << "podaj id dokumentu\n ";
		std::string idDoc;
		std::cin >> idDoc;

		if (typ == "1") {
			auto documentReleaseId = _DocumentService.GetWarehosueDocumentReleaseById(IdWarehouse, idDoc);
			printDocumentRowTitle();
			printDocumentRelease(documentReleaseId);
		 }
		if (typ == "2"){
			auto documentReceptionId = _DocumentService.GetWarehosueDocumentReceptionById(IdWarehouse, idDoc);
			printDocumentRowTitle();
			printDocumentReception(documentReceptionId);
		}

	};
	void AddNew() {
		/*auto document = WarehouseDocumentDto();*/
		auto warehouseReleaseDto = WarehouseReleseDocumentDto();
		warehouseReleaseDto.DocumentName = "release";
		std::string productId = "";
		std::string warehouseId = "";
		auto documentService = IWarehouseDocumentService();
		auto productService = IWarehouseProductService();
		

		//std::cout << "podaj nazwe dokumentu " << std::endl;
		//std::cin >> warehouseReleaseDto.DocumentName;
		std::cout << "podaj id dokumentu " << std::endl;
		std::cin >> warehouseReleaseDto.DocumentIdGuid;
		std::cout << "podaj id magazynu " << std::endl;
		std::cin >> warehouseReleaseDto.WarehouseIdGuid;
		std::cout << "podaj imie klienta " << std::endl;
		std::cin >> warehouseReleaseDto.ClientName;
		std::cout << "podaj id produktu " << std::endl;
		std::cin >> productId;
		warehouseId = warehouseReleaseDto.WarehouseIdGuid;

		auto productDto = productService.GetProductById(warehouseId, productId);
		auto receptionDto = WarehouseReceptionDocumentDto();
		receptionDto.Products.push_back(*productDto);
		
		std::cout << "podaj imie pracownika " << std::endl;
		std::cin >> warehouseReleaseDto.AssignedEmployeeName;

		_DocumentService.CreateWarehouseDocument(warehouseReleaseDto);
	};

private:
	IWarehouseDocumentService _DocumentService;
	void printDocumentReception(std::shared_ptr <WarehouseDocumentDto> Document) {
		std::cout << Document->DocumentIdGuid << "	" << Document->DocumentName << std::endl;
	}
	void printDocumentRelease(std::shared_ptr <WarehouseDocumentDto> Document) {
		std::cout << Document->DocumentIdGuid << "	" << Document->DocumentName << std::endl;
	}
	void printDocumentRowTitle() {
		std::cout << "Id	" << "Nazwa	" << std::endl;
	}
};

class UILocationManager :public UIManager
{
public:
	void ShowAll() {
		std::string IdWarehouse = "";
		std::cout << "podaj id magazynu " << std::endl;
		std::cin >> IdWarehouse;
		auto locations = _LocationService.GetAllWarehouseLocation(IdWarehouse);
		PrintLocationRowTitle();
		for (auto loc : locations) {
			PrintLocation(loc);
		}
	};
	void ShowById() {
		std::string IdWarehouse = "";
		std::cout << "podaj id magazynu " << std::endl;
		std::cin >> IdWarehouse;
		std::string IDlocation = "";
		std::cout << "podaj id lokazlizacji " << std::endl;
		std::cin >> IDlocation;

		auto location = _LocationService.GetWarahouseLocationById(IdWarehouse, IDlocation);
		PrintLocationRowTitle();
		PrintLocation(location);
	};

	void AddNew() {
		auto location = WarehouseLocationDto();

		std::cout << "podaj id magazynu " << std::endl;
		std::cin >> location.WarehouseId;
		std::cout << "podaj nazwe lokalizacji " << std::endl;
		std::cin >> location.WarehouseLocationName;
		std::cout << "podaj sposob magazynowania " << std::endl;
		std::cin >> location.StorageMethod;
		std::cout << "podaj wysokosc " << std::endl;
		std::cin >> location.Height;
		std::cout << "podaj glebokosc " << std::endl;
		std::cin >> location.Depth;
		std::cout << "podaj dlugosc " << std::endl;
		std::cin >> location.Width;

		std::string warehouseId = location.WarehouseId;
		_LocationService.CreateWarehouseLocation(location);
	};

private:
	IWarehouseLocationService _LocationService;
	void PrintLocation(std::shared_ptr<WarehouseLocationDto> location) {
		std::cout << location->WarehouseLocationName << "	" << location->StorageMethod << std::endl;
	};
	void PrintLocationRowTitle() {
		std::cout << "nazwa lokalizacji		" << "Metoda skladowania	" << std::endl;
	};
};