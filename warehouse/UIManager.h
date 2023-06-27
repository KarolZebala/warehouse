#pragma once
#include <iostream>
#include <string>
#include "WarehouseLocationRepository.h"
#include "WarehouseDocumentRepository.h"
#include "ProuductRepository.h"
/**!
 * \brief Klasa IUIManager jest klasa abstrakcyjn¹, odpowiadaj¹c¹ za wyœwietlanie treœci w UI
 */
class IUIManager
{
public:
	virtual void ShowAll() = 0;
	virtual void ShowById() = 0;
	virtual void AddNew() = 0;

};

