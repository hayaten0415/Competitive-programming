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
  int h, w;
  cin >>h >> w;
  vector<vector<ll>> A(h, vector<ll>(w));
  vector<vector<ll>> B(h, vector<ll>(w));
  rep(i, h) rep(j, w) cin >> A[i][j];
  rep(i, h) rep(j, w) cin >> B[i][j];
  ll ans = 0;
  rep(i, h-1)rep(j, w-1){
    if(A[i][j] == B[i][j])continue;
    ll d = B[i][j] - A[i][j];
    ans += abs(d);
    A[i][j] += d;
    A[i+1][j] += d;
    A[i][j+1] += d;
    A[i+1][j + 1] += d;
  }
  if(A== B){
    cout << "Yes" << endl;
    cout << ans << endl;
  }else{
    cout << "No" << endl;
  }
}