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
using PP = pair<int, P>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

bool ok[101][60001];
int dp[101][60001];

void solve() {
  int n, r;
  cin >> n >> r;
  vector<P> plus, minus, res;
  rep(i, n){
    int a, b;
    cin >> a >> b;
    if(b >= 0){
      plus.pb({a, b});
    }else{
      minus.pb({a, b});
    }
  }
  sort(plus.begin(), plus.end(), [](P x, P y) {
    if(x.first != y.first){
      return x.first < y.first;
    }else{
      return x.second > y.second;
    }
  });
  int ans = 0;
  for(auto [a, b]: plus){
    if(a <= r){
      r += b;
      ans++;
    }else{
      break;
    }
  }
  for(auto [a, b] : minus){
    res.pb({a, b});
  }
  sort(res.begin(), res.end(), [](P x, P y) {
    return x.first + x.second > y.first + y.second;
  });
  int b = res.size();
  ok[0][r] = true;
  int tmp = 0;
  rep(i, b){
    rep(j, 60001){
      if(!ok[i][j])continue;
      chmax(dp[i + 1][j], dp[i][j]);
      ok[i + 1][j] = true;
      if(res[i].first<= j){
        if(j + res[i].second >= 0){
          chmax(dp[i + 1][j + res[i].second], dp[i][j] + 1);
          ok[i + 1][j + res[i].second] = true;
        }
      }
    }
  }
  for (int j = 0; j <= 60000; j++)if(ok[b][j])chmax(tmp, dp[b][j]);
  chmax(ans, ans + tmp);
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t = 1;
  while(t--) solve();
}