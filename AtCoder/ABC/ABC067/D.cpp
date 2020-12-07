#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const ll INF = 100000000000;
// グラフ
using Edge = pair<int, ll>;         // {重み, 行き先}
using Graph = vector<vector<int>>; // グラフ

int main() {
  int n;
  cin >> n;
  //1からの距離
  vector<ll> dist1(n, INF);
  //nからの距離
  vector<ll> dist2(n, INF);
  int fenec = 0;
  int snuke = 0;
  //最短経路復元(1からn)
  vector<int> pre(n, -1);
  //最短経路(1からn)に含まれているか
  vector<bool> shortest(n, false);
  shortest[0] = true;
  shortest[n - 1] = true;
  Graph G(n);
  dist1[0] = 0;
  dist2[n - 1] = 0;
  queue<int> que;
  rep(i,n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].push_back(b);
    G[b].push_back(a);
  }
  que.push(0);
  while (!que.empty()){
    int v = que.front();
    que.pop();
    for(int u: G[v]){
      if(dist1[u] > dist1[v] + 1){
        dist1[u] = dist1[v] + 1;
        pre[u] = v;
        que.push(u);
      }
    }
  }
  que.push(n - 1);
  while (!que.empty()){
    int v = que.front();
    que.pop();
    for(int u: G[v]){
      if(dist2[u] > dist2[v] + 1){
        dist2[u] = dist2[v] + 1;
        que.push(u);
      }
    }
  }
  vector<int> shortest_path;
  shortest_path.push_back(n - 1);
  shortest[n - 1] = true;
  int index = n - 1;
  while (pre[index] != -1){
    shortest_path.push_back(pre[index]);
    shortest[pre[index]] = true;
    index = pre[index];
  }
  reverse(ALL(shortest_path));
  rep(i, shortest_path.size()){
    if(dist1[shortest_path[i]] <= dist2[shortest_path[i]])fenec++;
    else snuke++;
  }
  rep(i, n){
    if(shortest[i])continue;
    else{
      if(dist1[i] <= dist2[i])fenec++;
      else snuke++;
    }
  }
  if(fenec <= snuke){
    cout << "Snuke" << endl;
  }else{
    cout << "Fennec" << endl;
  }
}