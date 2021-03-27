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
using namespace std;
using P = pair<int, int>;
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
  vector<int> A(n), mx_A(n), mn_A(n);
  int mx = 0;
  set<int> st_mn, st_mx;
  rep(i, n){
    cin >> A[i];
    st_mn.insert(i + 1);
    st_mx.insert(i + 1);
  }
  rep(i, n){
    if(chmax(mx, A[i])){
      mn_A[i] = A[i];
      mx_A[i] = A[i];
      st_mn.erase(A[i]);
      st_mx.erase(A[i]);
    }else{
      mn_A[i] = *st_mn.begin();
      st_mn.erase(mn_A[i]);
      auto d = st_mx.lower_bound(mx);
      d--;
      mx_A[i] = *d;
      st_mx.erase(mx_A[i]);
    }
  }
  rep(i, n){
    cout << mn_A[i] << (i == n - 1 ? "\n" : " ");
  }
  rep(i, n){
    cout << mx_A[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}