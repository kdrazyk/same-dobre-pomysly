#include "macierz.hh"

istream & operator >> (istream &istr, macierz &mac)
{
    for (wektor &wek : mac._kol)
        istr >> wek;
    return istr;
}

ostream & operator << (ostream &ostr, const macierz &mac)
{

    /*
      for (wektor wek : mac._kol)
      ostr << wek << endl;
    */

    int i,j;
    for (i=0; i < ROZMIAR; ++i) {
        for (j=0; j < ROZMIAR; ++j)
            ostr << setw(RZAD_WIELK) << setprecision(2) << mac._kol[j][i];
        ostr << endl;
    }

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
    int i,j,k, mnoznik;
    mKopia = *this;
    mOdwrotna.do_jednostkowej();

    cout << "macierz wejsciowa" << endl;
    cout << mKopia << endl;
    cout << mOdwrotna << endl;

    for (j=0; j < ROZMIAR; ++j)
        for (i=0; i < ROZMIAR; ++i) {
            k = (i+j)%ROZMIAR;
            if (mKopia[k][j] != 0) {
                swap(mKopia[k],mKopia[j]);
                swap(mOdwrotna[k],mOdwrotna[j]);
                break;
            }
            else if (i==ROZMIAR-1)
                cout << "BLAD: nie udalo sie ulozyc macierzy" << endl;
        }

    cout << "po ulozeniu" << endl;
    cout << mKopia << endl;
    cout << mOdwrotna << endl;

    for (i=0; i < ROZMIAR; ++i) {
        mnoznik = mKopia[i][i];
        mKopia[i] = mKopia[i] / mnoznik;
        mOdwrotna[i] = mOdwrotna[i] / mnoznik;

        for (j=1; j < ROZMIAR; ++j) {
            k = (i+j)%ROZMIAR;
            mnoznik = mKopia[k][i];
            mKopia[k] = mKopia[k] - (mKopia[i] * mnoznik);
            mOdwrotna[k] = mOdwrotna[k] - (mOdwrotna[i] * mnoznik);

            //cout << "(i,j): (" << i << "," << j << ")\n";
            //cout << mKopia << endl;
            //cout << mOdwrotna << endl;
        }

        //cout << "(i,j): (" << i << "," << j << ")\n";
        //cout << mKopia << endl;
        //cout << mOdwrotna << endl;
    }

    cout << "po gaussie" << endl;
    cout << mKopia << endl;
    cout << mOdwrotna << endl;


    return mOdwrotna;
}
