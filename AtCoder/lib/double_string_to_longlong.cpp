#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


//小数を10^x倍して整数で返すライブラリ
ll double_string_to_longlong(string s, int x){
  int c = x;
  int n = s.size();
  string res = "";
  bool float_ok = false;
  rep(i, n){
    if(s[i] == '.'){
      float_ok = true;
      continue;
    }
    if(float_ok){
      c--;
    }
    res.pb(s[i]);
  }
  ll num = stol(res);
  rep(i, c){
    num *= 10;
  }
  return num;
}