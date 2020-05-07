#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;


using Graph = vector<vector<int>>; // グラフ

int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    if(a == 0 || b == 0 || a == n-1 || b == n-1){
      G[a].push_back(b);
      G[b].push_back(a);
    }
  }
  if(G[0].size() == 0 || G[n-1].size() == 0){
    cout << "IMPOSSIBLE" << endl;
    return 0;
  }
  for(auto i : G[0]){
    for(auto j : G[i]){
      if(j == n-1){
        cout << "POSSIBLE" << endl;
        return 0;
      }
    }
  }
  cout << "IMPOSSIBLE" << endl;
}