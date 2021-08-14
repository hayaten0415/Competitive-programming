#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
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
  int n;
  cin >> n;
  vector<ll> S(n), T(n);
  rep(i, n) cin >> S[i];
  rep(i, n) cin >> T[i];
  rep(i, n) S.pb(S[i]);
  rep(i, n) T.pb(T[i]);
  vector<ll> ans(2 * n, INF<ll>);
  ans[0] = T[0];
  rep(i, 2 * n - 1){
    chmin(ans[i + 1], ans[i] + S[i]);
    chmin(ans[i + 1], T[i+1]);
  }
  rep(i, n){
    cout << min(ans[i], ans[i+ n]) << endl;
  }
}