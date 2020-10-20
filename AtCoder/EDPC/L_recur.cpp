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


ll dp[3300][3000];
ll a[3200];
bool visited[3300][3300];
int n;
//半開区間[l, r)
ll dfs(int l, int r){
  if(visited[l][r])return dp[l][r];
  visited[l][r] = true;
  if(l > r || r < l)return 0LL;
  if(l == r)return 0LL;
  if(n % 2 == (r-l) %2){
    return dp[l][r] = max(dfs(l + 1, r) + a[l], dfs(l, r - 1) + a[r-1]);
  }else{
    return dp[l][r] = min(dfs(l + 1, r) - a[l], dfs(l, r - 1) - a[r-1]);
  }
}

int main() {
  cin >> n;
  rep(i, n) cin >> a[i];
  cout << dfs(0, n) << endl;
}