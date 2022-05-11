#include "main.hh"

int main(){
    ukladRownanLiniowych url;

    swektor<double, ROZMIAR> testw;

    cout << testw << endl;



      cin >> url;
      cout << "Uklad rownan:" << endl;
      cout << url << endl;
      cout << "Rozwiazanie x = [x_1, x_2, x_3]" << endl;
      cout << url.rozwiazanie() << endl;
      cout << "Wektor bledu Ax-b = " << url.wektorBledu() << endl;
      cout << "Dlugosc wektora bledu: " << url.wektorBledu().dlugosc() << endl;




}
