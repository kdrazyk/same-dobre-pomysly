#pragma once

#include <iostream>
#include <iomanip>
#include "swektor.hh"

#define RZAD_WIELK 6

using namespace std;

template<typename sTyp, int sWymiar>
class smacierz {
private:
        swektor<sTyp,sWymiar> _kol[sWymiar];

public:



    const swektor<sTyp,sWymiar> & operator[] (int el) const {return this->_kol[el];}
    swektor<sTyp,sWymiar> & operator[] (int el) {return this->_kol[el];}

    smacierz<sTyp, sWymiar> operator= (const smacierz<sTyp, sWymiar> & mKopiowana);


    swektor<sTyp, sWymiar> operator* (const swektor<sTyp, sWymiar> &wek) const;

    void do_jednostkowej();
    smacierz<sTyp,sWymiar> odwrotna() const;
};

template<typename sTyp, int sWymiar>
istream & operator >> (istream &istr, smacierz<sTyp, sWymiar> &mac)
{
    for (int i=0; i < sWymiar; ++i)
        istr >> mac[i];
    return istr;
}

template<typename sTyp, int sWymiar>
ostream & operator << (ostream &ostr, const smacierz<sTyp, sWymiar> &mac)
{
    int i,j;
    for (i=0; i < sWymiar; ++i) {
        for (j=0; j < sWymiar; ++j)
            ostr << setw(RZAD_WIELK) << setprecision(2) << mac[j][i];
        ostr << endl;
    }
    return ostr;
}

template<typename sTyp, int sWymiar>
smacierz<sTyp, sWymiar> smacierz<sTyp, sWymiar>::operator= (const smacierz<sTyp, sWymiar> & mKopiowana)
{
    for (int i=0; i < sWymiar; ++i)
        for (int j=0; j < sWymiar; ++j)
            this->_kol[i][j] = mKopiowana[i][j];
    return *this;
}

template<typename sTyp, int sWymiar>
swektor<sTyp,sWymiar> smacierz<sTyp, sWymiar>::operator* (const swektor<sTyp,sWymiar> &wek) const
{
    swektor<sTyp,sWymiar> wynik;
    int i,j;
    for (i=0; i < sWymiar; ++i)
        for (j=0; j < sWymiar; j++)
            wynik.add(i, wek[j] * this->_kol[j][i]);
    return wynik;
}

template<typename sTyp, int sWymiar>
void smacierz<sTyp,sWymiar>::do_jednostkowej()
{
    int i,j;
    for (i=0; i < sWymiar; ++i)
        for (j=0; j < sWymiar; ++j) {
            if (i == j)
                this->_kol[i][j] = 1;
            else
                this->_kol[i][j] = 0;
        }
}

template<typename sTyp, int sWymiar>
smacierz<sTyp,sWymiar> smacierz<sTyp,sWymiar>::odwrotna() const
{
    smacierz<sTyp,sWymiar> mOdwrotna, mKopia;
    int i,j,k;
    sTyp mnoznik;
    mKopia = *this;
    mOdwrotna.do_jednostkowej();

    for (j=0; j < sWymiar; ++j)
        for (i=0; i < sWymiar; ++i) {
            k = (i+j)%sWymiar;
            if (mKopia[k][j] != 0) {
                swap(mKopia[k],mKopia[j]);
                swap(mOdwrotna[k],mOdwrotna[j]);
                break;
            }
            else if (i==sWymiar-1) {
                cout << "BLAD: nie udalo sie ulozyc macierzy" << endl;
                exit(-1);
            }

        }

    for (i=0; i < sWymiar; ++i) {
        mnoznik = mKopia[i][i];
        mKopia[i] = mKopia[i] / mnoznik;
        mOdwrotna[i] = mOdwrotna[i] / mnoznik;
        for (j=1; j < sWymiar; ++j) {
            k = (i+j)%sWymiar;
            mnoznik = mKopia[k][i];
            mKopia[k] = mKopia[k] - (mKopia[i] * mnoznik);
            mOdwrotna[k] = mOdwrotna[k] - (mOdwrotna[i] * mnoznik);
        }
    }
    return mOdwrotna;
}
