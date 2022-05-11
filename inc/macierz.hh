#pragma once

#include <iostream>
#include <iomanip>

#include "swektor.hh"
#include "wektor.hh"

#define RZAD_WIELK 6

using namespace std;

class macierz {
private:
    wektor _kol[ROZMIAR];

public:
    const wektor & operator[] (int el) const {return this->_kol[el];}
    wektor & operator[] (int el) {return this->_kol[el];}
    macierz operator= (const macierz & mKopiowana);
    wektor operator* (wektor wek) const;

    void do_jednostkowej();
    macierz odwrotna() const;

    friend istream & operator >> (istream &istr, macierz &mac);
    friend ostream & operator << (ostream &ostr, const  macierz &mac);
};
