#include "UIManager.h"
#pragma once
#include <iostream>
#include <string>


void UIProductManager::ShowAll() {
	std::string IdWarehouse = "";
	std::cout << "podaj id magazynu " << std::endl;
	std::cin >> IdWarehouse;
	try
	{
		auto Products = _productRepository->getAllProducts(IdWarehouse);
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
		auto Product = _productRepository->getProductById(IdWarehouse, IdProduct);
		PrintProductRowTitle();
		PrintProduct(Product);
	}
	catch (const std::exception&)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
	}
};

void UIProductManager::ShowByName() {
	
	try
	{
		std::string name = "";
		std::cout << "podaj nazwe " << std::endl;
		std::cin >> name;
		auto product = _productRepository->GetProductByName(name);
		PrintProductRowTitle();
		PrintProduct(product);
	}
	catch (const std::exception&)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
	}
}

void UIProductManager::AddNew() {
	std::string name;
	std::cout << "podaj nazwe produktu " << std::endl;
	std::cin >> name;
	std::string storageMethod;
	std::cout << "podaj metode skladowania " << std::endl;
	std::cin >> storageMethod;
	std::string condition;
	std::cout << "podaj warunki skladowania " << std::endl;
	std::cin >> condition;
	std::string coments;
	std::cout << "komentarze " << std::endl;
	std::cin >> coments;
	int price = 0;
	std::cout << "podaj cene produktu " << std::endl;
	std::cin >> price;
	int quantity = 0;
	std::cout << "podaj ilosc produktu " << std::endl;
	std::cin >> quantity;
	int xDimension = 0;
	std::cout << "podaj wymiar X " << std::endl;
	std::cin >> xDimension;
	int zDimension = 0;
	std::cout << "podaj wymiar Z " << std::endl;
	std::cin >> zDimension;
	int yDimension = 0;
	std::cout << "podaj wymiar Y " << std::endl;
	std::cin >> yDimension;
	std::string warehouseId;
	std::cout << "podaj id magzynu " << std::endl;
	std::cin >> warehouseId;

	try
	{
		auto productToAdd = Product(
			name,
			condition,
			coments,
			storageMethod,
			price,
			quantity,
			xDimension,
			yDimension,
			zDimension,
			warehouseId
		);
		auto productToAddPtr = std::make_shared<Product>(productToAdd);
		_productRepository->addProduct(productToAddPtr);
	}
	catch (const std::exception&)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
	}
};

