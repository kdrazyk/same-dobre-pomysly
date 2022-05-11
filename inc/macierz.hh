#pragma once

#include <iostream>
#include <iomanip>
#include "swektor.hh"

#define RZAD_WIELK 6

using namespace std;

class macierz {
private:
    swektor<double,ROZMIAR> _kol[ROZMIAR];

public:
    const swektor<double,ROZMIAR> & operator[] (int el) const {return this->_kol[el];}
    swektor<double,ROZMIAR> & operator[] (int el) {return this->_kol[el];}
    macierz operator= (const macierz & mKopiowana);
    swektor<double,ROZMIAR> operator* (swektor<double,ROZMIAR> wek) const;

    void do_jednostkowej();
    macierz odwrotna() const;

    friend istream & operator >> (istream &istr, macierz &mac);
    friend ostream & operator << (ostream &ostr, const  macierz &mac);
};
