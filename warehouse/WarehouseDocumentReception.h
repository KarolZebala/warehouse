#ifndef WAREHOUSEDOCUMENTRECEPTION_H
#define WAREHOUSEDOCUMENTRECEPTION_H

#include "WarehouseDocument.h"
#include<vector>
#include<ctime>
/**!
 * \brief Klasa WarehouseDocumentReception reprezentuje przyjecia magazynowe
 * 
 * Jest to dokument ktory potwierdza przyjecie towaru i umieszczenie go w danej lokalizajci
 */
class WarehouseDocumentReception : public WarehouseDocument {
public:
	/**
	* Konstruktor klasy WarehouseDocumentReception
	*
	* \param documentName nazwa dokument
	* \param warehosueId id magazynu
	* \param clientName  klient od ktorego pochodzi towar przyjmowany 
	* \param employeeName pracownik odpowiedzialny za dokument
	*/
	explicit WarehouseDocumentReception(std::string name, std::string warehosueId, std::string clientName, std::string employeeName, std::string documentId = "");
	/**
	* Funckcja dodaje do przyjecia magazynowego produkt
	*
	* \param product  produkt do dodania
	*/
	void addProductToDocument(std::shared_ptr<DocumentProduct> product);
	/**
	* Funckcja zwraca wszystkie produkty które s¹ na dokumencie
	*
	*/
	std::vector<std::shared_ptr<DocumentProduct>> getAllReceptionProduct();

	std::time_t getCreateDate();
	std::time_t getIssueDate();
	std::string getClientName();
	std::string getEmployeeName();

private:
	std::time_t CreateDate;
	std::time_t IssueDate;
	std::string ClientName;
	std::string EmployeeName;
};

#endif // WAREHOUSEDOCUMENTRECEPTION_H
