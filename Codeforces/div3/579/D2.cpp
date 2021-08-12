#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
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
template <typename T>
const auto INF = numeric_limits<T>::max();


void solve() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int m = t.size();
  int cur = 0;
  vector<int> lef(m+1), rig(m+1);
  lef[0] = -1;
  rep(i, n){
    if(s[i] == t[cur]){
      cur++;
      lef[cur] = i;
      if(cur == m)break;
    }
  }
  cur = m - 1;
  rig[m] = n;
  rrep(i, n){
    if(s[i] == t[cur]){
      rig[cur] = i;
      cur--;
      if(cur < 0)break;
    }
  }
  int ans = 0;
  rep(i, m+1){
    chmax(ans, rig[i] - lef[i] - 1);
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}