#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  string s, t;
  cin >> s >> t;
  int ans = 0;
  rep(i, s.size()){
    if(s[i] != t[i])ans++;
  }
  cout << ans << endl;
}