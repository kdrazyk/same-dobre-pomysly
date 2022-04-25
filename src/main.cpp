#include "main.hh"

int main(){

  string data = "1 2 3 4 5 6 7 8 9 11 22 33";
  stringstream sData;
  sData.str (data);

  ukladRownanLiniowych test;
  sData >> test;

  cout << endl;
  cout << test << endl;
}
