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
#define popcountll(bit) __builtin_popcountll(bit)
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
  int n, d;
  cin >> n >> d;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  vector<ll> res(n + 1);
  rep(bit, (1 << n)){
    ll tmp = 0;
    rep(i, n){
      if(bit & (1LL << i)){
        tmp |= A[i];
      }
    }
    int b = popcountll(tmp);
    int k = popcount(bit);
    res[k] += (1LL << (d -b));
  }
  ll ans = 0;
  rep(i, n+1){
    if(i %2 == 0){
      ans += res[i];
    }else{
      ans -= res[i];
    }
  }
  cout << ans << endl;
}