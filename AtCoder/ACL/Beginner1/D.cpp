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
const int A_MAX = 300005;

int op(int a, int b) {
  return max(a, b);
}
int e() {
  return 0;
}


int main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n){
    cin >> a[i];
  }
  segtree<int, op, e> dp(A_MAX);
  rep(i, n){
    int x = a[i];
    int l = x - k, r = x + k + 1;
    l = max(0, l);
    r = min(r, A_MAX);
    int now = dp.prod(l, r) + 1;
    dp.set(x, now);
  }
  cout << dp.prod(0, A_MAX) << endl;
}