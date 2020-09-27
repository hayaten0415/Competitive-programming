#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using mint = modint998244353;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const mint inv9 = mint(1) / 9;

struct S {
  mint x, w;
  S(mint x = 0, mint w = 1): x(x), w(w){}
};

S op(S l, S r) {
  return S(l.x * r.w + r.x, l.w * r.w);
}
S e() { return S(); }

S mapping(int f, S a){
  if(f == 0) return a;
  return S((a.w - 1) * inv9 * f, a.w);
}

//gのほうが先のことに気をつける
int composition(int f, int g){
  if(f == 0) return g;
  return f;
}

int id() {
  return 0;
}

int main() {
  int n, q;
  cin >> n >> q;
  lazy_segtree<S, op, e, int, mapping, composition, id> seg(n);
  rep(i, n){
    seg.set(i, S(1, 10));
  }
  rep(i,q){
    int l, r, d;
    cin >> l >> r >> d;
    --l;
    seg.apply(l, r, d);
    S ans = seg.prod(0,n);
    printf("%d\n", ans.x.val());
  }
}