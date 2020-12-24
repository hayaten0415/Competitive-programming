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
const int cost[10] = {20, 2, 5, 5, 4, 5, 6, 3, 7, 6};
const int INF = (1 << 20);

int main(){
  int n, m;
  cin >> n >> m;
  vector<int> c(m);
  vector<P> dp(n + 1, make_pair(-INF, 0));
  rep(i, m) cin >> c[i];
  sort(ALL(c), greater{});
  dp[0] = {0, 0};
  rep(i, n+1){
    rep(j, m){
      if(i - cost[c[j]] >= 0){
        chmax(dp[i], make_pair(dp[i - cost[c[j]]].first + 1, c[j]));
      }
    }
  }
  vector<int> ans;
  int now_cost = n;
  while (now_cost > 0){
    ans.emplace_back(dp[now_cost].second);
    now_cost -= cost[dp[now_cost].second];
  }
  sort(ALL(ans), greater{});
  rep(i, ans.size()){
    cout << ans[i] << (i == ans.size() - 1 ? "\n" : "");
  }
}
