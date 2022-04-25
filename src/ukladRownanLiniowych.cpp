#include "ukladRownanLiniowych.hh"


istream & operator >> (istream &istr, ukladRownanLiniowych &url)
{
  istr >> url._macierzParametrow >> url._wektorRozwiazan;
  return istr;
}

ostream & operator << (ostream &ostr, const ukladRownanLiniowych &url)
{
  ostr << url._macierzParametrow << url._wektorRozwiazan;
  return ostr;
}
