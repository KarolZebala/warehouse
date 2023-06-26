#pragma once
#include "UIManager.h"
/**!
 * \brief UIProductManager klasa zarz¹dzaj¹ca UI produktów
 */
class UIProductManager : public IUIManager
{
public:
	/**
	* Konstruktor klasy UIProductManager
	*/
	UIProductManager();
	/**
	* Funkcja odpowiada za wyœwietlenie wszystkich produktów w UI
	*/
	void ShowAll();
	/**
	* Funkcja odpowiada za wyœwietlenie produktu w UI
	*/
	void ShowById();
	/**
	* Funkcja odpowiada za pobranie parametrów od urzytkownika i utworzenie produktu
	*/
	void AddNew();
	/**
	* Funkcja odpowiada za wyœwietlenie produktu w UI na podstawie nazwy
	*/
	void ShowByName();

private:
	std::shared_ptr<IProuductRepository> _productRepository;
	/**
	* Funkcja wyœwietla wiersz danymi konkretnego produktu
	*/
	void PrintProduct(std::shared_ptr<Product> Product);
	/**
	* Funkcja wyœwietla wiersz z nazwmi kolumn
	*/
	void PrintProductRowTitle();
};


