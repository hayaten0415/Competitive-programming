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

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    lazy_segtree(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push(r >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
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

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
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
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
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
struct S{
    long long value;
    int size;
};
using F = long long;

S op(S a, S b){ return {a.value+b.value, a.size+b.size}; }
S e(){ return {0, 0}; }
S mapping(F f, S x){ return {x.value + f*x.size, x.size}; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

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
  vector<S> A(N, {0, 1});
  lazy_segtree<S, op, e, ll, mapping, composition, id> seg(A);
  int q;
  cin >> q;
  while(q--) {
    int type, u;
    ll w;
    cin >> type;
		if(type == 0) {
			cin >> u >> w;
			hl.path_query(0, u,[&](int l,int r){ //u,v間の頂点
          seg.apply(l,r, w);
      }, 1);
		}
		if(type == 1) {
			cin >> u;
      ll ans = 0;
			hl.path_query(0, u,[&](int l,int r){ //u,v間の頂点
        ans += seg.prod(l,r).value;
      }, 1);
      cout << ans << endl;
    }
  }
}
