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

int out[102];
int main() {
  int n, m;
  cin >> n >> m;
  dsu d(n);
  rep(i, m){
    int u, v;
    cin >> u >> v;
    u--, v--;
    bool ng = false;
    if (d.leader(u) == d.leader(v))ng = true;
    d.merge(u, v);
    if(ng){
      out[d.leader(u)] = 1;
    }
  }
  int ans = 0;
  int cn = d.groups().size();
  vector<vector<int>> tmp = d.groups();
  rep(i, cn){
    if(out[d.leader(tmp[i][0])])continue;
    ans++;
  }
  cout << ans << endl;
}