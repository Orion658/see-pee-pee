#include "ECommerceSystem.h"
#include <iostream>
#include <limits>

int main() {
    ECommerceSystem ecommerce;

    int choice;
    do {
        std::cout << "\nMenu:\n1. Add Seller\n2. Add Product\n3. Display products sold by specific seller\n"
                  << "4. Display All Sellers\n5. Display All Products\n0. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string name;
                int sellerId;
                std::cout << "Enter seller name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear newline character
                std::getline(std::cin, name);
                std::cout << "Enter seller ID: ";
                std::cin >> sellerId;
                ecommerce.addSeller(name, sellerId);
                break;
            }
            case 2: {
                std::string productName;
                double price;
                std::cout << "Enter product name: ";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear newline character
                std::getline(std::cin, productName);
                std::cout << "Enter product price: $";
                std::cin >> price;
                ecommerce.addProduct(productName, price);
                break;
            }
            case 3: {
                int sellerId;
                std::cout << "Enter seller ID to display products sold: ";
                std::cin >> sellerId;
                ecommerce.displayProductsSoldBySeller(sellerId);
                break;
            }
            case 4:
                ecommerce.displayAllSellers();
                break;
            case 5:
                ecommerce.displayAllProducts();
                break;
            case 0:
                std::cout << "Exiting program.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
