#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int INF = (1 << 20);

int op(int a, int b) { return min(a, b); }
int e() { return int(1e9) + 1; }

int main() {
  int n, m;
  string s;
  cin >> n >> m >> s;
  vector<int> dp(n + 1, INF);
  dp[n] = 0;
  segtree<int, op, e> seg(dp);
  for (int i = n- 1; i >= 0; i--){
    if(s[i] == '1')continue;
    int right = min(i+m+1, n+1);
    int left = i + 1;
    chmin(dp[i], seg.prod(left, right) + 1);
    seg.set(i, dp[i]);
  }
  if(dp[0] ==INF){
    cout << -1 << endl;
    return 0;
  }
  int next = 1;
  int now = n - 1;
  int rec = -1;
  int pre = n;
  vector<int> ans;
  while (now >=0){
    if(dp[now] == next)rec = now;
    else if(dp[now] == next+1){
      ans.emplace_back(pre - rec);
      pre = rec;
      now = pre;
      next++;
    }
    now--;
  }
  ans.emplace_back(pre - 0);
  reverse(ALL(ans));
  rep(i, dp[0]){
    cout << ans[i] << (i == dp[0]-1 ? "\n" : " ");
  }
}