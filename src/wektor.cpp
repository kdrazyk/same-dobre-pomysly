#include "wektor.hh"

wektor::wektor()
{
    for (double &wsp : this->_wsp)
        wsp = 0;
}

ostream & operator << (ostream &ostr, const wektor &wek)
{
    ostr << "[";
    for (int i=0; i < ROZMIAR; ++i) {
        ostr << setw(SZEROKOSC) << setprecision(PRECYZJA) << wek._wsp[i];
        ostr << (i==ROZMIAR-1 ? "" : ",");
    }
    ostr << "]";
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

double wektor::iloczynSkalarny(const wektor &wek2) const
{
    double wynik = 0;
    for (int i=0; i < ROZMIAR; ++i)
        wynik += this->_wsp[i] * wek2._wsp[i];
    return wynik;
}

double wektor::dlugosc() const
{
    return sqrt(this->iloczynSkalarny(*this));
}
