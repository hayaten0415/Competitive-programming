#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
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
ll X, Y;

map<ll, ll> memo;
ll rec(ll y){
  ll res = 0;
  if (memo.find(y) != memo.end()) return memo[y];
  if(y % 2 == 0){
    memo[y] = min(rec(y / 2) + 1, abs(X - y));
    res += memo[y];
  }else if(y != 1 && y % 2 == 1){
    memo[y] = min(rec((y + 1) / 2) + 2, min(rec((y - 1) / 2) + 2, abs(X - y)));
    res += memo[y];
  }else if(y == 1){
    res += abs(X - y);
  }
  return res;
}

int main() {
  cin >> X >> Y;
  cout << rec(Y) << endl;
}