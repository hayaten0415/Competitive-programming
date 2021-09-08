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
using mint = modint1000000007;
mint dp[1007][1007];
int cnt_A[1010], cnt_B[1010];
vector<int> val_A, val_B;

void init(){
  dp[0][0] = 1;
  rep(i, 1007)rep(j, 1007){
    if(i == 0 || j == 0){
      dp[i][j] = 1;
      continue;
    }
    if(i == 1 || j == 1){
      dp[i][j] = 1;
      continue;
    }
    if(j - i >= 0){
      dp[i][j] += dp[i][j - i];
    }
    dp[i][j] += dp[i-1][j];
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  int sum_A = 0;
  int sum_B = 0;
  rep(i, n){
    int a;
    cin >> a;
    cnt_A[a]++;
    sum_B += a;
  }
  rep(i, m){
    int b;
    cin >> b;
    cnt_B[b]++;
    sum_A += b;
  }
  rep(i, 1001){
    if(cnt_A[i]) val_A.push_back(cnt_A[i]);
    if(cnt_B[i]) val_B.push_back(cnt_B[i]);
  }
  init();
  auto f = [&](vector<int> &A, int sum) -> mint {
    vector<vector<mint>> dp2(110, vector<mint>(1007, 0));
    dp2[0][0] = 1;
    int S = A.size();
    rep(i, S)rep(j, sum+ 1)rep(k, j + 1){
      dp2[i + 1][j] += (dp2[i][k] * dp[A[i]][j - k]);
    }
    return dp2[S][sum];
  };
  mint ans = 1;
  ans *= f(val_A, sum_A);
  ans *= f(val_B, sum_B);
  cout << ans.val() << endl;
}