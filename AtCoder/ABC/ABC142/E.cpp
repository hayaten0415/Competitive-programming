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
const int INF = (1 << 30);

int main() {
  int N, M;
  cin >> N >> M;
  int n2 = 1 << N;
  vector<int> dp(n2, INF);
  vector<int> cost(M), key(M);
  dp[0] = 0;
  rep(i, M){
    int b;
    cin >> cost[i] >> b;
    rep(j, b){
      int c;
      cin >> c;
      c--;
      key[i] += (1 << c);
    }
  }
  rep(i, n2){
    rep(j, M){
      if((i & key[j]) == key[j])continue;
      chmin(dp[i | key[j]], dp[i] + cost[j]);
    }
  }
  if (dp[n2 - 1] == INF){
    cout << -1 << endl;
  }else {
    cout << dp[n2 - 1] << endl;
  }
}