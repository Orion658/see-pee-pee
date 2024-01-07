#include "Seller.h"
#include <iostream>

Seller::Seller(const std::string& n, int id) : Person(n), sellerId(id) {}

void Seller::addProductSold(int productId) {
    productsSold.push_back(productId);
}

void Seller::displayProductsSold() const {
    std::cout << "Products sold by Seller " << sellerId << " (" << getName() << "): ";
    for (int productId : productsSold) {
        std::cout << productId << " ";
    }
    std::cout << std::endl;
}

int Seller::getSellerId() const {
    return sellerId;
}

