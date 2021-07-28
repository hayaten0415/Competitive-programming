#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


void solve() {
  vector<ll> A(3);
  rep(i, 3) cin >> A[i];
  sort(ALL(A));
  ll ans = LONG_MAX;
  rep(i, 3){
    rep(j, 3){
      rep(d, 3){
        vector<ll> tmp = A;
        if(i == 1)tmp[0] += 1;
        if(i == 2)tmp[0] -= 1;
        if(j == 1)tmp[1] += 1;
        if(j == 2)tmp[1] -= 1;
        if(d == 1)tmp[2] += 1;
        if(d == 2)tmp[2] -= 1;
        ll res = abs(tmp[0] - tmp[1]) + abs(tmp[2] - tmp[1]) + abs(tmp[2] - tmp[0]);
        chmin(ans, res);
      }
    }
  }
  cout << ans<< endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}