#include <iostream>
#include "WarehouseApp.h"
#include "WarehosueDto.h"

int main() {
	//aplication start

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
			auto warehosueDto = new WarehosueDto();
			std::cout << "Podaj imie";
			std::cin >> warehosueDto->Name;

			auto id = warehosueApp->CreateWarehouse(warehosueDto);
			std::cout << "dzia³a z id: " << id << std::endl;
		}
		if (userInput == "2") {
			auto results = warehosueApp->GetAll();
			std::cout << "Pddasfa";

		}if (userInput == "2") {
			//auto results = warehosueApp->();
			std::cout << "Pddasfa";

		}
	}
	return 1;
}

