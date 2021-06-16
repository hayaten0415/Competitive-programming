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
using P = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  int n;
  ll k;
  cin >> n >> k;
  ll pre = 0;
  ll rest = k;
  vector<P> AB(n);
  rep(i, n) cin >> AB[i].first >> AB[i].second;
  sort(ALL(AB));
  ll ans = 0;
  rep(i, n){
    if(rest - AB[i].first + pre >= 0){
      ans = AB[i].first;
      rest -= (AB[i].first - pre);
      pre = AB[i].first;
      rest += AB[i].second;
    }else{
      ans = pre + rest;
      cout << ans << endl;
      return 0;
    }
  }
  ans += rest;
  cout << ans << endl;
}