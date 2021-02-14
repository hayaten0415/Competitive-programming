#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  Graph G(n);
  vector<int> color(n);
  rep(i, m){
    int a,b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  rep(i, n) cin >> color[i];
  rep(i, q){
    int num;
    cin >> num;
    if(num == 1){
      int k;
      cin >> k;
      k--;
      cout << color[k] << endl;
      int co = color[k];
      for(auto d : G[k]){
        color[d] = co;
      }
    }else{
      int x, y;
      cin >> x >> y;
      x--,
      cout << color[x] << endl;
      color[x] = y;
    }
  }
}