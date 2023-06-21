#include "UIManager.h"
#pragma once
#include <iostream>
#include <string>
#include "WarehouseProductService.h"
#include "WarehouseDocumentService.h"
#include "WarehouseLocationService.h"


void UIProductManager::ShowAll() {
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
};

void UIProductManager::ShowById() {
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
	catch (const std::exception&)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
	}
};

void UIProductManager::AddNew() {
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
};

void UIProductManager::PrintProduct(std::shared_ptr<ProductDto> Product) {
	std::cout << Product->ProductId << "	" << Product->Name << "	" << std::endl;
};

void UIProductManager::PrintProductRowTitle() {
	std::cout << "Id	" << "Nazwa	" << std::endl;
};

void UIDocumentManager::ShowAll() {
	std::string IdWarehouse = "";
	std::cout << "podaj id magazynu " << std::endl;
	std::cin >> IdWarehouse;
	try
	{
		auto documentReception = _DocumentService->GetAllWarehouseDocumentReceptionsDocuements(IdWarehouse);
		auto documentRelease = _DocumentService->GetAllWarehouseDocumentReleasesDocuements(IdWarehouse);
		printDocumentRowTitle();
		for (auto doc : documentReception) {
			printDocumentReception(doc);
		};

		for (auto doc : documentRelease) {
			printDocumentRelease(doc);
		};
	}
	catch (const std::exception&)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
	}

};
void UIDocumentManager::ShowById() {
	std::string IdWarehouse = "";
	std::cout << "podaj id magazynu " << std::endl;
	std::cin >> IdWarehouse;

	std::cout << "podaj typ dokumentu\n ";
	std::cout << "1 - dokumenty WZ\n";
	std::cout << "2 - dokumenty PZ\n";
	std::string typ;
	std::cin >> typ;

	std::cout << "podaj id dokumentu\n ";
	std::string idDoc;
	std::cin >> idDoc;

	try
	{
		if (typ == "1") {
			auto documentReleaseId = _DocumentService->GetWarehosueDocumentReleaseById(IdWarehouse, idDoc);
			printDocumentRowTitle();
			printDocumentRelease(documentReleaseId);
		}
		if (typ == "2") {
			auto documentReceptionId = _DocumentService->GetWarehosueDocumentReceptionById(IdWarehouse, idDoc);
			printDocumentRowTitle();
			printDocumentReception(documentReceptionId);
		}
	}
	catch (const std::exception&)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
	}

};
void UIDocumentManager::AddNew() {
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

	try
	{
		auto productDto = productService.GetProductById(warehouseId, productId);
		auto receptionDto = WarehouseReceptionDocumentDto();
		receptionDto.Products.push_back(*productDto);
	}
	catch (const std::exception&)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
	}

	std::cout << "podaj imie pracownika " << std::endl;
	std::cin >> warehouseReleaseDto.AssignedEmployeeName;

	_DocumentService->CreateWarehouseDocument(warehouseReleaseDto);
};

void UIDocumentManager::printDocumentReception(std::shared_ptr <WarehouseDocumentDto> Document) {
	std::cout << Document->DocumentIdGuid << "	" << Document->DocumentName << std::endl;
}
void UIDocumentManager::printDocumentRelease(std::shared_ptr <WarehouseDocumentDto> Document) {
	std::cout << Document->DocumentIdGuid << "	" << Document->DocumentName << std::endl;
}
void UIDocumentManager::printDocumentRowTitle() {
	std::cout << "Id	" << "Nazwa	" << std::endl;
}

void UILocationManager::ShowAll() {
	std::string IdWarehouse = "";
	std::cout << "podaj id magazynu " << std::endl;
	std::cin >> IdWarehouse;

	try
	{
		auto locations = _LocationService->GetAllWarehouseLocation(IdWarehouse);
		PrintLocationRowTitle();
		for (auto loc : locations) {
			PrintLocation(loc);
		}
	}
	catch (const std::exception&)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
	}
};
void UILocationManager::ShowById() {
	std::string IdWarehouse = "";
	std::cout << "podaj id magazynu " << std::endl;
	std::cin >> IdWarehouse;
	std::string IDlocation = "";
	std::cout << "podaj id lokazlizacji " << std::endl;
	std::cin >> IDlocation;

	try
	{
		auto location = _LocationService->GetWarahouseLocationById(IdWarehouse, IDlocation);
		PrintLocationRowTitle();
		PrintLocation(location);
	}
	catch (const std::exception&)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
	}
};

void UILocationManager::AddNew() {
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

	try
	{
		std::string warehouseId = location.WarehouseId;
		_LocationService->CreateWarehouseLocation(location);
	}
	catch (const std::exception&)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
	}
};

void UILocationManager::PrintLocation(std::shared_ptr<WarehouseLocationDto> location) {
	std::cout << location->WarehouseLocationName << "	" << location->StorageMethod << std::endl;
};
void UILocationManager::PrintLocationRowTitle() {
	std::cout << "nazwa lokalizacji		" << "Metoda skladowania	" << std::endl;
};