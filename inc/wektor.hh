#pragma once

#include <iostream>
#include "rozmiar.hh"

using namespace std;

class wektor {
private:
    double _wsp[ROZMIAR];

public:
    wektor();

    const double & operator[] (int el) const {return this->_wsp[el];}
    double & operator[] (int el) {return this->_wsp[el];}

    wektor operator+ (const wektor &wektor2) const;
    wektor operator- (const wektor &wektor2) const;
    wektor operator* (double liczba) const;
    wektor operator/ (double liczba) const;

    void set(int x, double y) {_wsp[x] = y;}
    double get(int x) {return _wsp[x];}
    void add(int x, double y) {_wsp[x] += y;}

    friend istream & operator >> (istream &istr, wektor &wek);
    friend ostream & operator << (ostream &ostr, const  wektor &wek);
};
