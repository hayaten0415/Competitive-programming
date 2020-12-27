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
const ll INF = (1 << 30);

int main() {
  int n, c;
  cin >> n >> c;
  vector<vector<ll>> cost(c, vector<ll>(c));
  vector<vector<int>> grid(n, vector<int>(n));
  vector<vector<ll>> color_cost(3, vector<ll>(c));
  rep(i,c){
    rep(j, c) cin >> cost[i][j];
  }
  rep(i, n){
    rep(j, n){
      cin >> grid[i][j];
      grid[i][j]--;
    }
  }
  rep(i, c){
    rep(j, n){
      rep(k, n){
        if(grid[j][k] == i)continue;
        color_cost[(j + k) % 3][i] += cost[grid[j][k]][i];
      }
    }
  }
  ll ans = INF;
  rep(i, c){
    for (int j = i + 1; j < c; j++){
      for (int k = j + 1; k < c; k++){
        vector<int> tmp = {i, j, k};
        do{
          chmin(ans, color_cost[0][tmp[0]] + color_cost[1][tmp[1]] + color_cost[2][tmp[2]]);
        } while (next_permutation(ALL(tmp)));
      }
    }
  }
  cout << ans << endl;
}