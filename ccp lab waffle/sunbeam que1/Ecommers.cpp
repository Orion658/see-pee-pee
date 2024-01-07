#include <iostream>
#include <vector>
#include <string>
#include <limits>
using namespace std;

class Person {
protected:
    string name;

public:
    Person(const string& n) : name(n) {}

    string getName() const {
        return name;
    }
};

class Seller : public Person {
private:
    int sellerId;
    vector<int> productsSold;

public:
    Seller(const string& n, int id) : Person(n), sellerId(id) {}

    void addProductSold(int productId) {
        productsSold.push_back(productId);
    }

    void displayProductsSold() const {
        cout << "Products sold by Seller " << sellerId << " (" << getName() << "): ";
        for (int productId : productsSold) {
            cout << productId << " ";
        }
        cout << endl;
    }

    int getSellerId() const {
        return sellerId;
    }
};

class Product {
private:
    int productId;
    string productName;
    double price;

public:
    Product(int id, const string& name, double p) : productId(id), productName(name), price(p) {}

    void displayProduct() const {
        cout << "Product ID: " << productId << ", Name: " << productName << ", Price: $" << price << endl;
    }

    int getProductId() const {
        return productId;
    }
};

class ECommerceSystem {
private:
    vector<Seller> sellers;
    vector<Product> products;

public:
    void addSeller(const string& name, int sellerId) {
        Seller seller(name, sellerId);
        sellers.push_back(seller);
    }

    void addProduct(const string& productName, double price) {
        int productId = products.size() + 1; // Generating unique product ID
        Product product(productId, productName, price);
        products.push_back(product);
    }

    void displayProductsSoldBySeller(int sellerId) const {
        for (const Seller& seller : sellers) {
            if (seller.getSellerId() == sellerId) {
                seller.displayProductsSold();
                return;
            }
        }
        cout << "Seller not found." << endl;
    }

    void displayAllSellers() const {
        cout << "All Sellers:" << endl;
        for (const Seller& seller : sellers) {
            cout << "Seller ID: " << seller.getSellerId() << ", Name: " << seller.getName() << endl;
        }
    }

    void displayAllProducts() const {
        cout << "All Products:" << endl;
        for (const Product& product : products) {
            product.displayProduct();
        }
    }
};

int main() {
    ECommerceSystem ecommerce;

    int choice;
    do {
        cout << "\nMenu:\n1. Add Seller\n2. Add Product\n3. Display products sold by specific seller\n"
                  << "4. Display All Sellers\n5. Display All Products\n0. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string name;
                int sellerId;
                cout << "Enter seller name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline character
                getline(cin, name);
                cout << "Enter seller ID: ";
                cin >> sellerId;
                ecommerce.addSeller(name, sellerId);
                break;
            }
            case 2: {
                string productName;
                double price;
                cout << "Enter product name: ";
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline character
                getline(cin, productName);
                cout << "Enter product price: $";
                cin >> price;
                ecommerce.addProduct(productName, price);
                break;
            }
            case 3: {
                int sellerId;
                cout << "Enter seller ID to display products sold: ";
                cin >> sellerId;
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
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 0);

    return 0;
}
