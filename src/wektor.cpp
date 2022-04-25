#include "wektor.hh"

wektor::wektor()
{
    for (double &wsp : this->_wsp)
        wsp = 0;
}

ostream & operator << (ostream &ostr, const wektor &wek)
{
    for (double liczba : wek._wsp)
        ostr << liczba;
    return ostr;
}

istream & operator >> (istream &istr, wektor &wek)
{
    for (double &liczba : wek._wsp)
        istr >> liczba;
    return istr;
}


wektor::wektor & operator+ (wektor wek2)
{
    for (int i=0; i < ROZMIAR; i++) {

    }
}



wektor::wektor & operator- (wektor wek2);
wektor::wektor & operator* (wektor wek2);
wektor::wektor & operator/ (wektor wek2);
