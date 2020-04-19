#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
  string s,t;
  int ans = 0;
  cin >> s >> t;
  rep(i , s.size()) {
    if(s.at(i) == t.at(i)){
      ans++;
    }
  }
  cout << ans << endl;
}