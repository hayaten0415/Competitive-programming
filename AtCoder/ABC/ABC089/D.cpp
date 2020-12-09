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
  int h, w, d;
  cin >> h >> w >> d;
  int mx = (h * w + d - 1) / d;
  vector<vector<int>> grid(h, vector<int>(w, 0));
  vector<vector<ll>> dist(d, vector<ll>(mx, 0));
  vector<P> num(h * w);
  rep(i, h){
    rep(j, w){
      cin >> grid[i][j];
      grid[i][j]--;
      num[grid[i][j]] = {i, j};
    }
  }
  rep(i, d){
    ll tmp = 0;
    int fi = i;
    while(fi + d < h * w){
      tmp += abs(num[fi].first - num[fi + d].first) + abs(num[fi].second - num[fi + d].second);
      dist[i][(fi + d) / d] = tmp;
      fi += d;
    }
  }
  int q;
  cin >> q;
  vector<ll> ans(q);
  rep(i, q){
    int l, r;
    cin >> l >> r;
    l--, r--;
    if(l / d == 0){
      ans[i] = dist[l % d][r / d];
    }else{
      ans[i] = dist[l % d][r / d] - dist[l % d][l / d];
    }
  }
  rep(i, q){
    cout << ans[i] << endl;
  }
}