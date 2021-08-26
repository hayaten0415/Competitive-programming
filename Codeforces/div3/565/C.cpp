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
#define fi first
#define se second
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
const auto INF = numeric_limits<T>::max() / 2;


void solve() {
  int n;
  cin >> n;
  vector<bool> ng(n);
  vector<int> res = {4,8,15,16,23,42};
  vector<int> cn(6, 0);
  rep(i, n){
    int a;
    cin >> a;
    int c = lower_bound(ALL(res), a) - res.begin();
    if(c > 0){
      if(cn[c-1] <= cn[c])continue;
      else cn[c]++;
    }else{
      cn[c]++;
    }
  }
  int mn = *min_element(ALL(cn));
  int ans = 0;
  int re = 0;
  rep(i, 6){
    re += cn[i];
    ans += (cn[i] - mn);
  }
  ans += n - re;
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}