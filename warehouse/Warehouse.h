#ifndef WAREHOUSE_H
#define WAREHOUSE_H

#include <string>
#include <vector>
#include <memory>

class Warehouse {
public:
    explicit Warehouse(const std::string name);

    std::string getName() const;
    int getId();

private:
    int Id;
    std::string Name;
    
};

#endif // WAREHOUSE_H
