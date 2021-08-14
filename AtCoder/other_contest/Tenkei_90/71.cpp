#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

using Graph = vector<vector<int>>;
vector<int> dist;
vector<int> topo_sort(const Graph &G){
  int n = G.size();
  vector<int> ans;
  vector<int> ind(n);
  rep(i, n) for (auto v : G[i]) ind[v]++;
  queue<int> que;
  rep(i, n) if(ind[i] == 0)que.push(i);
  while (!que.empty()){
    int v = que.front();
    que.pop();
    ans.emplace_back(v);
    for(auto e : G[v]){
      ind[e]--;
      chmax(dist[e], dist[v] + 1);
      if(ind[e] == 0)que.push(e);
    }
  }
  return ans;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  dist.resize(n);
  Graph G(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
  }
  vector<int> ans = topo_sort(G);
  if(ans.size() != n){
    cout << -1 << endl;
    return 0;
  }
  vector<set<int>> cn(n);
  rep(i, n){
    cn[dist[i]].insert(i);
  }
  ll num = 1;
  bool ok = false;
  rep(i, n){
    cout << i <<  " " << cn[i].size() << endl;
    if(cn[i].size() == 0)continue;
    if(cn[i].size() >= 4){
      ok = true;
      break;
    }
    if(cn[i].size() == 3){
      num *= 6;
    }else{
      num *= cn[i].size();
    }
  }
  cout << num << endl;
  if(!ok){
    cout << -1 << endl;
  }else{
    vector<vector<int>> dist_set;
    vector<int> ans;
    rep(i, n){
      vector<int> tmp;
      if(cn[i].size() == 0)continue;
      for(auto d : cn[i]){
        tmp.pb(d);
      }
      dist_set.pb(tmp);
    }
    int f = dist_set.size();
    int tmp = 0;
    while (tmp < k){
      rep(i, f){
        if(tmp >= k)break;
        do{
          rep(j, f){
            for(auto g : dist_set[j]){
              cout << g + 1 << " ";
            }
          }
          cout << endl;
          tmp++;
          if(tmp >= k)break;
        }while(next_permutation(ALL(dist_set[i])));
      }
    }
  }
}