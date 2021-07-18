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
using PL = pair<long long, P>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL <<60);



int main() {
  int h, w;
  ll c;
  cin >> h >> w >> c;
  vector<vector<ll>> A(h, vector<ll>(w));
  rep(i, h) rep(j, w){
    cin >> A[i][j];
  }
  ll ans = INF;
  rep(d, 2){
    vector<vector<ll>> B1(h, vector<ll>(w));
    vector<vector<ll>> B2(h, vector<ll>(w));
    vector<vector<ll>> mn;
    rep(i, h)rep(j, w){
      B1[i][j] = A[i][j] + c * (i + j);
      B2[i][j] = A[i][j] - c * (i + j);
    }
    mn = B2;
    rep(i, h)rep(j, w){
      if(i > 0){
        chmin(mn[i][j], mn[i-1][j]);
      }
      if(j > 0){
        chmin(mn[i][j], mn[i][j - 1]);
      }
    }
    rep(i, h)rep(j, w){
      if(i > 0){
        chmin(ans, mn[i-1][j] + B1[i][j]);
      }
      if(j > 0){
        chmin(ans, mn[i][j-1] + B1[i][j]);
      }
    }

    reverse(ALL(A));
  }
  cout << ans << endl;
}