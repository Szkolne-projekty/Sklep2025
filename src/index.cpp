#include <iostream>

#include "procedural.h"
#include "oop.h"

using namespace std;

void clearConsole()
{
#if defined(_WIN32)
    system("cls");
#else
    system("clear");
#endif
}

int main()
{
    int choice;

    do
    {
        clearConsole();
        cout << "--- SKLEP ---" << endl;
        cout << "1. Wersja proceduralna" << endl;
        cout << "2. Wersja obietkowa" << endl;
        cout << "3. Wyjście" << endl;
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
        case 3:
            cout << "Zamykanie programu..." << endl;
            break;
        default:
            cout << "Nieprawidłowa opcja!" << endl;
        }
    } while (choice != 3);

    return 0;
}