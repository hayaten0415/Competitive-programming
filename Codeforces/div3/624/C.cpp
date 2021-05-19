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
#define popcount(bit) __builtin_popcount(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> sum_alpha(26, vector<int>(n + 1, 0));
  vector<vector<int>> alpha(26, vector<int>(n, 0));
  vector<int> ans(26, 0);
  vector<int> P(m);
  string s;
  cin >> s;
  rep(i, m) cin >> P[i];
  rep(i, n){
    int d = s[i] - 'a';
    alpha[d][i]++;
  }
  rep(i, n)rep(j, 26){
    sum_alpha[j][i + 1] = sum_alpha[j][i] + alpha[j][i];
  }
  rep(i, m){
    rep(j, 26){
      ans[j] += sum_alpha[j][P[i]];
    }
  }
  rep(j, 26){
      ans[j] += sum_alpha[j][n];
    }
  rep(i, 26){
    cout << ans[i] << (i == 25 ? "\n" : " ");
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}