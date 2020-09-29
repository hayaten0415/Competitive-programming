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
  int h, w, k, n;
  cin >> h >> w >> k >> n;
  vector<int> row(100000, 0), column(100000, 0),r(n), c(n);
  vector<ll> cn_row(100001, 0), cn_column(100001, 0);
  rep(i, n){
    cin >> r[i] >> c[i];
    r[i]--, c[i]--;
    row[r[i]]++, column[c[i]]++;
  }
  rep(i, h){
    cn_row[row[i]]++;
  }
  rep(i, w){
    cn_column[column[i]]++;
  }
  ll ans = 0;
  rep(i, k+1){
    ans += cn_row[i] * cn_column[k - i];
  }
  rep(i, n){
    int num = row[r[i]] + column[c[i]];
    if(num == k)ans--;
    if(num == k+1)ans++;
  }
  cout << ans << endl;
}