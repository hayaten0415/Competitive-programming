#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
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
  int n;
  cin >> n;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  ll ans = INF;
  for (int bit = 0; bit < (1 << (n - 1)); bit++){
    vector<ll> tmp;
    ll num = 0;
    rep(i, n){
      num = (num | A[i]);
      if(bit & (1 << i)){
        tmp.emplace_back(num);
        num = 0;
      }
    }
    tmp.emplace_back(num);
    ll res = 0;
    for(auto d : tmp){
      res = (res ^ d);
    }
    chmin(ans, res);
  }
  cout << ans << endl;
}