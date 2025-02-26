#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "index.h"

using namespace std;

const char *OOP_FILE_PATH = "../products.txt";

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
    void addProduct()
    {
        Product product;
        product.id = products.size() + 1;

        cout << "Podaj nazwę: ";
        cin.ignore();
        getline(cin, product.name);

        cout << "Podaj kategorię: ";
        getline(cin, product.category);

        cout << "Podaj cenę: ";
        cin >> product.price;

        cout << "Podaj ilość: ";
        cin >> product.quantity;

        products.push_back(product);
        cout << "Produkt został dodany!" << endl;
    };

    void displayProducts()
    {
        if (products.empty())
        {
            cout << "Brak produktów do wyświetlenia." << endl;
            return;
        }

        cout << "\nLista produktów:" << endl;
        for (const auto &product : products)
        {
            cout << "ID: " << product.id << "\tNazwa: " << product.name
                 << "\tKategoria: " << product.category << "\tCena: " << product.price
                 << "zl\tIlość: " << product.quantity << endl;
        }
    };

    void searchByName()
    {
        if (products.empty())
        {
            cout << "Brak produktów do wyszukania." << endl;
            return;
        }

        string prompt;
        cout << "Podaj nazwę produktu do wyszukania: ";
        cin.ignore();
        getline(cin, prompt);

        bool found = false;
        for (const auto &product : products)
        {
            if (product.name == prompt)
            {
                cout << "\nZnaleziono produkt:\n";
                cout << "ID: " << product.id << "\tNazwa: " << product.name
                     << "\tKategoria: " << product.category << "\tCena: " << product.price
                     << "zl\tIlość: " << product.quantity << endl;
                found = true;
            }
        }

        if (!found)
            cout << "Nie znaleziono produktu o podanej nazwie." << endl;
    };

    void searchByCategory()
    {
        if (products.empty())
        {
            cout << "Brak produktów do wyszukania." << endl;
            return;
        }

        string prompt;
        cout << "Podaj kategorię do wyszukania: ";
        cin.ignore();
        getline(cin, prompt);

        bool found = false;
        cout << "\nProdukty w kategorii " << prompt << ":\n";
        for (const auto &product : products)
        {
            if (product.category == prompt)
            {
                cout << "ID: " << product.id << "\tNazwa: " << product.name
                     << "\tCena: " << product.price << " zl\tIlość: " << product.quantity << endl;
                found = true;
            }
        }

        if (!found)
            cout << "Nie znaleziono produktów w podanej kategorii." << endl;
    };

    void deleteByName()
    {
        if (products.empty())
        {
            cout << "Brak produktów do usunięcia." << endl;
            return;
        }

        string prompt;
        cout << "Podaj nazwę produktu do usunięcia: ";
        cin.ignore();
        getline(cin, prompt);

        auto it = find_if(products.begin(), products.end(), [&](const Product &product)
                          { return product.name == prompt; });

        if (it == products.end())
        {
            cout << "Nie znaleziono produktu o podanej nazwie…" << endl;
            return;
        }

        int id = it->id;
        products.erase(it);
        cout << "Produkt o ID " << id << " został usunięty." << endl;
    };

    void saveToFile()
    {
        if (products.empty())
        {
            cout << "Brak produktów do zapisania." << endl;
            return;
        }

        FILE *plik = fopen(OOP_FILE_PATH, "w");
        if (!plik)
        {
            cout << "Błąd otwarcia pliku!" << endl;
            return;
        }

        for (const auto &product : products)
        {
            fprintf(plik, "%d;%s;%s;%.2f;%d\n", product.id, product.name.c_str(), product.category.c_str(), product.price, product.quantity);
        }

        fclose(plik);
        cout << "Zapisano dane do pliku…" << endl;
    };

    void readFromFile()
    {
        FILE *plik = fopen(OOP_FILE_PATH, "r");
        if (!plik)
        {
            cout << "Brak pliku lub błąd odczytu." << endl;
            return;
        }

        products.clear();
        Product product;
        char name[100], category[100];

        while (fscanf(plik, "%d;%99[^;];%99[^;];%lf;%d\n", &product.id, name, category, &product.price, &product.quantity) == 5)
        {
            product.name = name;
            product.category = category;
            products.push_back(product);
        }

        fclose(plik);
        cout << "Wczytano dane z pliku…" << endl;
    };

    void menu()
    {
        int choice;

        clearConsole();

        bool firstRun = true;
        do
        {
            string title = firstRun ? "--- WERSJA OBIEKTOWA ---" : "\n--- WERSJA OBIEKTOWA ---";
            cout << title << endl;
            cout << "1. Dodaj produkt" << endl;
            cout << "2. Wyświetl wszystkie produkty" << endl;
            cout << "3. Wyszukaj po nazwie" << endl;
            cout << "4. Wyszukaj po kategorii" << endl;
            cout << "5. Usuń po nazwie" << endl;
            cout << "6. Zapisz do pliku" << endl;
            cout << "7. Wczytaj z pliku" << endl;
            cout << "8. Wyjście" << endl;
            cout << "Wybierz opcję: ";
            cin >> choice;

            firstRun = false;

            switch (choice)
            {
            case 1:
                addProduct();
                break;
            case 2:
                displayProducts();
                break;
            case 3:
                searchByName();
                break;
            case 4:
                searchByCategory();
                break;
            case 5:
                deleteByName();
                break;
            case 6:
                saveToFile();
                break;
            case 7:
                readFromFile();
                break;
            case 8:
                cout << "Zamykanie programu..." << endl;
                break;
            default:
                cout << "Nieprawidłowa opcja!" << endl;
            }
        } while (choice != 8);
    };
};

void oop()
{
    ProductsManager manager;

    manager.readFromFile();
    manager.menu();
}