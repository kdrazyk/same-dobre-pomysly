#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include "rozmiar.hh"

using namespace std;

#define SZEROKOSC 5
#define PRECYZJA 5

template <typename sTyp, int sWymiar>
class swektor {
private:
    sTyp _wsp[sWymiar];

public:
    swektor() {for (sTyp &wsp: _wsp) wsp = 0;};

    const sTyp & operator[] (int el) const {return this->_wsp[el];}
    sTyp & operator[] (int el) {return this->_wsp[el];}
    void add(int x, sTyp y) {_wsp[x] += y;}
    double iloczynSkalarny(const swektor<sTyp, sWymiar> &wek2) const;
    double dlugosc() {return sqrt(this->iloczynSkalarny(*this));}

    swektor<sTyp,sWymiar> operator + (const swektor<sTyp, sWymiar> &wektor2) const;
    swektor<sTyp,sWymiar> operator - (const swektor<sTyp, sWymiar> &wektor2) const;
    swektor<sTyp,sWymiar> operator * (double liczba) const;
    swektor<sTyp,sWymiar> operator / (double liczba) const;
};



template <typename sTyp, int sWymiar>
istream & operator >> (istream &istr, swektor<sTyp,sWymiar> &wek)
{
    for (int i=0; i < sWymiar; ++i)
        istr >> wek[i];
    return istr;
}

template <typename sTyp, int sWymiar>
ostream & operator << (ostream &ostr, const swektor<sTyp,sWymiar> &wek)
{
    ostr << "[";
    for (int i=0; i < sWymiar; ++i) {
        ostr << setw(SZEROKOSC) << setprecision(PRECYZJA) << wek[i];
        ostr << (i==sWymiar-1 ? "" : ",");
    }
    ostr << "]";
    return ostr;
}

template <typename sTyp, int sWymiar>
double swektor<sTyp,sWymiar>::iloczynSkalarny(const swektor<sTyp, sWymiar> &wek2) const
{
    double wynik = 0;
    for (int i=0; i < ROZMIAR; ++i)
        wynik += this->_wsp[i] * wek2._wsp[i];
    return wynik;
}

template <typename sTyp, int sWymiar>
swektor<sTyp,sWymiar> swektor<sTyp,sWymiar>::operator + (const swektor<sTyp, sWymiar> &wektor2) const
{
    swektor<sTyp,sWymiar> wynik;
    for (int i=0; i < sWymiar; ++i)
        wynik[i] = this->_wsp[i] + wektor2._wsp[i];
    return wynik;
}

template <typename sTyp, int sWymiar>
swektor<sTyp,sWymiar> swektor<sTyp,sWymiar>::operator - (const swektor<sTyp, sWymiar> &wektor2) const
{
    swektor<sTyp,sWymiar> wynik;
    for (int i=0; i < sWymiar; ++i)
        wynik[i] = this->_wsp[i] - wektor2._wsp[i];
    return wynik;
}

template <typename sTyp, int sWymiar>
swektor<sTyp,sWymiar> swektor<sTyp,sWymiar>::operator * (double liczba) const
{
    swektor<sTyp,sWymiar> wynik;
    for (int i=0; i < ROZMIAR; ++i)
        wynik[i] = this->_wsp[i] * liczba;
    return wynik;
}

template <typename sTyp, int sWymiar>
swektor<sTyp,sWymiar> swektor<sTyp,sWymiar>::operator / (double liczba) const
{
    swektor<sTyp,sWymiar> wynik;
    for (int i=0; i < ROZMIAR; ++i)
        wynik[i] = this->_wsp[i] / liczba;
    return wynik;
}
