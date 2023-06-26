#pragma once
#include "UIManager.h"
/**!
 * \brief UIDocumentManager klasa zarządzająca UI dokumentów
 */
class UIDocumentManager :public IUIManager
{
public:
	/**
	* Konstruktor klasy UIDocumentManager
	*/
	UIDocumentManager();
	/**
	* Funkcja odpowiada za wyświetlenie wszystkich dokumentów w UI
	*/
	void ShowAll();
	/**
	* Funkcja odpowiada za wyświetlenie dokumnetu w UI
	*/
	void ShowById();
	/**
	* Funkcja odpowiada za pobranie parametrów od urzytkownika i utworzenie dokumnetu 
	*/
	void AddNew();

private:
	std::shared_ptr<IProuductRepository> _productRepository;
	std::shared_ptr<IWarehouseDocumentRepository> _documentRepository;
	std::shared_ptr<IWarehouseLocationRepository> _locationRepository;
	/**
	* Funkcja wyświetla wiersz danymi konkretnego dokumentu
	*/
	void printDocument(std::shared_ptr <WarehouseDocument> Document);
	/**
	* Funkcja wyświetla wiersz z nazwmi kolumn
	*/
	void printDocumentRowTitle();
};


