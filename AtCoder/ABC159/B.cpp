#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  bool cond = true;
  cin >> s;
  rep(i,s.size() / 2){
    if (s[i] != s[s.size() - 1 - i]) {
      cond = false;
    }
  }
  rep(i, s.size() / 2){
    if (s[i] != s[s.size() / 2 - 1 - i]){
      cond = false;
    }
  }
  rep(i, s.size() / 2){
    if (s[i + s.size() / 2 + 1] != s[s.size() - 1 - i]){
      cond = false;
    }
  }
  cout << (cond? "Yes":"No")<< endl;
  return 0;
}