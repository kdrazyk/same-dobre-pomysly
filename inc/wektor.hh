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

    wektor & operator+ (wektor wek2);
    wektor & operator- (wektor wek2);
    wektor & operator* (wektor wek2);
    wektor & operator/ (wektor wek2);

    friend istream & operator >> (istream &istr, wektor &wek);
    friend ostream & operator << (ostream &ostr, const  wektor &wek);
};
