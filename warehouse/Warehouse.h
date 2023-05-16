#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include <vector>
#include <memory>

class Warehouse {
public:
    explicit Warehouse(const std::string& name);

    std::string getName() const;

private:
    std::string name;
};

#endif // WAREHOUSE_H
