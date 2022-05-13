#pragma once

#include <iostream>
#include <iomanip>

using namespace std;

class liczba_zespolona {
    double re;
    double im;

public:
    liczba_zespolona();
    liczba_zespolona(double r, double i);

    liczba_zespolona operator + (liczba_zespolona lz) const;
    liczba_zespolona operator - (liczba_zespolona lz) const;
    liczba_zespolona operator * (liczba_zespolona lz) const;
    liczba_zespolona operator / (liczba_zespolona lz) const;
    liczba_zespolona operator = (double liczba);

    // Porownanie wartosci re i im dwoch liczb zespolonych
    bool operator == (liczba_zespolona lz) const;
    bool operator == (double liczba) const {return (this->re == liczba) && (this->im == 0);};
    bool operator != (double liczba) const {return (this->re != liczba) || (this->im != 0);};
    liczba_zespolona operator += (liczba_zespolona lz);

    // Wypisanie liczby zespolonej w formacie (a+bi)
    friend ostream & operator << (ostream &ostr, liczba_zespolona lz);

    // Wczytanie liczby zespolonej w formacie (a+bi)
    friend istream & operator >> (istream &istr, liczba_zespolona &lz);
};
