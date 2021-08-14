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
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int P[8][10000];

int main() {
  int h, w;
  cin >> h >> w;
  map<int, int> mp;
  rep(i, h) rep(j, w){
    cin >> P[i][j];
  }
  int ans = 1;
  rep(bit, (1 << h)){
    if(bit == 0)continue;
    int cn = popcount(bit);
    vector<int> tmp_h;
    rep(i, h){
      if(bit & (1 << i))tmp_h.pb(i);
    }
    map<int, int> mp;
    rep(j, w){
      int pre = P[tmp_h[0]][j];
      bool ok = true;
      for(auto d: tmp_h){
        if(P[d][j] != pre){
          ok = false;
          break;
        }
      }
      if(ok){
        mp[pre] += cn;
      }
    }
    for(auto p : mp)chmax(ans, p.second);
  }
  cout << ans << endl;
}