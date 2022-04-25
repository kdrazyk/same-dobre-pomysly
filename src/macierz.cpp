#include "macierz.hh"


istream & operator >> (istream &istr, macierz &mac)
{
  for (wektor wek : mac._kol)
    for (double &war : wek._wsp) {
      istr >> war;
      cout << war;
      }
  return istr;
}

ostream & operator << (ostream &ostr, const  macierz &mac)
{
  for (wektor wek : mac._kol) {
    for (double war : wek._wsp)
      ostr << war;
    ostr << endl;
    }
  return ostr;
}
