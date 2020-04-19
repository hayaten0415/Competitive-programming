#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
  string s;
  int n;
  cin >> n >> s;
  rep(i,s.length()) {
    int a = s[i] - 'A';
    a = (a + n) % 26;
    char str = 'A' + a;
    cout << str;
  }
  cout << endl;
  return 0;
}