#include <iostream>
#include "sukladRownanLiniowych.hh"

void numeracjaRozwiazan(int rozmiar)
{
    cout << "Rozwiazanie x = [";
    for (int i=1; i <= rozmiar; ++i)
        cout << "x_" << i << (i==rozmiar ? ']' : ',');
    cout << endl;
}

int main(){
    char typ;
    sukladRownanLiniowych<liczba_zespolona,ROZMIAR> urlZ;
    sukladRownanLiniowych<double,ROZMIAR> urlR;

    cin >> typ;
    switch (typ) {
    case 'r':
        cin >> urlR;
        cout << "Uklad rownan:" << endl;
        cout << urlR << endl;
        numeracjaRozwiazan(ROZMIAR);
        cout << urlR.rozwiazanie() << endl;
        cout << "Wektor bledu Ax-b = " << urlR.wektorBledu() << endl;
        cout << "Dlugosc wektora bledu: " << scientific << setprecision(1) << urlR.wektorBledu().dlugosc() << endl;
        break;
    case 'z':
        cin >> urlZ;
        cout << "Uklad rownan:" << endl;
        cout << urlZ << endl;
        numeracjaRozwiazan(ROZMIAR);
        cout << urlZ.rozwiazanie() << endl;
        cout << "Wektor bledu Ax-b = " << urlZ.wektorBledu() << endl;
        cout << "Dlugosc wektora bledu: " << scientific << setprecision(1) << urlZ.wektorBledu().dlugosc() << endl;
        break;
    default:
        cout << "Niepoprawne dane wejsciowe." << endl;
    }
}
