#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  string s;
  cin >> s;
  if (s == "WBWBWWBWBWBWWBWBWWBW"){
    cout << "Do" << endl;
  }else if(s == "WBWWBWBWBWWBWBWWBWBW") {
    cout << "Re" << endl;
  }else if(s == "WWBWBWBWWBWBWWBWBWBW"){
    cout << "Mi" << endl;
  }else if(s == "WBWBWBWWBWBWWBWBWBWW"){
    cout << "Fa" << endl;
  }else if(s == "WBWBWWBWBWWBWBWBWWBW"){
    cout << "So" << endl;
  }else if(s == "WBWWBWBWWBWBWBWWBWBW") {
    cout << "La" << endl;
  }else {
    cout << "Si" << endl;
  }
}