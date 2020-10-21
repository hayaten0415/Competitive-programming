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

ll dp[110][110];
ll mat[110][2];
bool visited[110][110];
//半開区間[l, r)
ll dfs(int l, int r){
  if(l+1>= r)return 0LL;
  if(visited[l][r])return dp[l][r];
  visited[l][r] = true;
  ll ans = 1e18;
  for (int mid = l + 1; mid < r; mid++){
    chmin(ans, dfs(l, mid) + dfs(mid, r) + mat[l][0] * mat[mid][0] * mat[r - 1][1]);
  }
  return dp[l][r] = ans;
}

int main() {
  int n;
  cin >> n;
  rep(i, n){
    cin >> mat[i][0] >> mat[i][1];
  }
  cout << dfs(0, n) << endl;
}