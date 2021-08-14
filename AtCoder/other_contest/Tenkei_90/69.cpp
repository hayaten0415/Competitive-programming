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
using mint = modint1000000007;

int main() {
  ll n, k;
  cin >> n >> k;
  mint ans = 1;
  if(n == 1){
    cout << k << endl;
    return 0;
  }
  if(n == 2){
    ans *= (k * (k - 1));
    cout << ans.val() << endl;
    return 0;
  }
  if(k <= 2){
    cout << 0 << endl;
    return 0;
  }
  ans *= (k) * (k - 1);
  ans *= mint(k - 2).pow(n - 2);
  cout << ans.val() << endl;
}