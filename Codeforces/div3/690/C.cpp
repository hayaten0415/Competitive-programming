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
  int x;
  cin >> x;
  if(x < 10){
    cout << x << endl;
    return;
  }
  if(x > 45){
    cout << -1 << endl;
    return;
  }
  vector<int> A(50);
  rep(i, 10) A[i] = i;
  int i = 10;
  int tmp = 9;
  int cn = 1;
  while(i <= 45){
    for (int j = 8; j > 0; j--){
      for (int d = 0; d < j; d++){
        A[i + d] = A[tmp] + (d + 1) * pow(10, cn);
        //cout << i + d << " " << tmp << endl;
      }
      i += j;
      tmp = i - 1;
      cn++;
    }
  }
  cout << A[x] << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}