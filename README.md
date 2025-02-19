# Projekt sklep 2025

## Uruchomienie

1. Zmienić nazwę pliku `products.txt.example` na `products.txt` (opcjonalnie)
2. Skompilować i uruchomic

## Założenia projektu (od Pana Bartka)

Projekt można wykonać w C++ lub C, nie używamy typu “string” tylko “char”. Projekt wykonujemy zgodnie z zaleceniami (tj. tablice, pliki itd.)

a) Cel: Stworzenie aplikacji konsolowej do zarządzania katalogiem produktów.
Zadania do wykonania:

1. Przechowuj informacje o produktach (ID, nazwa, kategoria, cena, ilość) w tablicy/tablicach.
2. Utwórz tablice dla każdego atrybutu produktu (maksymalnie 100 produktów).
3. Zaimplementuj menu umożliwiające użytkownikowi: - Dodanie produktu - Usunięcie produktu - Wyszukiwanie produktu po nazwie lub kategorii - Wyświetlanie listy produktów - Zapis i odczyt bazy produktów z pliku (products.txt) - Zakończenie programu
4. Użyj plików do zapisywania i odczytywania bazy produktów.
5. Dodaj podstawową walidację danych wejściowych (np. puste nazwy, kategorie itp.).\_/

b) Zaprezentuj jak wykonać powyższe zadanie w języku C++ (w C nie mamy klas) z użyciem klas i obiektów. Ten podpunkt może być wykonany szczątkowo tylko w celu prezentacji podpunktu a) w inny sposób, tj. aby dało się dodać jakiś produkt i też nadać mu kategorie itd. ale z użyciem klas i obiektów nie w samych tablicach jak było to w podpunkcie a) ….w tej części można już pominąć zapis do pliku i odczyt czy nawet wszystkie podpunkty menu, wystarczy dodawanie i kasowanie produktu. Niech program z tego podpunktu będzie w osobnym pliku. Ten podpunkt nie musi być pełnoprawnym zamiennikiem pierwszego tylko niejako wskazówką jak rozwiazać zadanie w inny (może bardziej cywilizowany) sposób.

## Pomocnicze linki i podpowiedzi (od Pana Bartka)

funkcje do obsługi plików: fopen(), fscanf(), fprintf(), fclose()

przykladowe poradniki jak wykorzystywać te funkcje (pamiętajcie że mogą być drobne różnice składniowe między C a C++ gdy zdecydujecie się na jeden z nich):

-   [C/Czytanie i pisanie do plików - Wikibooks, biblioteka wolnych podręczników](https://pl.wikibooks.org/wiki/C/Czytanie_i_pisanie_do_plik%C3%B3w)
-   [C Library - fscanf() function](https://www.tutorialspoint.com/c_standard_library/c_function_fscanf.htm)
-   [C Library - fprintf() function](https://www.tutorialspoint.com/c_standard_library/c_function_fprintf.htm)
-   [C Library - fopen() function](https://www.tutorialspoint.com/c_standard_library/c_function_fopen.htm)
-   [C Library - fclose() function](https://www.tutorialspoint.com/c_standard_library/c_function_fclose.htm)

i inne podobne, youtube, pomoc prowadzącego (ale nie na ostatnią chwilę) itp.

przykladowa walidacja:
// Function to validate input
int isValidString(const char\* str) {
return str != NULL && strlen(str) > 0;
}

## Problematyka

To co jest napisane w założeniach nie ma sensu, pozdrawiam
