#include "ECommerceSystem.h"
#include <iostream>

void ECommerceSystem::addSeller(const std::string& name, int sellerId) {
    Seller seller(name, sellerId);
    sellers.push_back(seller);
}

void ECommerceSystem::addProduct(const std::string& productName, double price) {
    int productId = products.size() + 1;
    Product product(productId, productName, price);
    products.push_back(product);
}

void ECommerceSystem::displayProductsSoldBySeller(int sellerId) const {
    bool sellerFound = false;

    for (const Seller& seller : sellers) {
        if (seller.getSellerId() == sellerId) {
            seller.displayProductsSold();
            sellerFound = true;
            break;
        }
    }

    if (!sellerFound) {
        std::cout << "Seller with ID " << sellerId << " not found." << std::endl;
    }
}

void ECommerceSystem::displayAllSellers() const {
    std::cout << "All Sellers:" << std::endl;
    for (const Seller& seller : sellers) {
        std::cout << "Seller ID: " << seller.getSellerId() << ", Name: " << seller.getName() << std::endl;
    }
}

void ECommerceSystem::displayAllProducts() const {
    std::cout << "All Products:" << std::endl;
    for (const Product& product : products) {
        product.displayProduct();
    }
}
