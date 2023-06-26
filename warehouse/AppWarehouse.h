#pragma once
#include <iostream>
#include "UIManager.h"
#include "SeedingService.h"
#include "UIProductManager.h"
#include "UIDocumentManager.h"
#include "UILocationManager.h"
/**!
 * \brief AppWarehouse klasa zarz�dzaj�ca UI aplikacji
 */
class AppWarehouse 
{
public:
    /**
    * Konstruktor klasy AppWarehouse
    */
	AppWarehouse();
	/**
	* Funkcja odpowiada za wy�wietlenie g��wnego menu
	*/
	void Start();

private:
	std::shared_ptr<ISeedingService> _seedingService;
	/**
	* Funkcja zainicjalizowanie tabel w bazie
	*/
	void SetUpDateBase();
	/**
	* Funkcja odpowiada za wy�wietlenie menu produkt�w
 	*/
	void ManageProduct();
	/**
	* Funkcja odpowiada za wy�wietlenie menu dokument�w
	*/
	void ManageDocument();
	/**
	* Funkcja odpowiada za wy�wietlenie menu lokalizacji
	*/
	void ManageLocation();
};
