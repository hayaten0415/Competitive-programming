#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
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
template <typename T>
const auto INF = numeric_limits<T>::max()/2;

ll dp[41][401][401];

int main() {
  rep(i, 41) rep(j, 401) rep(k, 401) dp[i][j][k] = INF<ll>;
  dp[0][0][0] = 0;
  int n, ma, mb;
  cin >> n >> ma >> mb;
  vector<int> A(n), B(n);
  vector<ll> C(n);
  rep(i, n) cin >> A[i] >> B[i] >> C[i];
  rep(i, n)rep(j, 401)rep(k, 401){
    chmin(dp[i + 1][j][k], dp[i][j][k]);
    if(j + A[i] <= 400 && k + B[i] <= 400){
      chmin(dp[i + 1][j + A[i]][k + B[i]], dp[i][j][k] + C[i]);
    }
  }
  ll ans = INF<ll>;
  rep(i, 401)rep(j, 401){
    if(i== 0 || j == 0)continue;
    int bb = ma * j;
    int aa = mb * i;
    if(aa == bb)chmin(ans, dp[n][i][j]);
  }
  if(ans == INF<ll>)ans = -1;
  cout << ans << endl;
}