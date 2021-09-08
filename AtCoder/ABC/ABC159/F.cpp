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
using mint = modint998244353;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max()/2;

mint dp[3020][6020][3];

int main() {
  int n, s;
  cin >> n >> s;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  dp[0][0][0] = 1;
  rep(i, n) {
    for(int j=0;j<=s;j++){
      dp[i+1][j][0] += dp[i][j][0]; 
      dp[i+1][j][1] += dp[i][j][0] + dp[i][j][1];
      dp[i+1][j][2] += dp[i][j][0] + dp[i][j][1] + dp[i][j][2];
      if(j + A[i] <= s){
        (dp[i+1][j+A[i]][1] += dp[i][j][0] + dp[i][j][1]);
        (dp[i+1][j+A[i]][2] += dp[i][j][0] + dp[i][j][1]);
      }
    }
  }
  cout << dp[n][s][2].val() << endl;
}