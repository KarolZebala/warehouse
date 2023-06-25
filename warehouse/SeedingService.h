#pragma once
#include <sqlite3.h>
#include <string>
class ISeedingService
{
public:
	virtual void AddTables() {};
};
class SeedingService : public ISeedingService
{
public:
	void AddTables();
};

