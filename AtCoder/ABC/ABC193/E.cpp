#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = (1LL << 60);



void solve(){
  ll X, Y, P, Q;
  cin >> X >> Y >> P >> Q;
  ll ans = INF;
  rep(i, Q){
    rep(j, Y){
      auto [a, b] = crt({P + i, X + j}, {P + Q, 2 * (X + Y)});
      if(a == 0 && b == 0)continue;
      chmin(ans, a);
    }
  }
  if(ans == INF){
    cout << "infinity" << endl;
  }else{
    cout << ans << endl;
  }
}

int main() {
  int t;
  cin >> t;
  while(t--)solve();
}