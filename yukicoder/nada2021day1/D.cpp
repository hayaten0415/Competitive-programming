#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, m;
  cin >> n >> m;
  ll ans = (1LL << 50);
  vector<vector<ll>> A(n, vector<ll>(n));
  rep(i, n) rep(j, n) cin >> A[i][j];
  vector<ll> sum = sum_result(A, n);
  for (int bit = 1; bit < (1 << (n + 2)); bit++){
    int d = __builtin_popcount(bit);
    vector<vector<ll>> a = A;
    if(d + n < m)continue;
    ll res = 0;
    rep(i, n){
      if(bit & (1 << i)){
        rep(j, n){
          res += a[j][i];
          a[j][i] = 0;
        }
      }
    }
    if(bit & (1 << n)){
      rep(j, n){
        res += a[j][j];
        a[j][j] = 0;
      }
    }
    if(bit & (1 << (n + 1))){
      rep(j, n){
        res += a[j][n-1-j];
        a[j][n-1-j] = 0;
      }
    }
    if(d == m){
      chmin(ans, res);
      continue;
    }
    vector<int> row(n);
    rep(i, n){
      rep(j, n) row[i] += a[i][j];
    }
    sort(ALL(row));
    rep(i, m - d) res += row[i];
    chmin(ans, res);
  }
  cout << ans << endl;
}