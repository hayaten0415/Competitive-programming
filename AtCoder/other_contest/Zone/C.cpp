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
  vector abcde(n, vector(5, 0LL));
  rep(i, n) rep(j, 5) cin >> abcde[i][j];
  auto check = [&](int x) -> bool{
    bool ok = false;
    set<int> st;
    rep(i, n){
      int bit = 0;
      rep(j, 5){
        if(abcde[i][j] >= x) bit |= (1 << j);
      }
      st.insert(bit);
    }
    for(auto a : st) for(auto b : st) for(auto c : st){
      if((a | b | c) == ((1 << 5) - 1)) ok = true;
    }
    return ok;
  };
  int left = 0, right = 1000000001;
  while(right - left > 1){
    int mid = (left + right) / 2;
    if(check(mid))left = mid;
    else right = mid;
  }
  cout << left << endl;
}