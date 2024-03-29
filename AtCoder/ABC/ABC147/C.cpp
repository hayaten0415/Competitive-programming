#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int g[15][15];

int main(){
  int n;
  cin >> n;
  rep(i, n) rep(j, n) g[i][j] = -1;
  rep(i,n){
    int Ai;
    cin >> Ai;
    rep(j,Ai){
      int a, x;
      cin >> a >> x;
      a--;
      g[i][a] = x;
    }
  }
  int ans = 0;
  rep(i, 1<<n){
    vector<int> d(n);
    rep(j,n) if(i>>j&1) {
      d[j] = 1;
    }
    bool ok = true;
    rep(j,n){
      if(d[j]){
        rep(k,n){
          if(g[j][k] == -1) continue;
          if(g[j][k] != d[k]) ok = false;
        }
      }
    }
    if(ok) ans = max(ans, __builtin_popcount(i));
  }
  cout << ans << endl;
}