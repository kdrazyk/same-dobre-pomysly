#include "main.hh"

int main(){

  string data = "1 2 3";
  stringstream sData;
  sData.str (data);

  wektor test;
  sData >> test;
  cout << endl;
  cout << test << endl;

}
