#pragma once

#include <iostream>
#include "wektor.hh"

using namespace std;

class macierz {
private:
  wektor _kol[ROZMIAR];

public:
  const wektor & operator[] (int el) const {return this->_kol[el];}
  wektor & operator[] (int el) {return this->_kol[el];}

  friend istream & operator >> (istream &istr, macierz &mac);
  friend ostream & operator << (ostream &ostr, const  macierz &mac);
};
