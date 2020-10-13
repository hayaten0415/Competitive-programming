#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
using mint = modint1000000007;

void solve() {
  ll n, a, b;
  cin >> n >> a >> b;
  if(n < a + b){
    cout << 0 << endl;
    return;
  }
  mint all = mint(n - a + 1) * (n - a + 1) * (n - b + 1) * (n - b + 1);
  mint x = mint(n - a + 1) * (n - b + 1) - mint(n - a - b + 2) * (n - a - b + 1);
  mint ans = all - x * x;
  cout << ans.val() << endl;
}

int main() {
  int t;
  cin >> t;
  rep(i, t){
    solve();
  }
}