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

int op(int a, int b) { return std::min(a, b); }
int e() { return int(1e9) + 1; }
int main() {
  int n, m;
  cin >> n >> m;
  vector<P> ra(m);
  vector<int> imos(n + 1, 0);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--;
    ra[i] = {a, b};
    imos[a]++;
    imos[b]--;
  }
  rep(i, n){
    imos[i + 1] = imos[i] + imos[i + 1];
  }
  segtree<int, op, e> seg(imos);
  vector<int> ans;
  rep(i, m){
    int num = seg.prod(ra[i].first, ra[i].second);
    if(num > 1){
      ans.emplace_back(i + 1);
    }
  }
  int c = ans.size();
  cout << c << endl;
  rep(i, c){
    cout << ans[i] << endl;
  }
}