void UIProductManager::PrintProduct(std::shared_ptr<Product> Product) {
	std::cout << Product->getProductId() << "	" << Product->getName() << "	" << std::endl;
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
		auto documentReception = _documentRepository->getAllReceptions();
		auto documentRelease = _documentRepository->getAllReleases();
		printDocumentRowTitle();
		for (auto doc : documentReception) {
			printDocument(doc);
		};

		for (auto doc : documentRelease) {
			printDocument(doc);
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
			auto documentRelease = _documentRepository->getReleaseById(idDoc);
			printDocumentRowTitle();
			printDocument(documentRelease);
		}
		if (typ == "2") {
			auto documentReception = _documentRepository->getRecepitonById(idDoc);
			printDocumentRowTitle();
			printDocument(documentReception);
		}
	}
	catch (const std::exception&)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
	}

};
void UIDocumentManager::AddNew() {
	try
	{
		std::string userInput = "";

		std::cout << "Wybierz jaki dokument chcesz stworzyæ: " << std::endl;
		std::cout << "1 Przyjecie " << std::endl;
		std::cout << "2 Wydanie " << std::endl;
		std::cin >> userInput;

		std::string productId = "";
		std::string warehouseId = "";

		if (userInput == "1") {
			std::string documentName = "";
			std::cout << "podaj nazwe dokumentu " << std::endl;
			std::cin >> documentName;
			std::string warehouseId = "";
			std::cout << "podaj id magazynu " << std::endl;
			std::cin >> warehouseId;
			std::string clientName = "";
			std::cout << "podaj imie klienta " << std::endl;
			std::cin >> clientName;
			std::string employeeName;
			std::cout << "podaj imie pracownika " << std::endl;
			std::cin >> employeeName;
			
			auto document = WarehouseDocumentReception(
				documentName,
				warehouseId,
				clientName,
				employeeName
			);
			auto documentPtr = std::make_shared<WarehouseDocumentReception>(document);
			std::cout << "Podaj id produktów aby skoñczyæ wciœnij 0 " << std::endl;
			while (true) {

				std::cout << "podaj id produktu " << std::endl;
				std::cin >> productId;
				if (productId == "0") {
					break;
				}
				auto product = _productRepository->getProductById(warehouseId, productId);
				std::string locationIdGuid = "";
				std::cout << "podaj id lokalizacji magazynowej" << std::endl;
				std::cin >> locationIdGuid;
				auto productToAdd = DocumentProduct(
					product->getProductId(),
					product->getName(),
					product->getPrice(),
					product->getVolume(),
					product->getStorageMethod(),
					documentPtr->getDocuemntId()
				);
				auto productToAddPtr = std::make_shared<DocumentProduct>(productToAdd);
				documentPtr->addProductToDocument(productToAddPtr);
				auto location = _locationRepository->getById(locationIdGuid);
				auto locationProduct = location->AddProductFromDocument(productToAddPtr);
				_locationRepository->createLocationProduct(locationProduct);
			}
			_documentRepository->addRecepiton(documentPtr);
		}
		else if (userInput == "2") {

			std::string documentName = "";
			std::cout << "podaj nazwe dokumentu " << std::endl;
			std::cin >> documentName;
			std::string warehouseId = "";
			std::cout << "podaj id magazynu " << std::endl;
			std::cin >> warehouseId;
			std::string clientName = "";
			std::cout << "podaj imie klienta " << std::endl;
			std::cin >> clientName;
			std::string employeeName;
			std::cout << "podaj imie pracownika " << std::endl;
			std::cin >> employeeName;

			auto document = WarehouseDocumentRelease(
				documentName,
				warehouseId,
				clientName,
				employeeName
			);
			auto documentPtr = std::make_shared<WarehouseDocumentRelease>(document);

			std::cout << "Podaj id produktów aby skoñczyæ wciœnij 0 " << std::endl;
			while (true) {

				std::cout << "podaj id produktu " << std::endl;
				std::cin >> productId;
				if (productId == "0") {
					break;
				}
				auto product = _productRepository->getProductById(warehouseId, productId);
				std::string locationIdGuid = "";
				std::cout << "podaj id lokalizacji magazynowej" << std::endl;
				std::cin >> locationIdGuid;
				auto productToAdd = DocumentProduct(
					product->getProductId(),
					product->getName(),
					product->getPrice(),
					product->getVolume(),
					product->getStorageMethod(),
					documentPtr->getDocuemntId()
				);
				auto productToAddPtr = std::make_shared<DocumentProduct>(productToAdd);
				documentPtr->addProductToDocument(productToAddPtr);
				auto location = _locationRepository->getById(locationIdGuid);
				auto locationProduct = location->RemoveProduct(productToAddPtr);
				_locationRepository->removeLocationProduct(locationProduct->getProductId(), locationProduct->getLocationId());
			}

			_documentRepository->addRelease(documentPtr);
		}
		else {
			std::cout<<"Nie ma takiej opcji" << std::endl;
		}
	}
	catch (const std::exception&)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
	}

	
};

void UIDocumentManager::printDocument(std::shared_ptr <WarehouseDocument> Document) {
	std::cout << Document->getDocuemntId() << "	" << Document->getName() << std::endl;
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
		auto locations = _locationRepository->getAll();
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
		auto location = _locationRepository->getById(IDlocation);
		PrintLocationRowTitle();
		PrintLocation(location);
	}
	catch (const std::exception&)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
	}
};

void UILocationManager::AddNew() {
	std::string warehouseId = "";
	std::cout << "podaj id magazynu " << std::endl;
	std::cin >> warehouseId;
	std::string locationName = "";
	std::cout << "podaj nazwe lokalizacji " << std::endl;
	std::cin >> locationName;
	std::string storageMethod = "";
	std::cout << "podaj sposob magazynowania " << std::endl;
	std::cin >> storageMethod;
	int height = 0;
	std::cout << "podaj wysokosc " << std::endl;
	std::cin >> height;
	int depth = 0;
	std::cout << "podaj glebokosc " << std::endl;
	std::cin >> depth;
	int width = 0;
	std::cout << "podaj dlugosc " << std::endl;
	std::cin >> width;

	try
	{
		auto locationToAdd = WarehouseLocation(
			locationName,
			width,
			depth,
			height,
			storageMethod,
			warehouseId
		);
		auto locationPtr = std::make_shared<WarehouseLocation>(locationToAdd);
		_locationRepository->addLocatation(locationPtr);
	}
	catch (const std::exception&)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
	}
};

void UILocationManager::PrintLocation(std::shared_ptr<WarehouseLocation> location) {
	std::cout << location->getName() << "	" << location->getStorageMethod() << "	" << location->GetId() << std::endl;
};
void UILocationManager::PrintLocationRowTitle() {
	std::cout << "nazwa lokalizacji		" << "Metoda skladowania	" << "Id	" << std::endl;
};