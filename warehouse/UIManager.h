#pragma once
#include <iostream>
#include <string>
#include "WarehouseProductService.h"
#include "WarehouseDocumentService.h"
#include "WarehouseLocationService.h"
#include "WarehouseLocationRepository.h"
#include "WarehouseDocumentRepository.h"
/**!
 * \brief Klasa IUIManager jest klasa abstrakcyjną, odpowiadającą za wyświetlanie treści w UI
 */
class IUIManager
{
public:
	virtual void ShowAll() =0;
	virtual void ShowById() =0;
	virtual void AddNew() =0;

};

