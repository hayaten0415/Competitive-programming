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
  vector<int> X(n), Y(n);
  vector<P> XY(n);
  rep(i, n){
    cin >> X[i] >> Y[i];
    XY[i].first = X[i] + Y[i];
    XY[i].second = i;
  }
  sort(ALL(XY));
  string ans = "";
  int prex = 0, prey = 0;
  rep(i, n){
    if(prex > X[XY[i].second] || prey > Y[XY[i].second]){
      cout << "NO" << endl;
      return;
    }else{
      int d = X[XY[i].second] - prex;
      int s = Y[XY[i].second] - prey;
      prex = X[XY[i].second];
      prey = Y[XY[i].second];
      rep(j, d){
        ans.pb('R');
      }
      rep(j, s){
        ans.pb('U');
      }
    }
  }
  cout << "YES" << endl;
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}