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

ll dp[420][420];
vector<ll> sum;
bool visited[3300][3300];
//半開区間[l, r)
ll dfs(int l, int r){
  if(l>= r || r <= l)return 0LL;
  if(visited[l][r])return dp[l][r];
  visited[l][r] = true;
  ll ans = 1e18;
  for (int mid = l + 1; mid <= r; mid++){
    chmin(ans, dfs(l, mid - 1) + dfs(mid, r));
  }
  ans += sum[r + 1] - sum[l];
  return dp[l][r] = ans;
}

int main() {
  int n;
  cin >> n;
  vector<ll> a(n);
  sum = vector<ll>(n + 1);
  rep(i, n){
    cin >> a[i];
    sum[i + 1] = sum[i] + a[i];
  }
  cout << dfs(0, n-1) << endl;
}