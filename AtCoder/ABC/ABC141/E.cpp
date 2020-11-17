#include <bits/stdc++.h>
#include <atcoder/string>
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
  int n;
  string s;
  cin >> n >> s;
  int ans = 0;
  rep(i, n){
    string t = s.substr(i);
    vector<int> a = z_algorithm(t);
    rep(j, a.size()){
      chmin(a[j], j);
      chmax(ans, a[j]);
    }
  }
  cout << ans << endl;
}