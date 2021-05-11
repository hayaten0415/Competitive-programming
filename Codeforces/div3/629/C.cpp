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
  cin >> n;
  string s;
  cin >> s;
  string res1 = "", res2 = "";
  int cn1 = 0, cn2 = 0;
  int first = 0;
  rep(i, n){
    if(first == 0){
      if(s[i] == '2'){
        res1 += '1';
        res2 += '1';
      }else if(s[i] == '1'){
        first++;
        res1 += '1';
        res2 += '0';
      }else{
        res1 += '0';
        res2 += '0';
      }
    }else{
      if(s[i] == '2'){
        res1 += '0';
        res2 += '2';
      }else if(s[i] == '1'){
        res1 += '0';
        res2 += '1';
      }else{
        res1 += '0';
        res2 += '0';
      }
    }
  }
  cout << res1 << endl;
  cout << res2 << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}