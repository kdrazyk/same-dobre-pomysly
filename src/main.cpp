#include "main.hh"

int main(){

  string data = "1 2 3 4 5 6 7 8 9";
  stringstream sData;
  sData.str (data);

  macierz test;
  sData >> test;
  cout << endl;
  cout << test << endl;

}
