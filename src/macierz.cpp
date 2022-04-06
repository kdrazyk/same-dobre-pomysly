#include "macierz.hh"

macierz::macierz()
{
  for (wektor *&wek : this->kolumny){
    wek = new wektor;
    for (double &liczba : wek->_wsp){
      liczba = 0;
    }
  }
}
