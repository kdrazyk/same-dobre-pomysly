#pragma once

#include <iostream>
#include "macierz.hh"

class ukladRownanLiniowych {
private:
  macierz _macierzParametrow;
  wektor _wektorRozwiazan;

public:

  friend istream & operator >> (istream &istr, ukladRownanLiniowych &url);
  friend ostream & operator << (ostream &ostr, const ukladRownanLiniowych &url);

};
