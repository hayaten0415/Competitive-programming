#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

const int MOD = 1000000007;
const int MAX =200000;


int main() {
  int n, m;
  int ans = 0;
  bool cond = true;
  cin >> n >> m;
  if(m == 0 && n > 2) {
    ans = pow(10, n - 1);
    cout << ans << endl;
    return 0;
  } else if (m == 0 && n == 1) {
    ans = 0;
    cout << ans << endl;
    return 0;
  } else {
    int a, b;
    vector<P> digit(m);
    rep(i, m){
      cin >> a >> b;
      digit[i] = make_pair(a, b);
    }
    sort(digit.begin(), digit.end());
    rep(i,m) {
      if(n > 1 && digit[i].first == 1 && digit[i].second == 0) {
        cond = false;
        break;
      }
    }
    rep(i, m - 1) {
      if(digit[i].first == digit[i + 1].first) {
        if (digit[i].second != digit[i+1].second) {
          cond = false;
          break;
        } else {
          continue;
        }
      } else {
        ans += digit[i].second * pow(10, n - digit[i].first);
      }
    }
    ans += digit[m -1].second * pow(10, n - digit[m - 1].first);
    if(cond) {
      if(n > 1 && ans < pow(10, n - 1)) {
        cout << pow(10, n - 1) + ans << endl;
      } else {
        cout << ans << endl;
      }
    }else {
      cout << -1 << endl;
    }
    return 0;
  }
}
