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


bool ok(vector<int> &A, int n, ll b){
  vector<vector<bool>> dp(n + 1, vector<bool>(b + 1, false));
  // 初期化
  for (int i = 0; i <= n; i++) {
      dp[i][0] = true;
  }
  // 更新
  for (int i = 0; i < n; i++) {
      for (int k = 0; k <= b; k++) {
          if (k - A[i] >= 0) dp[i + 1][k] = dp[i + 1][k] | dp[i][k - A[i]];
          dp[i + 1][k] = dp[i + 1][k] | dp[i][k];
      }
  }
  return dp[n][b];
}

void solve() {
  int n;
  cin >> n;
  vector<int> A(n), cn(n);
  ll sum = 0;
  rep(i, n){
    cin >> A[i];
    int k = A[i];
    while(k % 2 == 0){
      cn[i]++;
      k /= 2;
    }
    sum += A[i];
  }
  vector<int> ans;
  vector<P> two_cn(n);
  rep(i, n){
    two_cn[i] = {cn[i], i};
  }
  sort(ALL(two_cn));
  vector<int> B = A;
  rep(i, n){
    if(sum % 2 != 0)break;
    bool tmp = ok(B, n - i, sum/2);
    if(!tmp)break;
    int k = 0;
    rep(j, B.size()){
      if(B[j] == A[two_cn[i].second]){
        k = j;
        break;
      }
    }
    ans.pb(two_cn[i].second);
    sum -= A[two_cn[i].second];
    B.erase(B.begin() + k);
  }
  cout << ans.size() << endl;
  rep(i, ans.size()){
    cout << ans[i] + 1 << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  t = 1;
  while(t--) solve();
}