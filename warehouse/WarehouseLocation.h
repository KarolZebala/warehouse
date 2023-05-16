#ifndef WAREHOUSELOCATION_H
#define WAREHOUSELOCATION_H

#include <string>
#include <vector>
#include <memory>

class WarehouseLocation {
public:
    explicit WarehouseLocation(const std::string& name);

    std::string getName() const;

private:
    std::string name;
};

#endif // WAREHOUSELOCATION_H
