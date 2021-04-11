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
const int INF = (int)1e9 + 1;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> X(n), Y(n);
  rep(i, n) cin >> X[i];
  rep(i, n) cin >> Y[i];
  sort(ALL(X));
  vector<int> dp1(n);
  rep(i, n) dp1[i] = i + 1 - (lower_bound(ALL(X), X[i] - k) - X.begin());
  vector<int> dp2 = dp1;
  rep(i, n - 1) chmax(dp2[i + 1], dp2[i]);
  vector<int> dp3(n);
  rep(i, n){
    int d = lower_bound(ALL(X), X[i] - k) - X.begin();
    if(d == 0){
      dp3[i] = dp1[i];
    }else{
      dp3[i] = dp1[i] + dp2[d - 1];
    }
  }
  int ans = 0;
  rep(i, n) chmax(ans, dp3[i]);
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}