#include "macierz.hh"

istream & operator >> (istream &istr, macierz &mac)
{
  for (wektor &wek : mac._kol)
    istr >> wek;
  return istr;
}

ostream & operator << (ostream &ostr, const macierz &mac)
{
  for (wektor wek : mac._kol)
    ostr << wek << endl;
  return ostr;
}
