#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
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
using mint = modint998244353;

mint dp[5001][5002];

int main() {
  int n;
  cin >> n;
  vector<P> AB(n);
  vector<int> A(n), B(n);
  rep(i, n) cin >> AB[i].fi;
  rep(i, n) cin >> AB[i].se;
  sort(ALL(AB));
  rep(i, n){
    A[i] = AB[i].fi;
    B[i] = AB[i].se;
  }
  dp[0][0] = 1;
  mint ans = 0;
  rep(i, n)rep(j, 5001){
    dp[i+1][j] += dp[i][j];
    if(j + B[i] > 5000)continue;
    dp[i + 1][j + B[i]] += dp[i][j];
    if(j + B[i] <= A[i])ans += dp[i][j];
  }
  cout << ans.val() << endl;
}