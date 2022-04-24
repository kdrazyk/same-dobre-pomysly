#include "wektor.hh"

wektor::wektor()
{
  for (double &wsp : this->_wsp)
    wsp = 0;
}

ostream & operator << (ostream &ostr, const wektor &wek)
{
  for (double liczba : wek._wsp)
    ostr << liczba << endl;
  return ostr;
}

istream & operator >> (istream &istr, wektor &wek)
{
  for (double &liczba : wek._wsp)
    istr >> liczba;
  return istr;
}
