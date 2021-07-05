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
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL << 60);

int main() {
  ll p;
  cin >> p;
  vector<ll> a(10);
  a[0] = 1;
  rep(i, 9){
    a[i + 1] = a[i] * (i + 2);
  }
  vector<ll> dp(p + 1, INF);
  dp[0] = 0;
  rep(i, p+1){
    rep(j, 10){
      if(i - a[j] >= 0){
        chmin(dp[i], dp[i - a[j]] + 1);
      }
    }
  }
  cout << dp[p] << endl;
}