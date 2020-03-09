#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
  string s;
  bool cond = true;
  cin >> s;
  rep(i ,s.size()) {
    if(i % 2 == 0) {
      if(s.at(i) == 'R' || s.at(i) == 'U' || s.at(i) == 'D'){
        continue;
      } else {
        cond = false;
        break;
      }
    }else {
      if(s.at(i) == 'L' || s.at(i) == 'U' || s.at(i) == 'D') {
        continue;
      } else {
        cond = false;
        break;
      }
    }
  }
  cout << (cond ? "Yes" : "No") << endl;
  return 0;
}