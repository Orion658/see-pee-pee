#ifndef SELLER_H
#define SELLER_H

#include "Person.h"
#include <vector>

class Seller : public Person {
private:
    int sellerId;
    std::vector<int> productsSold;

public:
    Seller(const std::string& n, int id);
    void addProductSold(int productId);
    void displayProductsSold() const;
    int getSellerId() const;
};

#endif
