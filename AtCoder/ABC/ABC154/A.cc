#include <iostream>
#include <algorithm>
using namespace std;

int main(){
  string s, t;
  int a, b;
  string u;
  cin >> s >> t >> a >> b >> u;
  if(s == u) {
    cout << a - 1 << " " << b << endl;
  } else{
    cout << a << " " << b - 1 << endl;
  }
}
