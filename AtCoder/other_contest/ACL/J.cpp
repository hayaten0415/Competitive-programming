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

int op(int a, int b) {
  return max(a, b);
}
int e() {
  return -1;
}

int target;

bool f(int x){
  return x < target;
}

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  segtree<int, op, e> seg(a);
  rep(i, q){
    int t;
    cin >> t;
    if(t == 1){
      int x, v;
      cin >> x >> v;
      x--;
      seg.set(x, v);
    }else if(t == 2){
      int l, r;
      cin >> l >> r;
      l--;
      cout << seg.prod(l, r) << endl;
    }else{
      int p;
      cin >> p >> target;
      p--;
      cout << seg.max_right<f>(p) + 1 << endl;
    }
  }
}