#pragma once

#include <iostream>
#include <iomanip>
#include "macierz.hh"

#define RZAD_WIELK_LICZB 3

class ukladRownanLiniowych {
private:
    macierz _macierzParametrow;
    swektor<double,ROZMIAR> _wektorRozwiazan;

public:
    swektor<double,ROZMIAR> rozwiazanie() const;
    swektor<double,ROZMIAR> wektorBledu() const;

    friend istream & operator >> (istream &istr, ukladRownanLiniowych &url);
    friend ostream & operator << (ostream &ostr, const ukladRownanLiniowych &url);
};
