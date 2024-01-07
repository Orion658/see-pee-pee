#include "Product.h"
#include <iostream>

Product::Product(int id, const std::string& name, double p) : productId(id), productName(name), price(p) {}

void Product::displayProduct() const {
    std::cout << "Product ID: " << productId << ", Name: " << productName << ", Price: $" << price << std::endl;
}

int Product::getProductId() const {
    return productId;
}
