#include <iostream>

#include "procedural.h"
#include "oop.h"

using namespace std;

int main()
{
    int choice;

    cout << "\n--- SKLEP ---" << endl;
    cout << "1. Wersja proceduralna" << endl;
    cout << "2. Wersja obietkowa" << endl;
    cout << "Wybierz opcję: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        procedural();
        break;
    case 2:
        oop();
        break;
    default:
        cout << "Nieprawidłowa opcja!" << endl;
    }
}