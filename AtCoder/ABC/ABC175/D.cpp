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
const ll INF = (1LL << 60);

int main() {
  int n;
  ll k;
  cin >> n >> k;
  vector<vector<int>> next(60, vector<int>(n));
  vector<vector<ll>> sum(60, vector<ll>(n));
  vector<vector<ll>> all_max_sum(60, vector<ll>(n));
  rep(i, n){
    cin >> next[0][i];
    next[0][i]--;
  }
  rep(i, n){
    cin >> sum[0][i];
    all_max_sum[0][i] = sum[0][i];
  }
  for (int d = 0; d + 1 < 60; d++){
    rep(i, n){
      next[d + 1][i] = next[d][next[d][i]];
      sum[d + 1][i] = sum[d][i] + sum[d][next[d][i]];
      all_max_sum[d + 1][i] = max(all_max_sum[d][i], sum[d][i] + all_max_sum[d][next[d][i]]);
    }
  }
  ll ans = -INF;
  rep(i, n){
    int now = i;
    ll sum_tmp = 0;
    for (int d = 0; d < 60; d++){
      if(k & (1LL << d)){
        ans = max(ans, sum_tmp + all_max_sum[d][now]);
        sum_tmp += sum[d][now];
        now = next[d][now];
      }
    }
  }
  cout << ans << endl;
}