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

macierz macierz::operator= (const macierz & mKopiowana)
{
    for (int i=0; i < ROZMIAR; ++i)
        for (int j=0; j < ROZMIAR; ++j)
            this->_kol[i][j] = mKopiowana[i][j];

    return *this;
}

void macierz::do_jednostkowej()
{
    for (int i=0; i < ROZMIAR; ++i)
        for (int j=0; j < ROZMIAR; ++j) {
            if (i == j)
                this->_kol[i][j] = 1;
            else
                this->_kol[i][j] = 0;
        }
}


macierz macierz::macierz_odwrotna() const
{
    macierz mOdwrotna, mKopia;
    mKopia = *this;
    mOdwrotna.do_jednostkowej();

    for (int j=0; j < ROZMIAR; ++j)
        for (int i=0; i < ROZMIAR; ++i) {
            int k = (i+j)%3;
            if (mKopia[k][j] != 0) {
                swap(mKopia[k],mKopia[j]);
                swap(mOdwrotna[k],mOdwrotna[j]);
                break;
            }
            else if (i==ROZMIAR-1)
                cout << "BLAD: nie udalo sie ulozyc macierzy" << endl;
        }

    cout << *this << endl;
    cout << mKopia << endl;
    cout << mOdwrotna << endl;


    return mOdwrotna;
}
