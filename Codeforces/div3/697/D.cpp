#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const int INF = (1 << 30);

void solve() {
  int n;
  ll m;
  cin >> n >> m;
  vector<int> B(n);
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  rep(i, n) cin >> B[i];
  ll sum = accumulate(ALL(A), 0LL);
  if(sum < m){
    cout << -1 << endl;
    return;
  }
  vector<ll> one, two;
  int ans = INF;
  rep(i, n){
    if(B[i] == 1){
      one.eb(A[i]);
    }else{
      two.eb(A[i]);
    }
  }
  sort(ALL(one), greater<ll>{});
  sort(ALL(two), greater<ll>{});
  vector<ll> one_sum(one.size() + 1), two_sum(two.size() + 1);
  rep(i, one.size()){
    one_sum[i + 1] = one_sum[i] + one[i];
  }
  rep(i, two.size()){
    two_sum[i + 1] = two_sum[i] + two[i];
  }
  rep(i, one_sum.size()){
    ll num = one_sum[i];
    if(num >= m){
      chmin(ans, i);
      continue;
    }
    int k = lower_bound(ALL(two_sum), m - num) - two_sum.begin();
    if(k == two_sum.size()){
      continue;
    }
    if(num + two_sum[k] < m)continue;
    chmin(ans, i + 2 * k);
  }
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}