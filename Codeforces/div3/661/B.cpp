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
  vector<ll> A(n);
  vector<ll> B(n);
  ll mnA = (ll)1e12;
  ll mnB = (ll)1e12;
  rep(i, n){
    cin >> A[i];
    chmin(mnA, A[i]);
  }
  rep(i, n){
    cin >> B[i];
    chmin(mnB, B[i]);
  }
  ll ans = 0;
  for (int i = 0; i < n;i++){
    ll mn = min(A[i] - mnA, B[i] - mnB);
    ans += mn;
    A[i] -= mn;
    B[i] -= mn;
    ans += (A[i] - mnA);
    ans += (B[i] - mnB);
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}