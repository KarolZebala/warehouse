#include "UIDocumentManager.h"



UIDocumentManager::UIDocumentManager()
{
	_documentRepository = std::make_shared<WarehouseDocumentRepository>(WarehouseDocumentRepository());
	_locationRepository = std::make_shared<WarehouseLocationRepository>(WarehouseLocationRepository());
	_productRepository = std::make_shared<ProuductRepository>(ProuductRepository());
}

void UIDocumentManager::ShowAll() {
	std::string IdWarehouse = "";
	std::cout << "podaj id magazynu " << std::endl;
	std::cin >> IdWarehouse;
	try
	{
		auto documentReception = _documentRepository->getAllReceptions(IdWarehouse);
		auto documentRelease = _documentRepository->getAllReleases(IdWarehouse);
		printDocumentRowTitle();
		for (auto doc : documentReception) {
			printDocument(doc);
		};

		for (auto doc : documentRelease) {
			printDocument(doc);
		};
	}
	catch (const std::exception& e)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
		std::cout << e.what() << std::endl;
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
			auto documentRelease = _documentRepository->getReleaseById(idDoc, IdWarehouse);
			printDocumentRowTitle();
			printDocument(documentRelease);
		}
		if (typ == "2") {
			auto documentReception = _documentRepository->getRecepitonById(idDoc, IdWarehouse);
			printDocumentRowTitle();
			printDocument(documentReception);
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
		std::cout << e.what() << std::endl;
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
				auto location = _locationRepository->getById(locationIdGuid, warehouseId);
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
				auto location = _locationRepository->getById(locationIdGuid, warehouseId);
				auto locationProduct = location->RemoveProduct(productToAddPtr);
				_locationRepository->removeLocationProduct(locationProduct->getProductId(), locationProduct->getLocationId());
			}

			_documentRepository->addRelease(documentPtr);
		}
		else {
			std::cout<<"Nie ma takiej opcji" << std::endl;
		}
	}
	catch (const std::exception& e)
	{
		std::cout << "Operacja siê nie powiod³a " << std::endl;
		std::cout << e.what() << std::endl;
	}

	
};

void UIDocumentManager::printDocument(std::shared_ptr <WarehouseDocument> Document) {
	std::cout << Document->getDocuemntId() << "	" << Document->getName() << std::endl;
}

void UIDocumentManager::printDocumentRowTitle() {
	std::cout << "Id	" << "Nazwa	" << std::endl;
}
