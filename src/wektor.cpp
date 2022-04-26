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


wektor wektor::operator+ (const wektor &wektor2) const
{
    wektor wynik;
    for (int i=0; i < ROZMIAR; ++i)
        wynik[i] = this->_wsp[i] + wektor2._wsp[i];
    return wynik;
}

wektor wektor::operator- (const wektor &wektor2) const
{
    wektor wynik;
    for (int i=0; i < ROZMIAR; ++i)
        wynik[i] = this->_wsp[i] - wektor2._wsp[i];
    return wynik;
}

wektor wektor::operator* (double liczba) const
{
    wektor wynik;
    for (int i=0; i < ROZMIAR; ++i)
        wynik[i] = this->_wsp[i] * liczba;
    return wynik;
}


wektor wektor::operator/ (double liczba) const
{
    wektor wynik;
    for (int i=0; i < ROZMIAR; ++i)
        wynik[i] = this->_wsp[i] / liczba;
    return wynik;
}
