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
template <typename T>
const auto INF = numeric_limits<T>::max();

int main() {
  int n, k;
  cin >> n >> k;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  vector<ll> res;
  auto dfs = [&](auto &&self, int cn, int s, ll sum) -> void{
    if(cn == k){
      res.pb(sum);
      return;
    }
    for(int i = s; i < n; i++){
      self(self, cn + 1, i + 1, sum + A[i]);
    }
    return;
  };
  dfs(dfs, 0, 0, 0LL);
  int d = res.size();
  vector<ll> num(20);
  num[0] = 1;
  num[1] = 5;
  for (int i = 2; i < 20; i++){
    num[i] = num[i - 2] * 10;
  }
  ll ans = INF<ll>;
  rep(i, d){
    ll tmp = 0;
    while (res[i]){
      int a = upper_bound(ALL(num), res[i]) - num.begin();
      ll b = res[i] / num[a - 1];
      tmp += b;
      res[i] -= (num[a - 1] * b);
    }
    chmin(ans, tmp);
  }
  cout << ans << endl;
}