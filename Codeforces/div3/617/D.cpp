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
  int n;
  ll a, b, k;
  cin >> n >> a >> b >> k;
  vector<ll> H(n);
  rep(i, n) cin >> H[i];
  vector<ll> res(n);
  ll d = a+ b;
  rep(i, n){
    ll m = H[i] % d;
    ll n = H[i] / d;
    if(m > 0 && m <= a){
      res[i] = 0;
      continue;
    }
    if(m > 0){
      ll rest = H[i] - d * n - a;
      res[i] = (rest + a - 1) / a;
    }
    if(m == 0){
      ll rest = H[i] - d * (n-1) - a;
      res[i] = (rest + a - 1) / a;
    }
  }
  sort(ALL(res));
  ll tmp = 0;
  int ans = 0;
  rep(i, n){
    tmp += res[i];
    if(tmp <= k)ans++;
    else break;
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t = 1;
  while(t--) solve();
}