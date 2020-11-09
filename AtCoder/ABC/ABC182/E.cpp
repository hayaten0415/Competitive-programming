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

bool stone[1502][1502];
bool light[1502][1502];
bool visited[1502][1502];
bool memo[1502][1502];
bool ok[1502][1502];

int H, W, N, M;

bool f(int v, int i, int j){
  if(i < 0 || j < 0 || i >= H || j >= W)return false;
  if(light[i][j])return true;
  if(stone[i][j])return false;
  if(visited[i][j])return memo[i][j];
  visited[i][j] = true;
  return memo[i][j] = f(v, i + dy[v], j + dx[v]);
}

int main() {
  cin >> H >> W >> N >> M;
  rep(i, N){
    int a, b;
    cin >> a >> b;
    a--; b--;
    light[a][b] = true;
  }
  rep(i, M){
    int a, b;
    cin >> a >> b;
    a--, b--;
    stone[a][b] = true;
  }
  rep(v, 4){
    rep(i, H)rep(j, W)visited[i][j] = false;
    rep(i, H) rep(j, W) if (f(v, i, j)) ok[i][j] = true;
  }
  int ans = 0;
  rep(i, H)rep(j, W)if(ok[i][j])ans++;
  cout << ans << endl;
}