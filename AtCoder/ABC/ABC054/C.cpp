#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
typedef long long ll;


int n, m;
ll ans = 0;
Graph G;


void dfs(vector<bool> &visited, int &ans, int s){
  bool fin = true;
  rep(i,visited.size()){
    if(!visited[i] && i != s) fin = false;
  }
  if(fin){
    ans++;
    return;
  }
  visited[s] = true;
  for(auto g : G[s]){
    if(visited[g]) continue;
    dfs(visited,ans, g);
  }
  visited[s] = false;
}

int main() {
  cin >> n >> m;
  G.assign(n, vector<int>());
  vector<bool> visited(n, false);
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  int ans = 0;
  dfs(visited, ans, 0);
  cout << ans << endl;
}