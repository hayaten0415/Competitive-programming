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

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> X(2 * n);
  rep(i, 2 * n) cin >> X[i];
  int n2 = (1 << 2 * n);
  vector<set<ll>> dp(n2);
  rep(bit, n2){
    if(popcount(bit) != 2)continue;
    vector<ll> tmp;
    rep(i, n2){
      if(bit & (1 << i)){
        tmp.pb(X[i]);
      }
    }
    dp[bit].insert(min(tmp[0], tmp[1]));
  }
  dp[0].insert(0);
  rep(S, n2){
    if(popcount(S) % 2 != 0)continue;
    for (int T=S; T> 0; T=(T-1)&S) {
      if(popcount(T) % 2 != 0)continue;
      int rest = S ^ T;
      for(auto d : dp[rest]){
        for(auto s : dp[T]){
          dp[S].insert(d + s);
        }
      }
    }
  }
  if(dp[n2-1].find(k) != dp[n2-1].end()){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}