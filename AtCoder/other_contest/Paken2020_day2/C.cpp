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

void solve(){
  int n, m;
  cin >> n >>m;
  vector<int> ind(n), oud(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    oud[a]++;
    ind[b]++;
  }
  int ans = m;
  rep(i, n) ans -= min(ind[i], oud[i]);
  cout << ans << endl;
}

int main() {
  int t;
  cin >> t;
  while(t--)solve();
}