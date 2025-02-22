#include <iostream>
#include <cstdio>
#include <cstring>
#include <limits>

#include "index.h"

using namespace std;

const int PRODUCTS_LIMIT = 100;
const int MAX_LENGTH = 50;

const char *FILE_PATH = "../products.txt";

int ids[PRODUCTS_LIMIT];
char names[PRODUCTS_LIMIT][MAX_LENGTH];
char categories[PRODUCTS_LIMIT][MAX_LENGTH];
double prices[PRODUCTS_LIMIT];
int quantities[PRODUCTS_LIMIT];
int productsCount = 0;

void addProduct()
{
    if (productsCount >= PRODUCTS_LIMIT)
    {
        cout << "Osiągnięto limit produktów!" << endl;
        return;
    }

    ids[productsCount] = productsCount + 1;

    cout << "Podaj nazwę: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.getline(names[productsCount], MAX_LENGTH);

    cout << "Podaj kategorię: ";
    cin.getline(categories[productsCount], MAX_LENGTH);

    cout << "Podaj cenę: ";
    cin >> prices[productsCount];

    cout << "Podaj ilość: ";
    cin >> quantities[productsCount];

    productsCount++;
    cout << "Produkt został dodany!" << endl;
}

void displayProducts()
{
    if (productsCount == 0)
    {
        cout << "Brak produktów do wyświetlenia." << endl;
        return;
    }

    cout << "\nLista produktów:" << endl;
    for (int i = 0; i < productsCount; i++)
    {
        cout << "ID: " << ids[i] << "\tNazwa: " << names[i]
             << "\tKategoria: " << categories[i] << "\tCena: " << prices[i]
             << "zl\tIlość: " << quantities[i] << endl;
    }
}

void searchByName()
{
    if (productsCount == 0)
    {
        cout << "Brak produktów do wyszukania." << endl;
        return;
    }

    char prompt[PRODUCTS_LIMIT];
    cout << "Podaj nazwę produktu do wyszukania: ";
    cin.ignore();
    cin.getline(prompt, MAX_LENGTH);

    bool found = false;
    for (int i = 0; i < PRODUCTS_LIMIT; i++)
    {
        if (strcmp(names[i], prompt) == 0)
        {
            cout << "\nZnaleziono produkt:\n";
            cout << "ID: " << ids[i] << "\tNazwa: " << names[i]
                 << "\tKategoria: " << categories[i] << "\tCena: " << prices[i]
                 << " zl\tIlość: " << quantities[i] << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Nie znaleziono produktu o podanej nazwie." << endl;
}

void searchByCategory()
{
    if (productsCount == 0)
    {
        cout << "Brak produktów do wyszukania." << endl;
        return;
    }

    char prompt[MAX_LENGTH];
    cout << "Podaj kategorię do wyszukania: ";
    cin.ignore();
    cin.getline(prompt, MAX_LENGTH);

    bool found = false;
    cout << "\nProdukty w kategorii " << prompt << ":\n";
    for (int i = 0; i < productsCount; i++)
    {
        if (strcmp(categories[i], prompt) == 0)
        {
            cout << "ID: " << ids[i] << "\tNazwa: " << names[i]
                 << "\tCena: " << prices[i] << " zl\tIlość: " << quantities[i] << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Nie znaleziono produktów w podanej kategorii." << endl;
}

void saveToFile()
{
    FILE *plik = fopen(FILE_PATH, "w");
    if (!plik)
    {
        cout << "Błąd otwarcia pliku!" << endl;
        return;
    }

    for (int i = 0; i < productsCount; i++)
    {
        fprintf(plik, "%d;%s;%s;%.2f;%d\n", ids[i], names[i], categories[i], prices[i], quantities[i]);
    }

    fclose(plik);
    cout << "Zapisano dane do pliku…" << endl;
}

void readFromFile()
{
    FILE *plik = fopen(FILE_PATH, "r");
    if (!plik)
    {
        cout << "Brak pliku lub błąd odczytu." << endl;
        return;
    }

    productsCount = 0;
    while (fscanf(plik, "%d;%49[^;];%49[^;];%lf;%d\n",
                  &ids[productsCount], names[productsCount],
                  categories[productsCount], &prices[productsCount],
                  &quantities[productsCount]) == 5)
    {
        productsCount++;
        if (productsCount >= PRODUCTS_LIMIT)
            break;
    }

    fclose(plik);
    cout << "Wczytano dane z pliku…" << endl;
}

void menu()
{
    int choice;

    clearConsole();

    bool firstRun = true;
    do
    {
        string title = firstRun ? "--- WERSJA PROCEDURALNA ---" : "\n--- WERSJA PROCEDURALNA ---";
        cout << title << endl;
        cout << "1. Dodaj produkt" << endl;
        cout << "2. Wyświetl wszystkie produkty" << endl;
        cout << "3. Wyszukaj po nazwie" << endl;
        cout << "4. Wyszukaj po kategorii" << endl;
        cout << "5. Zapisz do pliku" << endl;
        cout << "6. Wczytaj z pliku" << endl;
        cout << "7. Wyjście" << endl;
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
            saveToFile();
            break;
        case 6:
            readFromFile();
            break;
        case 7:
            cout << "Zamykanie programu..." << endl;
            break;
        default:
            cout << "Nieprawidłowa opcja!" << endl;
        }
    } while (choice != 7);
}

void procedural()
{
    readFromFile();
    menu();
}