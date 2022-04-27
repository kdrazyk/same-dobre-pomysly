#include "main.hh"

int main(){

    string data = "1 2 3  4 0 6  7 8 9";
    stringstream sData;
    sData.str (data);

    macierz T1;
    sData >> T1;
    T1.macierz_odwrotna();
}
