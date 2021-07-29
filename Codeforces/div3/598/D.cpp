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
#define popcountll(bit) __builtin_popcountll(bit)
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
  int n;
  ll k;
  cin >> n >> k;
  string s;
  cin >> s;
  vector<int> zero_ind;
  rep(i, n){
    if(s[i] == '0')zero_ind.pb(i);
  }
  int d = zero_ind.size();
  rep(i, d){
    if(k == 0)break;
    if(zero_ind[i] == i)continue;
    int d = zero_ind[i] - i;
    if(d > k){
      d = k;
    }
    zero_ind[i] -= d;
    k -= d;
  }
  string res = string(n, '1');
  rep(i, d){
    res[zero_ind[i]] = '0';
  }
  cout << res << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}