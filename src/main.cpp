#include "main.hh"

int main(){

    string data = "0 0 1  1 1 1  1 0 0";
    stringstream sData;
    sData.str (data);

    macierz T1;
    sData >> T1;
    T1.macierz_odwrotna();
}
