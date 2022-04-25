#pragma once

#include <iostream>
#include <iomanip>
#include "macierz.hh"

#define RZAD_WIELK_LICZB 3

class ukladRownanLiniowych {
private:
    macierz _macierzParametrow;
    wektor _wektorRozwiazan;

public:

    friend istream & operator >> (istream &istr, ukladRownanLiniowych &url);
    friend ostream & operator << (ostream &ostr, const ukladRownanLiniowych &url);
};
