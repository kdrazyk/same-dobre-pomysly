#include "main.hh"

int main(){

    string data = "1 2 3  4 0 6  7 8 9     3 5 7";
    stringstream sData;
    sData.str (data);

    wektor W1;
    macierz T1;
    sData >> T1;
    sData >> W1;
    cout << (T1.macierz_odwrotna() * W1);
}
