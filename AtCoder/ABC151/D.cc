#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
typedef pair<int, int> P;

const int INF = 1000002020;
const int di[] = {-1, 0, 1, 0};
const int dj[] = {0, -1, 0, 1};

int main(){
  int h, w;
  cin >> h >> w;
  int ans = 0;
  vector<string> s(h);
  rep(i, h) cin >> s[i];
  rep(ci, h)rep(cj, w){
    if(s[ci][cj] == '#') continue;
    vector<vector<int>> dist(h, vector<int>(w, INF));
    queue<P> q;
    auto update = [&](int i, int j, int x){
      if(dist[i][j] != INF) return;
      dist[i][j] = x;
      q.push(P(i,j));
    };
    update(ci, cj, 0);
    while(!q.empty()) {
      int i = q.front().first;
      int j = q.front().second; q.pop();
      rep(d, 4){
        int ni = i + di[d], nj = j + dj[d];
        if(ni<0 || ni>= h || nj < 0 || nj >= w ) continue;
        if(s[ni][nj] == '#') continue;
        update(ni, nj, dist[i][j]+1);
      }
    }
    rep(i ,h)rep(j, w){
      if(dist[i][j] == INF)continue;
      ans = max(ans, dist[i][j]);
    }
  }
  cout << ans << endl;
  return 0;
}
