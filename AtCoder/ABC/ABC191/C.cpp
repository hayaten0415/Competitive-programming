#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, 0, 1};
const int dy[4] = {0, 1, 0, 1};

int main() {
  int h, w;
  cin >> h >> w;
  int ans = 0;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  rep(i, h)rep(j, w){
    if(i + 1 >= h)continue;
    if(j + 1 >= w)continue;
    int num = 0;
    rep(s, 4){
      int ni = i + dx[s], nj = j + dy[s];
      if(grid[ni][nj] == '#')num++;
    }
    ans += (num % 2);
  }
  cout << ans << endl;
}