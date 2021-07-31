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
  vector<int> A(n), ind(n);
  rep(i, n){
    cin >> A[i];
    A[i]--;
    ind[A[i]] = i;
  }
  int ans = 0;
  if(ind[0] != 0 && ind[n-1] != n-1){
    if(ind[0] == n-1 && ind[n-1] == 0){
      cout << 3 << endl;
    }else{
      cout << 2 << endl;
    }
  }else{
    rep(i, n){
      if(ind[i] != i){
        ans++;
        break;
      }
    }
    cout << ans << endl;
  }
  //rep(i, n){
  //  cout << A[i] << (i == n - 1 ? "\n" : " ");
  //}
  //rep(i, n){
  //  cout << ind[i] << (i == n - 1 ? "\n" : " ");
  //}
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}