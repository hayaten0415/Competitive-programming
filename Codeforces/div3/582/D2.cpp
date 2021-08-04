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
const ll INF = (1LL << 60);

void solve() {
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  vector<ll> res(2e5+ 1);
  rep(i, n){
    ll b = A[i];
    res[b]++;
    ll d = 0;
    if(b == 0)continue;
    while (true){
      if(b == 0)break;
      b /= 2;
      d++;
      res[b]++;
    }
  }
  ll ans = INF;
  rep(i, 2e5+ 1){
    ll tmp = 0;
    int num = 0;
    sort(ALL(res[i]));
    for(auto d : res[i]){
      tmp += d;
      num++;
      if(num >= k){
        chmin(ans, tmp);
        break;
      }
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}