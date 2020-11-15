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

int main() {
  int n, m;
  cin >> n >> m;
  dsu d(n);
  vector<int> P(n);
  rep(i, n){
    cin >> P[i];
    P[i]--;
  }
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    d.merge(a, b);
  }
  int ans = 0;
  rep(i, n){
    if(d.same(P[i], i))ans++;
  }
  cout << ans << endl;
}