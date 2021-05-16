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

ll res[1];

int main() {
  string s;
  cin >> s;
  int ok = 0;
  int qu = 0;
  rep(i, 10){
    if(s[i] == 'o')ok++;
    if(s[i] == '?')qu++;
  }
  res[1] = 1;
  res[2] = 14;
  res[3] = 36;
  res[4] = 24;
  if (ok > 4){
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  for (int bit = 0; bit < (1 << qu); bit++){
    int d = popcount(bit);
    if(ok + d > 4)continue;
    if(ok + d <= 0)continue;
    ll num = res[ok + d];
    ans += num;
  }
  cout << ans << endl;
}