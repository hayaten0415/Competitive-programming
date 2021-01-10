#include <bits/stdc++.h>
#include <atcoder/dsu>
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
bool non_tree[400000];

int main() {
  int n;
  cin >> n;
  vector<int> A(n), B(n);
  map<int, int> mp;
  rep(i, n){
    cin >> A[i] >> B[i];
    mp[A[i]] = 0;
    mp[B[i]] = 0;
  }
  int cn = 0;
  for (auto &p : mp){
    p.second = cn;
    cn++;
  }
  dsu d(mp.size());
  rep(i, n){
    int a = mp[A[i]];
    int b = mp[B[i]];
    if(d.same(a, b)){
      non_tree[d.leader(a)] = true;
    }
    if(non_tree[d.leader(a)] | non_tree[d.leader(b)]){
      d.merge(a, b);
      non_tree[d.leader(a)] = true;
    }
    d.merge(a, b);
  }
  int ans = 0;
  rep(i, mp.size()){
    if(d.leader(i) != i)continue;
    ans += d.size(i);
    if(!non_tree[i])ans--;
  }
  cout << ans << endl;
}