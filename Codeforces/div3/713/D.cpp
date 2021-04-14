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
  vector<ll> B(n + 2);
  ll sum = 0;
  rep(i, n+2){
    cin >> B[i];
    sum += B[i];
  }
  sort(ALL(B));
  rep(i, n+1){
    if(sum - B[n + 1] - B[i] == B[n+ 1]){
      rep(j, n+1){
        if(i == j)continue;
        cout << B[j] << " ";
      }
      cout << endl;
      return;
    }
  }
  rep(i, n+2){
    if(i == n)continue;
    if(sum - B[i] - B[n] == B[n]){
      rep(j, n+2){
        if(i == j)continue;
        if(j == n)continue;
        cout << B[j] << " ";
      }
      cout << endl;
      return;
    }
  }
  cout << -1 << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}