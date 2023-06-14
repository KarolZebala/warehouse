#include <iostream>
#include "WarehouseApp.h"
#include "WarehouseDto.h"
#include "WarehouseDocumentDto.h"
#include "WarehouseProductService.h"
#include <sqlite3.h>
#include "WarehouseDocumentService.h"
#include "WarehouseLocationService.h"
int main() {


	//Create warehosuse app 

	auto warehosueApp = new WarehouseApp();
	auto isProgramRunning = true;
	
	std::cout << std::time(0);

	while (true) {
		std::cout<< "Podaj co chcesz zrobiæ: \n";
		std::cout << "1. opcja pierwsza\n";
		std::cout << "2. opcja druga\n";
		std::cout << "3. opcja trzecia\n";
		std::cout << "4. opcja czwarta\n";
		std::cout << "5. opcja pi¹ta\n";

		std::string userInput;
		std::cin >> userInput;

		//if (userInput == "1") {
		//	auto warehouseDto = new WarehouseDto();
		//	std::cout << "Podaj imie";
		//	std::cin >> warehouseDto->Name;

		//	auto id = warehosueApp->CreateWarehouse(warehouseDto);
		//	std::cout << "dzia³a z id: " << id << std::endl;
		//}
		//if (userInput == "2") {
		//	std::cout << "Pddasfa";

	//if (userInput == "2") {
	//	//auto results = warehosueApp->();
	//	auto ser = WarehouseService();
	//	auto res = ser.GetAllWarehouses();
	//}
		//}
		//if (userInput == "3") {
		//	auto service = new WarehouseProductService();
		//	auto productdto =  ProductDto();
		//	productdto.Name = "test1";
		//	productdto.Price = 1;
		//	std::cout << "Podaj id magazynu";
		//	std::cin >> productdto.WarehouseIdGuid;
		//	productdto.XDimension = 2;
		//	productdto.YDimension = 3;
		//	productdto.ZDimension = 4;
		//	productdto.Quantity = 5;
		//	productdto.StorageMethod = "FIFO";
		//	service->CreateProduct(productdto);

		//}
		//if (userInput == "4") {
		//	auto service = new WarehouseProductService();
		//	auto res = service->GetAllProducts("42e3fb-8b50-4792-a101-3e0d45ce3667");

		//}
		//if (userInput == "5") {
		//	auto service = new WarehouseProductService();
		//	service->GetProductById("42e3fb-8b50-4792-a101-3e0d45ce3667","6fdc7026-0830-4da3-9356-4999561d6f33");
		//}


		if (userInput == "1") {
			
			auto warehouserecDto = WarehouseReceptionDocumentDto("reception");
			auto product = ProductDto();
			product.Name = "test1";
			product.XDimension = 1;
			product.YDimension = 1;
			product.ZDimension = 1;
			product.StorageMethod = "FIFO";

			
			std::cout << "dzia³\n";

			auto warehouserreleaseDto = WarehouseReleseDocumentDto("release");
			/*auto product = ProductDto();
			product.Name = "test1";
			product.XDimension = 1;
			product.YDimension = 1;
			product.ZDimension = 1;
			product.StorageMethod = "FIFO";*/

			IWarehouseDocumentService service = WarehouseDocumentService();
			service.CreateWarehouseDocument(warehouserecDto);
			service.CreateWarehouseDocument(warehouserreleaseDto);
			std::cout << "dzia³\n";
		}
		if (userInput == "2") {
			auto locationService = WarehouseLocationService();
			auto location = WarehouseLocationDto();
			location.WarehouseLocationName = "test lok";
			location.Width = 10;
			location.Depth = 10;
			location.Height = 10;
			location.StorageMethod = "FIFO";
			locationService.CreateWarehouseLocation(location);
			std::cout << "dzia³\n";


		}if (userInput == "3") {
			auto locationService = WarehouseLocationService();
			auto res = locationService.GetAllWarehouseLocation("");
			std::cout << "dzia³\n";

		}
		if (userInput == "4") {
			auto service = new WarehouseProductService();
			auto productdto =  ProductDto();
			productdto.Name = "test1";
			productdto.Price = 1;
			std::cout << "Podaj id magazynu";
			std::cin >> productdto.WarehouseIdGuid;
			productdto.XDimension = 2;
			productdto.YDimension = 3;
			productdto.ZDimension = 4;
			productdto.Quantity = 5;
			productdto.StorageMethod = "FIFO";
			service->CreateProduct(productdto);

		}
		if (userInput == "4") {
			auto service = new WarehouseProductService();
			auto res = service->GetAllProducts("42e3fb-8b50-4792-a101-3e0d45ce3667");

		}
		if (userInput == "5") {
			auto service = new WarehouseProductService();
			service->GetProductById("42e3fb-8b50-4792-a101-3e0d45ce3667","6fdc7026-0830-4da3-9356-4999561d6f33");
		}
		if (userInput == "6") {
			auto service = new WarehouseDocumentService();
		}
	}
	return 1;
}

