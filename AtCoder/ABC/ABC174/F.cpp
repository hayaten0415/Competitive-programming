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


//0-indexed
template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n = 0) : n(n), d(n + 1) {}
  void add(int i, T x) {
    for (i++; i <= n; i += i & -i){
      d[i] += x;
    }
  }
  T sum(int i) {
    T num = 0;
    for (i++; i; i -= i & -i){
      num += d[i];
    }
    return num;
  }
  T sum(int l, int r) {
    return sum(r - 1) - sum(l - 1);
  }
};


int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> pi(n + 1, -1);
  vector<vector<int>> ps(n);
  rep(i, n){
    int l = pi[a[i]];
    if(l != -1) ps[l].emplace_back(i);
    pi[a[i]] = i;
  }
  vector<vector<P>> qs(n);
  rep(qi, q){
    int l, r;
    cin >> l >> r;
    l--, r--;
    qs[l].emplace_back(r, qi);
  }
  vector<int> ans(q);
  BIT<int> d(n);
  for (int x = n - 1; x >= 0; x--){
    for(int y : ps[x]) d.add(y, 1);
    for(P query: qs[x]){
      int r = query.first,  i = query.second;
      ans[i] = (r - x + 1) - d.sum(r);
    }
  }
  rep(i, q){
    cout << ans[i] << endl;
  }
}