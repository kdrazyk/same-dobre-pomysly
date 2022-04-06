#pragma once

#include <iostream>
#include "rozmiar.hh"

using namespace std;

class wektor
{
  private:


  public:
   double _wsp[ROZMIAR];
  wektor();

  double operator[] (int numer) {return this->_wsp[numer];}

  friend istream & operator >> (istream &istr, wektor &wek);
  friend ostream & operator << (ostream &ostr, const  wektor &wek);

};
