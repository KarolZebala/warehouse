#include <iostream>
#include "WarehouseApp.h"
#include "WarehouseDto.h"
#include "WarehouseProductService.h"
#include <sqlite3.h>
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

		if (userInput == "1") {
			auto warehouseDto = new WarehouseDto();
			std::cout << "Podaj imie";
			std::cin >> warehouseDto->Name;

			auto id = warehosueApp->CreateWarehouse(warehouseDto);
			std::cout << "dzia³a z id: " << id << std::endl;
		}
		if (userInput == "2") {
			std::cout << "Pddasfa";

		}if (userInput == "2") {
			//auto results = warehosueApp->();
			std::cout << "Pddasfa";

		}
		if (userInput == "3") {
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
	}
	return 1;
}

