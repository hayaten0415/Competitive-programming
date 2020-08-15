#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> A(n, vector<int>(m));
  rep(i, n) {
    rep(j, m) {
      cin >> A[i][j];
    }
  }
  ll ans = 0;
  rep(i, m) {
    for (int j = i + 1; j < m; j++){
      ll tmp = 0;
      rep(k, n) {
        tmp += max(A[k][i],A[k][j]);
      }
      ans = max(ans, tmp);
    }
  }
  cout << ans << endl;
}