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
  int n;
  cin >> n;
  vector<ll> A(4 * n);
  rep(i, 4 * n) cin >> A[i];
  sort(ALL(A));
  ll num = A[0] * A[4 * n - 1];
  if(A[0] != A[1] || A[4 * n-1] != A[4 * n-2] || num != A[1] *  A[4 * n-2]){
    cout << "NO" << endl;
    return;
  }
  int left1 = 2;
  int left2 = 3;
  int right1 = 4 * n- 3;
  int right2 = 4 * n - 4;
  for (int i = 1; i < n;i++){
    if(A[left1] != A[left2] || A[right1] != A[right2]){
      cout << "NO" << endl;
      return;
    }
    if (A[left1] * A[right1] != num || A[left2] * A[right2] != num){
      cout << "NO" << endl;
      return;
    }
    left1 += 2;
    left2 += 2;
    right1 -= 2;
    right2 -= 2;
  }
  cout << "YES" << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}