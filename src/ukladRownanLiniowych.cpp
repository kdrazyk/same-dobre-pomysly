#include "ukladRownanLiniowych.hh"

istream & operator >> (istream &istr, ukladRownanLiniowych &url)
{
    char typ;  // wstawka tymczasowa
    istr >> typ >> url._macierzParametrow >> url._wektorRozwiazan;
    return istr;
}

ostream & operator << (ostream &ostr, const ukladRownanLiniowych &url)
{
    for (int i=0; i < ROZMIAR; i++) {
        ostr << "|";
        for (int j=0; j < ROZMIAR; j++)
            ostr << setw(RZAD_WIELK_LICZB) << url._macierzParametrow[j][i];
        ostr << "||x_" << i+1 << "|";
        ostr << (ROZMIAR/2 == i ? "=" : " ");
        ostr << "|" << setw(RZAD_WIELK_LICZB) << url._wektorRozwiazan[i] << "|" << endl;
    }
    return ostr;
}

swektor<double,ROZMIAR> ukladRownanLiniowych::rozwiazanie() const
{
    return this->_macierzParametrow.odwrotna() * this->_wektorRozwiazan;
}

swektor<double,ROZMIAR> ukladRownanLiniowych::wektorBledu() const
{
    return this->_macierzParametrow * this->rozwiazanie() - this->_wektorRozwiazan;
}
