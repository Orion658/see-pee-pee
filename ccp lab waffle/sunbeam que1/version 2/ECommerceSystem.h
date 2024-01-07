#ifndef ECOMMERCESYSTEM_H
#define ECOMMERCESYSTEM_H

#include "Seller.h"
#include "Product.h"
#include <vector>

class ECommerceSystem {
private:
    std::vector<Seller> sellers;
    std::vector<Product> products;

public:
    void addSeller(const std::string& name, int sellerId);
    void addProduct(const std::string& productName, double price);
    void displayProductsSoldBySeller(int sellerId) const;
    void displayAllSellers() const;
    void displayAllProducts() const;
};

#endif
