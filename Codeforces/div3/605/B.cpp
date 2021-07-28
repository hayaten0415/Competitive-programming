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


void solve() {
  string s;
  cin >> s;
  int n = s.size();
  vector<int> ng(n + 1);
  int L = 0, R = 0, U = 0, D = 0;
  rep(i, n){
    if(s[i] == 'L')L++;
    if(s[i] == 'R')R++;
    if(s[i] == 'U')U++;
    if(s[i] == 'D')D++;
  }
  int ans = 0;
  if(min(L, R) == 0){
    ans = min(min(U, D) * 2, 2);
    cout << ans << endl;
    if(ans == 2){
      cout << "UD" << endl;
    }else{
      cout << endl;
    }
    return;
  }
  if(min(U, D) == 0){
    ans = min(min(L, R) * 2, 2);
    cout << ans << endl;
    if(ans == 2){
      cout << "LR" << endl;
    }else{
      cout << endl;
    }
    return;
  }
  ans = min(L, R) * 2 + min(U, D) * 2;
  cout << ans << endl;
  string res = "";
  res += string(min(L, R), 'L');
  res += string(min(U, D), 'U');
  res += string(min(L, R), 'R');
  res += string(min(U, D), 'D');
  cout << res << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}