#include <iostream>
#include<cstring>
#include <cstdlib>
#include <conio.h>

using namespace std;


void szyfrowanie(char *kod)
{
  int przesuniecie = 0, Oile[15] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9}; //tablica 15 elementowa, kazdy element to liczba przesuniec
  for (int i=0; kod[i] != NULL; i++)
  {
      kod[i] = ( kod[i] + Oile[przesuniecie] );  //przesuwa dana liczbe liter do przodu
      przesuniecie ++;
      if(przesuniecie == 15) przesuniecie = 0;  //jesli bedzie wiecej niz 15 liter, program zaczyna brac od poczatku cyfry z tablicy
  }
}

void deszyfrowanie(char *kod)
{
  int przesuniecie = 0, Oile[15] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9};
  for (int i=0; kod[i] != NULL; i++)
  {
      kod[i] = ( kod[i] - Oile[przesuniecie] ); //przesuwa dana liczne liter do tylu
      przesuniecie ++;
      if(przesuniecie == 15) przesuniecie = 0;
  }
}



int main()
{
    int wybor;
    int dlugosc=100;
    char kod[dlugosc];
do
{
    cout << "PROGRAM SZYFRUJACY I DESZYFRUJACY" << endl;
    cout << " ---------------------------------" << endl;
    cout << "WYKONANIE: Adam Czartoryjski" << endl;
    cout << "NUMER INDEKSU: 219295" << endl;
    cout << "PRZEDMIOT: Kryptografia 2" << endl;
    cout << "PROWADZACY: Andrzej Zygmunt" <<endl;
    cout << "----------------------------------" <<endl;
    cout << "1. Szyfrowanie" << endl;
    cout << "2. Deszyfrowanie" << endl;
    cout << "3. Zakoncz program" << endl;

    cin >> wybor;

    system ("cls");


    switch( wybor )
{
case 1:
    cout << "Podaj slowo do zaszyfrowania: " << endl;
    cin.sync();
    cin.getline(kod, dlugosc);

    if(dlugosc <= 100)
        {
            system ("cls");
            cout << endl;
            szyfrowanie(kod);
            cout << "Zaszyfrowany kod: " << kod;
            cout << endl;
            getch();
            system ("cls");
        }
    else
        {
            cout<<endl;
            cout << "Zbyt dlugie slowo" << endl;
        }
    break;

case 2:
    system ("cls");
    cout << "Zaszyfrowany kod: " << kod << endl;
    deszyfrowanie(kod);
    cout << "Zdeszyfrowany kod: " << kod;
    getch();
    cout << endl;
    system ("cls");
    break;

case 3:
    cout << "Program zakonczony" <<endl;
    break;

    default:
        system ("cls");
        cout << "Nie ma takiej opcji w programie" << endl;
        break;
}

} while (wybor != 3); //jesli uzytkownik wybierze opcje numer 3- program jest zakonczony

    return 0;
}
