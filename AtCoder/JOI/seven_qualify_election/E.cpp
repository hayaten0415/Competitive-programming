#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int a[11][10001];

int main() {
  int r, c;
  cin >> r >> c;
  rep(i, r) {
    rep(j, c) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int bit = 0; bit < (1 << r); bit++){
    vector<int> s(c);
    rep(i, r) {
      if(bit & (1 << i)){
        rep(j, c) {
          s[j] += a[i][j] ^ 1;
        }
      }else{
        rep(j, c) {
          s[j] += a[i][j];
        }
      }
    }
    int tmp = 0;
    rep(j, c) tmp += max(r - s[j], s[j]);
    ans = max(ans, tmp);
  }
  cout << ans << endl;
}