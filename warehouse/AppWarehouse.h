#pragma once
#include <iostream>
#include "UIManager.h"
#include "SeedingService.h"
#include "UIProductManager.h"
#include "UIDocumentManager.h"
#include "UILocationManager.h"
/**!
 * \brief AppWarehouse klasa zarz¹dzaj¹ca UI aplikacji
 */
class AppWarehouse 
{
public:
    /**
    * Konstruktor klasy AppWarehouse
    */
	AppWarehouse();
	/**
	* Funkcja odpowiada za wyœwietlenie g³ównego menu
	*/
	void Start();

private:
	std::shared_ptr<ISeedingService> _seedingService;
	/**
	* Funkcja zainicjalizowanie tabel w bazie
	*/
	void SetUpDateBase();
	/**
	* Funkcja odpowiada za wyœwietlenie menu produktów
 	*/
	void ManageProduct();
	/**
	* Funkcja odpowiada za wyœwietlenie menu dokumentów
	*/
	void ManageDocument();
	/**
	* Funkcja odpowiada za wyœwietlenie menu lokalizacji
	*/
	void ManageLocation();
};
