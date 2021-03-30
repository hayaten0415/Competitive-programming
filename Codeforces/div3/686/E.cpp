#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
using Graph = vector<vector<int>>;

void solve() {
  int n;
  cin >> n;
  Graph G(n);
  vector<int> cn(n, 1);
  rep(i, n){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].eb(b);
    G[b].eb(a);
  }
  vector<int> d(n);
  for (int j = 0; j < n; j++){
    d[j] = G[j].size();
  }
  queue<int> que;
  for (int j = 0; j < n; j++){
    if (d[j] == 1){
      que.push(j);
    }
  }
  int cnt = n;
  while(!que.empty()){
    int v = que.front();
    cnt--;
    que.pop();
    for (int w : G[v]){
      if (d[w] != 1){
        d[w]--;
        if (d[w] == 1){
          que.push(w);
        }
        cn[w] += cn[v];
      }
    }
  }
  long long ans = (long long) n * (n - 1);
  for (int j = 0; j < n; j++){
    if (d[j] == 2){
      ans -= (long long)cn[j] * (cn[j] - 1) / 2;
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}