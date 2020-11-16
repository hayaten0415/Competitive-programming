#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

vector<int> ans;
set<int> tmp;
set<int> already;
int n;

void dfs(int p, int pre, vector<vector<int>> &G){
  if(already.find(p) != already.end())return;
  if(ans.size() == n)return;
  already.insert(p);
  ans.emplace_back(p);
  for(auto k : G[p]){
    if(k == pre)continue;
    if(already.find(k) != already.end())continue;
    if(tmp.find(k) != tmp.end())continue;
    tmp.insert(k);
  }
  if(tmp.size() == 0)return;
  int num = *tmp.begin();
  tmp.erase(num);
  dfs(num, p, G);
}

int main() {
  cin >> n;
  vector<vector<int>> G(n);
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--; b--;
    G[a].emplace_back(b);
    G[b].emplace_back(a);
  }
  dfs(0, -1, G);
  rep(i, n){
    cout << ans[i] + 1 << (i == n - 1 ? "\n" : " ");
  }
}