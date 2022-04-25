#include <iostream>

#include "wektor.hh"

using namespace std;

class macierz {
private:
  wektor _kol[ROZMIAR];
public:

  friend istream & operator >> (istream &istr, macierz &mac);
  friend ostream & operator << (ostream &ostr, const  macierz &mac);
};
