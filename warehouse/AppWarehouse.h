#pragma once
#include <iostream>
#include "UIManager.h"
#include "SeedingService.h"
#include "UIProductManager.h"
#include "UIDocumentManager.h"
#include "UILocationManager.h"
/**!
 * \brief AppWarehouse klasa zarządzająca UI aplikacji
 */
class AppWarehouse 
{
public:
    /**
    * Konstruktor klasy AppWarehouse
    */
	AppWarehouse();
	/**
	* Funkcja odpowiada za wyświetlenie głównego menu
	*/
	void Start();

private:
	std::shared_ptr<ISeedingService> _seedingService;
	/**
	* Funkcja zainicjalizowanie tabel w bazie
	*/
	void SetUpDateBase();
	/**
	* Funkcja odpowiada za wyświetlenie menu produktów
 	*/
	void ManageProduct();
	/**
	* Funkcja odpowiada za wyświetlenie menu dokumentów
	*/
	void ManageDocument();
	/**
	* Funkcja odpowiada za wyświetlenie menu lokalizacji
	*/
	void ManageLocation();
};
