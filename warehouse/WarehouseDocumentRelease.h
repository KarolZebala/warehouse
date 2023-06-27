#ifndef WAREHOUSEDOCUMENTRELEASE_H
#define WAREHOUSEDOCUMENTRELEASE_H

#include "WarehouseDocument.h"
#include<ctime>
/**!
 * \brief Klasa WarehouseDocumentRelease ktora reprezentuje wydania magazynowe
 * 
 * Jest to dokument wystawiany w momencie wydania towaru z magazunu
 */
class WarehouseDocumentRelease : public WarehouseDocument {
public:
	/**
	* Konstruktor klasy WarehouseDocumentReception
	*
	* \param documentName nazwa dokument
	* \param warehosueId id magazynu
	* \param clientName  klient ktoremu jest wydawany towar
	* \param employeeName pracownik odpowiedzialny za dokument
	*/
    WarehouseDocumentRelease(const std::string documentName, std::string warehouseId, std::string clientName, std::string employeeName, std::string docuemntId = "");
	/**
	* Funckcja dodaje do wydania magazynowego produkt
	*
	* \param product produktu do dodania
	*/
    void addProductToDocument(std::shared_ptr<DocumentProduct> product);
	std::time_t getCreateDate();

	std::time_t getIssueDate();
	std::string getClientName();
	std::string getEmployeeName();
	std::vector<std::shared_ptr<DocumentProduct>> getAllReleaseProduct();

private:
	std::time_t CreateDate;
	std::time_t IssueDate;
	std::string ClientName;
	std::string EmployeeName;
};




#endif // WAREHOUSEDOCUMENTRELEASE_H
