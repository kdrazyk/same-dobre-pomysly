#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include "rozmiar.hh"
#include "LZespolona.hh"

using namespace std;

#define SZEROKOSC 6
#define PRECYZJA 1

template <typename sTyp, int sWymiar>
class swektor {
private:
    sTyp _wsp[sWymiar];

public:
    swektor() {for (sTyp &wsp: _wsp) wsp = 0;};

    const sTyp & operator[] (int el) const {return this->_wsp[el];}
    sTyp & operator[] (int el) {return this->_wsp[el];}
    void add(int x, sTyp y) {_wsp[x] += y;}
    sTyp iloczynSkalarny(const swektor<sTyp, sWymiar> &wek2) const;
    double dlugosc();

    swektor<sTyp,sWymiar> operator + (const swektor<sTyp, sWymiar> &wektor2) const;
    swektor<sTyp,sWymiar> operator - (const swektor<sTyp, sWymiar> &wektor2) const;
    swektor<sTyp,sWymiar> operator * (sTyp liczba) const;
    swektor<sTyp,sWymiar> operator / (sTyp liczba) const;
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
        ostr  << scientific << setprecision(PRECYZJA) << wek[i];
        ostr << (i==sWymiar-1 ? "" : ",");
    }
    ostr << "]";
    return ostr;
}

template <typename sTyp, int sWymiar>
sTyp swektor<sTyp,sWymiar>::iloczynSkalarny(const swektor<sTyp, sWymiar> &wek2) const
{
    sTyp wynik;
    wynik = 0;
    for (int i=0; i < sWymiar; ++i)
        wynik += this->_wsp[i] * wek2._wsp[i];
    return wynik;
}

/* IMPLEMENTACJA DLA DOUBLE
template<typename sTyp, int sWymiar>
double swektor<sTyp,sWymiar>::dlugosc()
{
    return sqrt(this->iloczynSkalarny(*this));
}
 */

template<typename sTyp, int sWymiar>
inline double swektor<sTyp,sWymiar>::dlugosc()
{
    double suma = 0;
    liczba_zespolona lz;
    for (int i=0; i < sWymiar; ++i) {
     lz = this->_wsp[i];
     suma += lz.modul2();
    }
    return sqrt(suma);
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
swektor<sTyp,sWymiar> swektor<sTyp,sWymiar>::operator * (sTyp liczba) const
{
    swektor<sTyp,sWymiar> wynik;
    for (int i=0; i < sWymiar; ++i)
        wynik[i] = this->_wsp[i] * liczba;
    return wynik;
}

template <typename sTyp, int sWymiar>
swektor<sTyp,sWymiar> swektor<sTyp,sWymiar>::operator / (sTyp liczba) const
{
    swektor<sTyp,sWymiar> wynik;
    for (int i=0; i < sWymiar; ++i)
        wynik[i] = this->_wsp[i] / liczba;
    return wynik;
}
