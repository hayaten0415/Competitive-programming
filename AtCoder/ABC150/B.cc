#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  string s;
  int ans = 0;
  cin >> n >> s;
  rep(i, n - 2) {
    if(s.at(i) == 'A' && s.at(i + 1) == 'B' && s.at(i + 2) == 'C') {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}