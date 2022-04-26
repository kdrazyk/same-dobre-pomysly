#include "main.hh"

int main(){

    string data = "1 2 3 4 5 6 7 8 9 11 22 33";
    stringstream sData;
    sData.str (data);

    wektor T1, T2;
    sData >> T1;
    sData >> T2;
    cout << T1 << endl;
    cout << T2 << endl;
    cout << T1 + T2 << endl;
    cout << T1 << endl;
    cout << T2 << endl;
}
