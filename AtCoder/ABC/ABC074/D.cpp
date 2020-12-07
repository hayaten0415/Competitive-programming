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

int main() {
  int n;
  cin >> n;
  vector<vector<ll>> dist(n, vector<ll>(n));
  rep(i, n){
    rep(j, n){
      cin >> dist[i][j];
    }
  }
  vector<vector<ll>> tmp = dist;
  vector<vector<bool>> flag(n, vector<bool>(n,true));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)   
      for (int k = 0; k < n; k++) 
        tmp[j][k] = min(tmp[j][k], tmp[j][i] + tmp[i][k]);
  if(tmp != dist){
    cout << -1 << endl;
    return 0;
  }
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      for (int k = 0; k < n; k++)
        if (dist[j][k] == dist[j][i] + dist[i][k] && j != i && k != i)flag[j][k] = false;

  ll ans = 0;
  rep(i, n){
    for (int j = i + 1; j < n; j++){
      if(flag[i][j])ans+= dist[i][j];
    }
  }
  cout << ans << endl;
}