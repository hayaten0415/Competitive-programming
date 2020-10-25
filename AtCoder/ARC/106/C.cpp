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
  if(n == 1 && m == 0){
    cout << 1 << " " << 2 << endl;
    return 0;
  }
  if(m == n || m < 0 || m == n-1){
    cout << -1 << endl;
    return 0;
  }
  int fi = 3;
  int se = 5;
  vector<P> ans(n-1);
  rep(i, n-1){
    ans[i] = {fi, se};
    fi += 4;
    se += 4;
  }
  if(m == 0){
    ans.push_back({1, 2});
    rep(i, n){
      cout << ans[i].first << " " << ans[i].second << endl;
    }
    return 0;
  }
  int last = 4 * (n-1) +2;
  int cn = n - 2 - m;
  last -= 4 * cn;
  ans.push_back({1, last});
  rep(i, n){
    cout << ans[i].first << " " << ans[i].second << endl;
  }
}