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
      if(s.at(i) == 'h') {
        continue;
      } else {
        cond = false;
        break;
      }
    }else {
      if(s.at(i) == 'i') {
        continue;
      }else {
        cond = false;
        break;
      }
    }
  }
  if (s.size() % 2 == 1){
    cond = false;
  }
  cout << (cond ? "Yes" : "No") << endl;
  return 0;
}