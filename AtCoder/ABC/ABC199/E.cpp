#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL <<60);
vector<P> check[19];

int main() {
  int n, m;
  cin >> n >> m;
  vector<ll> dp(1 << n);
  rep(i, m){
    int a, b, c;
    cin >> a >> b >> c;
    check[a].eb(P(b, c));
  }
  auto ok = [&](int msk, int d) {
    int b = popcount(msk);
    b++;
    for(auto [s, k] : check[b]){
      int num = 0;
      if(d < s)num++;
      rep(i, n){
        if(msk & (1 << i)){
          if(i < s)num++;
        }
      }
      if(num > k){
        return false;
      }
    }
    return true;
  };
  dp[0] = 1;
  rep(bit, 1 << n){
    rep(i, n){
      if(bit & (1 << i))continue;
      if(ok(bit, i)){
        dp[bit + (1 << i)] += dp[bit];
      }
    }
  }
  cout << dp[(1 << n) - 1] << endl;
}