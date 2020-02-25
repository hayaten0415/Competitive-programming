#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
  int n;
  string s;
  cin >> n >> s;
  bool cond = true;
  for (int i = 0; i < n / 2; i++){
    if (n % 2 != 0){
      cond = false;
      break;
    }
    if(s.at(i) != s.at(n / 2 + i)) {
      cond = false;
      break;
    }
  }
  if(n == 1) cond = false;
  cout << (cond? "Yes" : "No") << endl;
  return 0;
}