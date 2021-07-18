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

int main() {
  int n, m;
  cin >> n >> m;
  map<int, vector<int>> black;
  set<int> ans;
  ans.insert(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    black[a].pb(b);
  }
  for(auto x : black){
    set<int> ok;
    set<int> ng;
    for(auto y : x.second){
      if(ans.count(y-1) || ans.count(y + 1))ok.insert(y);
      else ng.insert(y);
    }
    for(auto y : ng)ans.erase(y);
    for(auto y : ok)ans.insert(y);
  }

  cout << ans.size() << endl;
}