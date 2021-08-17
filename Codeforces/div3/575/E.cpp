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
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max();


void solve() {
  ll b, w;
  cin >> b >> w;
  ll sum = b + w;
  ll mx = max(b, w);
  ll mn = min(b, w);
  if(mn == 1 && mx > 4){
    cout << "NO" << endl;
    return;
  }
  if(3 * (mn -1) + 4 < mx){
    cout << "NO" << endl;
    return;
  }
  cout << "YES" << endl;
  vector<PL> black;
  vector<PL> white;
  ll d = 0;
  ll x = 1e9 / 2;
  ll y = 1e9 / 2;
  rep(i, mn){
    white.pb({x, y});
    black.pb({x + 1, y});
    cout << x << " " << y << endl;
    cout << x + 1 << " " << y << endl;
    d += 2;
    x += 2;
  }
  
  if(b < w){
    int tmp_w = mn;
    int rest = sum - d;
    rep(i, rest / 2){
      auto [r, m] = black[i];
      cout << r << " " << m + 1 << endl;
      tmp_w++;
      cout << r << " " << m - 1 << endl;
      tmp_w++;
    }
    if(tmp_w < w){
      cout << black[mn-1].first + 1 << " " << black[mn-1].second << endl;
    }
  }
  if(w < b){
    int tmp_b = mn;
    int rest = sum - d;
    rep(i, rest / 2){
      auto [r, m] = white[i];
      cout << r << " " << m + 1 << endl;
      tmp_b++;
      cout << r << " " << m - 1 << endl;
      tmp_b++;
    }
    if(tmp_b < b){
      cout << white[0].first - 1 << " " << white[0].second << endl;
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}