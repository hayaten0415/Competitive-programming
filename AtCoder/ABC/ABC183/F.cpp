#include <bits/stdc++.h>
#include <atcoder/dsu>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, q;
  cin >> n >> q;
  vector<map<int, int>> cn(n);
  rep(i, n){
    int c;
    cin >> c;
    c--;
    cn[i][c] = 1;
  }
  dsu d(n);
  rep(i, q){
    int t, x, y;
    cin >> t >> x >> y;
    x--, y--;
    if(t== 1){
      x = d.leader(x);
      y = d.leader(y);
      if(x == y)continue;
      int s = d.merge(x, y);
      if(s != x)swap(x, y);
      for(auto temp:cn[y])cn[x][temp.first]+=temp.second;
    }else{
      cout << cn[d.leader(x)][y] << endl;
    }
  }
}