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
using PP = pair<int, P>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
using Graph = vector<vector<int>>;
const int INF = (1LL << 30);

vector<int> topo_sort(const Graph &G, const vector<int> &used){
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
      if(ind[e] == 0)que.push(e);
    }
  }
  return ans;
}

void solve() {
  int n, m;
  cin >> n >> m;
  Graph G(n), G1(n);
  vector<int> used(n);
  vector<int> num(n);
  vector<int> cn(n, 0);
  rep(i, m){
    int t, a, b;
    cin >> t >> a >> b;
    a--, b--;
    if(t == 1){
      G[a].eb(b);
      used[a] = 1;
      used[b] = 1;
    }else{
      G1[a].eb(b);
      G1[b].eb(a);
    }
  }
  vector<int> ans = topo_sort(G, used);
  if(ans.size() != n){
    cout << "NO" << endl;
  }else{
    cout << "YES" << endl;
    rep(i, n){
      num[ans[i]] = i;
    }
    rep(i, n){
      for (auto v : G[i]){
        cout << i + 1 << " " << v + 1 << endl;
      }
    }
    rep(i, n){
      for (auto v : G1[i]){
        if(num[v] > num[i]){
          cout << i + 1 << " " << v + 1 << endl;
        }
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}