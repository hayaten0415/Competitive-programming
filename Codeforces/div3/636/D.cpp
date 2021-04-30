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
  int n, k;
  cin >> n >> k;
  vector<int> modify_count(2 * k + 1);
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  rep(i, n/ 2){
    int sum = A[i] + A[n - 1 - i];
    if(sum != 2 * k){
      int d = k - min(A[i], A[n - 1 - i]);
      modify_count[sum + 1]++;
      if(sum + d + 1 <= 2 * k){
        modify_count[sum + d+1]--;
        modify_count[sum + d + 1]+= 2;
      }
    }
    if(sum != 2){
      int d = max(A[i], A[n - 1 - i]);
      d--;
      modify_count[sum - d]++;
      modify_count[sum - d] -= 2;
      modify_count[sum]--;
      modify_count[0]+= 2;
    }
  }
  int ans = n;
  for (int c = 1; c <= 2 * k; c++){
    modify_count[c] = modify_count[c] + modify_count[c - 1];
  }
  //for (int c = 1; c <= 2 * k; c++){
  //  cout << modify_count[c] << " " << (c == 2 * k ? "\n"  : " ");
  //}
  for (int c = 2; c <= 2 * k; c++){
    chmin(ans, modify_count[c]);
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