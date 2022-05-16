#include "LZespolona.hh"


liczba_zespolona::liczba_zespolona()
{
  this->re = 0;
  this->im = 0;
}

liczba_zespolona::liczba_zespolona(double r, double i)
{
  this->re = r;
  this->im = i;
}

liczba_zespolona liczba_zespolona::operator + (liczba_zespolona lz) const
{
  liczba_zespolona wynik;
  wynik.re = this->re + lz.re;
  wynik.im = this->im + lz.im;
  return wynik;
}

liczba_zespolona liczba_zespolona::operator - (liczba_zespolona lz) const
{
  liczba_zespolona wynik;
  wynik.re = this->re - lz.re;
  wynik.im = this->im - lz.im;
  return wynik;
}

liczba_zespolona liczba_zespolona::operator * (liczba_zespolona lz) const
{
  liczba_zespolona wynik;
  wynik.re = this->re * lz.re - this->im * lz.im;
  wynik.im = this->re * lz.im + this->im * lz.re;
  return wynik;
}

liczba_zespolona liczba_zespolona::operator / (liczba_zespolona lz) const
{
  liczba_zespolona wynik;
  double modul2 = lz.re * lz.re + lz.im * lz.im;
  wynik.re = (this->re * lz.re + this->im * lz.im) / modul2;
  wynik.im = (this->im * lz.re - this->re * lz.im) / modul2;
  return wynik;
}

liczba_zespolona liczba_zespolona::operator = (double liczba)
{
    this->re = liczba;
    this->im = 0;
    return *this;
}

// Porownanie dwoch liczb zespolonych
bool liczba_zespolona::operator == (liczba_zespolona lz) const
{
  return (this->re == lz.re) and (this->im == lz.im);
}

// Wypisanie liczby zespolonej w formacie (a+bi)
ostream & operator << (ostream &ostr, liczba_zespolona lz)
{
  ostr << "(" << lz.re << showpos << lz.im << noshowpos << "i)";
  return ostr;
}

// Wczytanie liczby zespolonej w formacie (a+bi)
istream & operator >> (istream &istr, liczba_zespolona &lz)
{
  double re, im;
  char znak;

  istr >> znak;
  if (znak != '(')
    istr.setstate(ios::failbit);
  istr >> re;
  istr >> im;
  istr >> znak;
  if (znak != 'i')
    istr.setstate(ios::failbit);
  istr >> znak;
  if (znak != ')')
    istr.setstate(ios::failbit);

  if (!istr.fail()) {
    lz.re = re;
    lz.im = im;
  }

  return istr;
}


liczba_zespolona liczba_zespolona::operator += (liczba_zespolona lz)
{
    this->re += lz.re;
    this->im += lz.im;
    return *this;
}
