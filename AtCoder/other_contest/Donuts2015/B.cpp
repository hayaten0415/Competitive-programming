#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> A(n);
  vector<int> B(m), C(m);
  vector<vector<int>> I(m);
  rep(i, n) cin >> A[i];
  rep(i, m) {
    cin >> B[i] >> C[i];
    rep(j, C[i]) {
        I[i].push_back(0);
        cin >> I[i].back();
    }
  }
  int ans = 0;
  rep(i, 1 << n) {
    int cn = 0, b = 0;
    rep(j, n) {
      if ((i >> j) & 1) {
        cn++;
        b += A[j];
      }
    }
    if (cn != 9) continue;
    int s = 0;
    rep(j, m) {
      int f = 0;
      rep(k, C[j]) {
          if ((i >> (I[j][k] - 1)) & 1) f++; 
      }
      if (f >2) s += B[j];
    }
    chmax(ans, s + b);
  }
  cout << ans << endl;
}