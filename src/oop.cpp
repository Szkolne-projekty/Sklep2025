#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product
{
    int id;
    string name;
    string category;
    double price;
    int quantity;
};

class ProductsManager
{
private:
    vector<Product> products;

public:
    void addProduct();
    void displayProducts();
    void searchByName();
    void searchByCategory();
    void saveToFile();
    void readFromFile();
    void clearConsole();
    void menu();
};

void oop()
{
    ProductsManager manager;

    manager.menu();
}