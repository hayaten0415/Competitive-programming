#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int a, p;
  string s;
  cin >> a >> p >> s;
  //大文字変換
  //小文字変換の場合は0x20を引く
  s[p - 1] = s[p - 1] + 0x20;
  cout << s << endl;
  return 0;
}