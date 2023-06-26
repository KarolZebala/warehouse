#pragma once
#include "UIManager.h"
/**!
 * \brief UIDocumentManager klasa zarz�dzaj�ca UI dokument�w
 */
class UIDocumentManager :public IUIManager
{
public:
	/**
	* Konstruktor klasy UIDocumentManager
	*/
	UIDocumentManager();
	/**
	* Funkcja odpowiada za wy�wietlenie wszystkich dokument�w w UI
	*/
	void ShowAll();
	/**
	* Funkcja odpowiada za wy�wietlenie dokumnetu w UI
	*/
	void ShowById();
	/**
	* Funkcja odpowiada za pobranie parametr�w od urzytkownika i utworzenie dokumnetu 
	*/
	void AddNew();

private:
	std::shared_ptr<IProuductRepository> _productRepository;
	std::shared_ptr<IWarehouseDocumentRepository> _documentRepository;
	std::shared_ptr<IWarehouseLocationRepository> _locationRepository;
	/**
	* Funkcja wy�wietla wiersz danymi konkretnego dokumentu
	*/
	void printDocument(std::shared_ptr <WarehouseDocument> Document);
	/**
	* Funkcja wy�wietla wiersz z nazwmi kolumn
	*/
	void printDocumentRowTitle();
};


