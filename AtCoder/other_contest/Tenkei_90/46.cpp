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

int main() {
  int n;
  cin >> n;
  vector<ll> A_res(46), B_res(46), C_res(46);
  rep(i, n){
    int a;
    cin >> a;
    a %= 46;
    A_res[a]++;
  }
  rep(i, n){
    int a;
    cin >> a;
    a %= 46;
    B_res[a]++;
  }
  rep(i, n){
    int a;
    cin >> a;
    a %= 46;
    C_res[a]++;
  }
  ll ans = 0;
  rep(i, 46)rep(j, 46)rep(s, 46){
    if((i + j + s) % 46 == 0){
      ans += (A_res[i] * B_res[j] * C_res[s]);
    }
  }
  cout << ans << endl;
}