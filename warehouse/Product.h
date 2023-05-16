#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <memory>

class Product {
public:
    explicit Product(const std::string& name, int quantity);

    std::string getName() const;
    int getQuantity() const;

private:
    std::string name;
    int quantity;
};

#endif // PRODUCT_H
