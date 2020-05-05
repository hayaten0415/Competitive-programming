#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, x, y;
  cin >> n >> x >> y;
  x--, y--;
  vector<vector<int>> dist(n, vector<int>(n, -1));
  for (int s = 0; s < n; s++){
    queue<int> que;
    dist[s][s] = 0;
    que.push(s);
    while (!que.empty()){
      auto v = que.front(); que.pop();
      vector<int> shortest;
      if(v > 0) shortest.push_back(v-1);
      if(v< n-1) shortest.push_back(v+1);
      if(v == x) shortest.push_back(y);
      if(v == y) shortest.push_back(x);
      for(auto sh: shortest){
        if(dist[s][sh] == -1){
          dist[s][sh] = dist[s][v] + 1;
          que.push(sh);
        }
      }
    }
  }
  vector<int> ans(n, 0);
  for (int i = 0; i < n; i++){
    for (int j = i + 1; j < n; j++){
      ans[dist[i][j]]++;
    }
  }
  for (int i = 1; i < n; i++){
    cout << ans[i] << endl;
  }
}