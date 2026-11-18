#include <iostream>
#include <vector>
#include <iomanip>
#include "product.h"
using namespace std;    
void showProducts(const std::vector<Product>& products) {
    for (size_t i = 0; i < products.size(); i++) {
        std::cout << i + 1 << ". "
            << std::left << std::setw(10) << products[i].name
            << std::fixed << std::setprecision(2) << products[i].price << " EUR"
            << "   quantity: " << products[i].quantity << "\n";
    }
  
}

struct Purchase {
    string productName;
    int quantity;
    double totalPrice;
};
void purchaseHistory(const vector<Purchase>& history) {

    cout << "\n========== PURCHASE HISTORY ==========\n";
    if (history.empty()) {
        cout << "History is empty.\n";
        return;
    }
    double grandTotal = 0;
    for (size_t i = 0; i < history.size(); i++) {
        cout << "\nPurchase #" << i + 1 << "\n";
        cout << "Product: " << history[i].productName << "\n";
        cout << "Quantity: " << history[i].quantity << "\n";
        cout << fixed << setprecision(2);
        cout << "Total: " << history[i].totalPrice << " EUR\n";
        grandTotal += history[i].totalPrice;
    }
    cout << "\n--------------------------------------\n";
    cout << "Grand Total: " << grandTotal << " EUR\n";
}


void chooseProduct(vector<Product>& products,
    vector<Purchase>& history) {
    int productChoice;
    int quantity;
    cout << "Enter product number: ";
    cin >> productChoice;
    if (productChoice < 1 || productChoice > products.size()) {
        cout << "Invalid product selection.\n";
        return;
    }
    cout << "Enter quantity: ";
    cin >> quantity;

    if (quantity <= 0) {
        cout << "Invalid quantity.\n";
        return;
    }
    if (quantity > products[productChoice - 1].quantity) {
        cout << "Not enough stock available.\n";
        return;
    }

    // Calculate total price
    double totalPrice =
        products[productChoice - 1].price * quantity;

    // Reduce stock
    products[productChoice - 1].quantity -= quantity;

    // Save purchase in history
    history.push_back({
        products[productChoice - 1].name,
        quantity,
        totalPrice
        });

    cout << "\nPurchase successful!\n";

    cout << "Product: "
        << products[productChoice - 1].name << "\n";

    cout << "Total: " << fixed << setprecision(2)
        << totalPrice << " EUR\n";
}

int main() {

    std::vector<Product> products = {
        { "Milk", 1.20, 30 },
        { "Bread", 0.95, 15 },
        { "Cheese", 4.50, 8 }
    };
    vector<Purchase> history;
    int choice = -1;
    while (choice != 0) {
        std::cout << "\n=== Store ===\n";
        std::cout << "1. Show products\n";
        std::cout << "2. Purchase products\n";
        cout << "3. Purchase history\n";
        std::cout << "0. Exit\n";
        std::cout << "Choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            showProducts(products);
            break;
        case 2:
            showProducts(products);
            chooseProduct(products, history);
            break;
        case 3:
            purchaseHistory(history);
            break;
        case 0:
            std::cout << "Bye!\n";
            break;
        default:
            std::cout << "Unknown option.\n";
        }
    }

    return 0;
}
