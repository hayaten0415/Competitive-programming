#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> s(m);
  for (int i = 0; i < m; i++){
    int k;
    cin >> k;
    for (int j = 0; j < k; j++){
      int a;
      cin >> a;
      a--;
      s[i].push_back(a);
    }
  }
  vector<int> p(m);
  ll ans = 0;
  rep(i, m) cin >> p[i];
  for (int bit = 0; bit < (1 << n); bit++){
    bool ok = true;
    rep(i, m){
      int cn = 0;
      for(auto v :s[i]){
        if(bit & (1 << v))cn++;
      }
      if(cn % 2 != p[i]) ok = false;
    }
    if(ok) ans++;
  }
  cout << ans << endl;
}