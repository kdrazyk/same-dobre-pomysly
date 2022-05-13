#pragma once

#include <iostream>
#include <iomanip>
#include "smacierz.hh"

#define RZAD_WIELK_LICZB 3

template<typename sTyp, int sWymiar>
class sukladRownanLiniowych {
private:
    smacierz<sTyp,sWymiar> _macierzParametrow;
    swektor<sTyp,sWymiar> _wektorRozwiazan;

public:
    swektor<sTyp,sWymiar> rozwiazanie() const;
    swektor<sTyp,sWymiar> wektorBledu() const;

    const smacierz<sTyp,sWymiar> & getM() const {return this->_macierzParametrow;}
    const swektor<sTyp,sWymiar> & getW() const {return this->_wektorRozwiazan;}

    smacierz<sTyp,sWymiar> & setM() {return this->_macierzParametrow;}
    swektor<sTyp,sWymiar> & setW() {return this->_wektorRozwiazan;}

};

template<typename sTyp, int sWymiar>
istream & operator >> (istream &istr, sukladRownanLiniowych<sTyp,sWymiar> &url)
{
    istr >> url.setM() >> url.setW();
    return istr;
}

template<typename sTyp, int sWymiar>
ostream & operator << (ostream &ostr, const sukladRownanLiniowych<sTyp,sWymiar> &url)
{
    for (int i=0; i < sWymiar; ++i) {
        ostr << "|";
        for (int j=0; j < sWymiar; ++j)
            ostr << setw(RZAD_WIELK_LICZB) << url.getM()[j][i];
        ostr << "||x_" << i+1 << "|";
        ostr << (sWymiar/2 == i ? "=" : " ");
        ostr << "|" << setw(RZAD_WIELK_LICZB) << url.getW()[i] << "|" << endl;
    }
    return ostr;
}

template<typename sTyp, int sWymiar>
swektor<sTyp,sWymiar> sukladRownanLiniowych<sTyp,sWymiar>::rozwiazanie() const
{
    return this->_macierzParametrow.odwrotna() * this->_wektorRozwiazan;
}

template<typename sTyp, int sWymiar>
swektor<sTyp,sWymiar> sukladRownanLiniowych<sTyp,sWymiar>::wektorBledu() const
{
    return this->_macierzParametrow * this->rozwiazanie() - this->_wektorRozwiazan;
}
