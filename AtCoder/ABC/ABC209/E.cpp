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
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL <<60);
Graph G;

int main() {
  int m;
  cin >> m;
  vector<string> sa(m), sb(m);
  map<string, int> mp;
  rep(i, m){
    string s;
    cin >> s;
    sa[i] = s.substr(0, 3);
    sb[i] = s.substr(s.size() - 3);
    mp[sa[i]] = 0, mp[sb[i]] = 0;
  }
  int n = 0;
  for (auto &p : mp){
    p.second = n;
    n++;
  }
  G.resize(n);
  vector<int> deg(n);
  rep(i, m){
    int a = mp[sa[i]];
    int b = mp[sb[i]];
    deg[a]++;
    G[b].pb(a);
  }
  queue<int> que;
  vector<int> ans(n);
  rep(i, n){
    if(deg[i] == 0){
      ans[i] = -1;
      que.push(i);
    }
  }
  while(!que.empty()){
    int u = que.front();
    que.pop();
    if(ans[u] == -1){
      for(auto v : G[u]){
        if(ans[v])continue;
        ans[v] = 1;
        que.push(v);
      }
    }else{
      for(auto v : G[u]){
        if(ans[v])continue;
        deg[v]--;
        if(deg[v] == 0){
          ans[v] = -1;
          que.push(v);
        }
      }
    }
  }
  rep(i, m){
    if(ans[mp[sb[i]]] == -1)cout << "Takahashi" << endl;
    else if(ans[mp[sb[i]]] == 1)cout << "Aoki" << endl;
    else cout << "Draw" << endl;
  }
}