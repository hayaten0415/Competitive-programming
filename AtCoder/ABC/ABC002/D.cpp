#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  int ans = 1;
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  for (int bit = 1; bit < (1 << n); bit++){
    vector<int> tmp;
    bool ok = true;
    rep(i, n){
      if(bit & (1 << i)){
        tmp.push_back(i);
      }
    }
    rep(i, tmp.size()){
      rep(j, tmp.size()){
        if(i == j)continue;
        if(find(G[tmp[i]].begin(), G[tmp[i]].end(), tmp[j])==G[tmp[i]].end()){
          ok = false;
          break;
        }
      }
      if(!ok)break;
    }
    if(ok) ans = max(ans, __builtin_popcount(bit));
  }
  cout << ans << endl;
}
