#pragma once
#include <sqlite3.h>
#include <string>
/**!
 * \brief Klasa ISeedingService jest klas¹ abstrakcyjn¹, która odpowiada inicjalizacje bazy na pocz¹tku dzia³ania aplikacji
 */
class ISeedingService
{
public:
	virtual void AddTables() =0;
};
/**!
 * \brief Klasa SeedingService odpowiada inicjalizacje bazy na pocz¹tku dzia³ania aplikacji
 */
class SeedingService : public ISeedingService
{
public:
	/**
	* Funkcja dodaje dodaje table do bazy jezeli nie istniej¹
	*
	*/
	void AddTables();
};

