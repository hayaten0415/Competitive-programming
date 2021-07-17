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
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL <<60);
int A[1000][1000];

int main() {
  int h, w;
  cin >> h >> w;
  rep(i, h) rep(j, w) cin >> A[i][j];
  set<int> st;
  rep(i, 1001) st.insert(i);
  vector<int> ans1(h), ans2(w);
  rep(i, h){
    set<int> tmp = st;
    rep(j, w){
      tmp.erase(A[i][j]);
    }
    ans1[i] = *tmp.begin();
  }
  rep(i, w){
    set<int> tmp = st;
    rep(j, h){
      tmp.erase(A[j][i]);
    }
    ans2[i] = *tmp.begin();
  }
  rep(i, h){
    cout << ans1[i] << (i == h - 1 ? "\n" : " ");
  }
  rep(i, w){
    cout << ans2[i] << (i == w - 1 ? "\n" : " ");
  }
}