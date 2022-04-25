#pragma once

#include <iostream>
#include "rozmiar.hh"

using namespace std;

class wektor {
private:


public:
  double _wsp[ROZMIAR];

  wektor();

  const double & operator[] (int el) const {return this->_wsp[el];}
  double & operator[] (int el) {return this->_wsp[el];}

  friend istream & operator >> (istream &istr, wektor &wek);
  friend ostream & operator << (ostream &ostr, const  wektor &wek);

};
