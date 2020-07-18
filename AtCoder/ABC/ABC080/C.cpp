#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  ll ans = -1000000000000000;
  vector<vector<int>> F(n, vector<int>(10));
  vector<vector<ll>> P(n, vector<ll>(11));
  rep(i, n){
    rep(j, 10){
      cin >> F[i][j];
    }
  }
  rep(i, n){
    rep(j, 11){
      cin >> P[i][j];
    }
  }
  for (int bit = 1; bit < (1 << 10); bit++){
    vector<int> d(10,0);
    ll tmp = 0;
    rep(i,10){
      if(bit & (1 << i)){
        d[i] = 1;
      }
    }
    rep(i, n){
      int cn = 0;
      rep(j, 10){
        if(d[j] == 1 && F[i][j] == 1)cn++;
      }
      tmp += P[i][cn];
    }
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}