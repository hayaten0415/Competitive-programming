#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
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
  int n;
  cin >> n;
  vector<vector<int>> C(n, vector<int>(n));
  rep(i, n)rep(j, n){
    cin >> C[i][j];
  }
  bool ok = true;
  for (int i = 0; i < n - 1; i++){
    for (int j = 0; j < n - 1; j++){
      if (C[i][j] + C[i + 1][j + 1] != C[i + 1][j] + C[i][j + 1]){
        ok = false;
      }
    }
  }
  vector<ll> A(n), B(n);
  if(!ok){
    cout << "No" << endl;
  }else{
    int p = min_element(C[0].begin(), C[0].end()) - C[0].begin();
    for (int i = 0; i < n; i++){
      A[i] = C[i][p];
    }
    for (int i = 0; i < n; i++){
      B[i] = C[0][i] - A[0];
    }
    cout << "Yes" << endl;
    rep(i, n) cout << A[i] << (i == n - 1 ? "\n" : " ");
    rep(i, n) cout << B[i] << (i == n - 1 ? "\n" : " ");
  }
}