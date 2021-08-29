#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max()/2;


#ifdef _MSC_VER
#include <intrin.h>
#endif
 
namespace atcoder {
 
namespace internal {
 
int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}
 
constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while (!(n & (1 << x))) x++;
    return x;
}
 
int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}
 
}  // namespace internal
 
}  // namespace atcoder
 
 
namespace atcoder {
 
template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }
 
    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }
 
    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }
 
    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;
 
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }
 
    S all_prod() const { return d[1]; }
 
    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }
 
    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }
 
  private:
    int _n, size, log;
    std::vector<S> d;
 
    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};
 
}  // namespace atcoder

class heavy_light_decomposition {
    const int n;
    vector<vector<int>> g;
    vector<int> in, out, size, head, par;
    int it;
    void erase_par(int v, int prev) {
        par[v] = prev;
        for (auto& u : g[v]) {
            if (u == g[v].back()) break;
            if (u == prev) swap(u, g[v].back());
            erase_par(u, v);
        }
        g[v].pop_back();
    }
    void dfs1(int v) {
        for (auto& u : g[v]) {
            dfs1(u);
            size[v] += size[u];
            if (size[u] > size[g[v][0]]) swap(u, g[v][0]);
        }
    }
    void dfs2(int v) {
        in[v] = it++;
        for (auto u : g[v]) {
            head[u] = (u == g[v][0] ? head[v] : u);
            dfs2(u);
        }
        out[v] = it;
    }
public:
    heavy_light_decomposition(int n_)
        : n(n_), g(n), in(n, -1), out(n, -1), size(n, 1), head(n), par(n, -1), it(0) {}
    heavy_light_decomposition(const vector<vector<int>>& G)
        : n(G.size()), g(G), in(n, -1), out(n, -1), size(n, 1), head(n), par(n, -1), it(0) {}
    void add_edge(int u, int v) {
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void build(int rt = 0) {
        for (auto v : g[rt]) erase_par(v, rt);
        dfs1(rt);
        head[rt] = rt;
        dfs2(rt);
    }
    int get_id(int v) {
        return in[v];
    }
    int get_lca(int u, int v) {
        while (true) {
            if (in[u] > in[v]) swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }
    int sub_size(int u){
        return size[u];
    }
    void path_query(int u, int v, function<void(int, int)> f, bool edge = false) {
        while (true) {
            if (in[u] > in[v]) swap(u, v);
            f(max(in[head[v]], in[u] + edge), in[v] + 1);
            if (head[u] == head[v]) return;
            v = par[head[v]];
        }
    }
    void subtree_query(int v, function<void(int, int)> f, bool edge = false) {
        f(in[v] + edge, out[v]);
    }
};

/*
hl.subtree_query(v,[&](int l,int r){ //vを根とする部分木
    seg.apply(l,r,num);
});

lint res=hoge;
hl.path_query(u,v,[&](int l,int r){ //u,v間の頂点
    res=max(res,seg.prod(l,r));
});
*/

// verify https://mojacoder.app/users/milkcoffee/contests/pdc001/tasks/4
// verify https://judge.yosupo.jp/problem/vertex_add_path_sum

using namespace atcoder;
ll op(ll a,ll b){
    return a + b;
}
ll e(){
    return 0;
}

int main(void){
  int N;
  cin >> N;
  heavy_light_decomposition hl(N);
  rep(i,N){
    int k;
    cin >> k;
    rep(j, k){
      int v;
      cin >> v;
      hl.add_edge(i, v);
    }
  }
  hl.build();
  segtree<ll,op,e> seg(N);
  int q;
  cin >> q;
  while(q--) {
    int type, u;
    ll w;
    cin >> type;
		if(type == 0) {
			cin >> u >> w;
			hl.subtree_query(u,[&](int l,int r){ //u,v間の頂点
          seg.set(l,seg.get(l) + w);
      }, 0);
		}
		if(type == 1) {
			cin >> u;
      ll ans = 0;
			hl.path_query(0, u,[&](int l,int r){ //u,v間の頂点
        ans += seg.prod(l,r);
      }, 1);
      cout << ans << endl;
    }
  }
}
