#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

vector<int> ans;
int color[100000];
vector<int> C;
Graph G;

void dfs(int u, int pre){
  for(auto v : G[u]){
    if(v == pre)continue;
    if(color[C[v]] == 0){
      ans.pb(v);
    }
    color[C[v]]++;
    dfs(v, u);
    color[C[v]]--;
  }
}

int main() {
  int n;
  cin >> n;
  C.resize(n);
  G.resize(n);
  rep(i, n){
    cin >> C[i];
    C[i]--;
  }
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].eb(b);
    G[b].eb(a);
  }
  ans.eb(0);
  color[C[0]]++;
  dfs(0, -1);
  sort(ALL(ans));
  int d = ans.size();
  rep(i, d){
    cout << ans[i] + 1 << endl;
  }
}