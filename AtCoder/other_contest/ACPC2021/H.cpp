#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
//#include <atcoder/all>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define REP(i,n) for(ll i=0;i<ll(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=ll(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=ll(b);i--)
#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i=n;i--;)
#define rrep2(i,n) for(ll i=n;i--;)
#define rrep3(i,a,b) for(ll i=b;i-->(a);)
#define rrep4(i,a,b,c) for(ll i=(a)+((b)-(a)-1)/(c)*(c);i>=(a);i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
//using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
inline void Yes(bool b = true) { cout << (b ? "Yes" : "No") << '\n'; }
inline void YES(bool b = true) { cout << (b ? "YES" : "NO") << '\n'; }
inline void OKNG(bool b = true) { cout << (b ? "OK" : "NG") << '\n'; }
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
 
 
using namespace atcoder;


template <class S, S (*op)(S, S), S (*e)(), class Coordinate> class rangetree {
    int n;
    using Pt = std::pair<Coordinate, Coordinate>;
    std::vector<Pt> _pts;
    std::vector<std::vector<Pt>> _range2yxs;
    std::vector<atcoder::segtree<S, op, e>> segtrees;
    void _set(int v, Pt p, S val) {
        auto i = std::distance(_range2yxs[v].begin(), std::lower_bound(_range2yxs[v].begin(), _range2yxs[v].end(), Pt{p.second, p.first}));
        segtrees[v].set(i, val);
    }
    void _add(int v, Pt p, S val) {
        auto i = std::distance(_range2yxs[v].begin(), std::lower_bound(_range2yxs[v].begin(), _range2yxs[v].end(), Pt{p.second, p.first}));
        segtrees[v].set(i, op(segtrees[v].get(i), val));
    }
    S _prod(int v, Coordinate yl, Coordinate yr) const {
        auto comp = [&](const Pt &l, const Pt &r) { return l.first < r.first; };
        auto il = std::distance(_range2yxs[v].begin(), std::lower_bound(_range2yxs[v].begin(), _range2yxs[v].end(), Pt{yl, yl}, comp));
        auto ir = std::distance(_range2yxs[v].begin(), std::lower_bound(_range2yxs[v].begin(), _range2yxs[v].end(), Pt{yr, yr}, comp));
        return segtrees[v].prod(il, ir);
    }

public:
    rangetree() = default;
    void add_point(Coordinate x, Coordinate y) noexcept { _pts.emplace_back(x, y); }
    void build() {
        std::sort(_pts.begin(), _pts.end());
        _pts.erase(std::unique(_pts.begin(), _pts.end()), _pts.end());
        n = _pts.size();

        _range2yxs.resize(n * 2);
        for (int i = 0; i < n; i++) _range2yxs[n + i] = {{_pts[i].second, _pts[i].first}};
        for (int i = n - 1; i > 0; i--) {
            auto &lch = _range2yxs[i * 2];
            auto &rch = _range2yxs[i * 2 + 1];
            std::merge(lch.begin(), lch.end(), rch.begin(), rch.end(), std::back_inserter(_range2yxs[i]));
            _range2yxs[i].erase(std::unique(_range2yxs[i].begin(), _range2yxs[i].end()), _range2yxs[i].end());
        }
        for (const auto &v : _range2yxs) segtrees.emplace_back(v.size());
    }
    void set(Coordinate x, Coordinate y, S val) {
        int i = std::distance(_pts.begin(), std::lower_bound(_pts.begin(), _pts.end(), Pt{x, y}));
        assert(i < n and _pts[i] == std::make_pair(x, y));
        for (i += n; i; i >>= 1) _set(i, {x, y}, val);
    }
    void add(Coordinate x, Coordinate y, S val) {
        int i = std::distance(_pts.begin(), std::lower_bound(_pts.begin(), _pts.end(), Pt{x, y}));
        assert(i < n and _pts[i] == std::make_pair(x, y));
        for (i += n; i; i >>= 1) _add(i, {x, y}, val);
    }
    S prod(Coordinate xl, Coordinate xr, Coordinate yl, Coordinate yr) const {
        auto comp = [](const Pt &l, const Pt &r) { return l.first < r.first; };
        int l = n + std::distance(_pts.begin(), std::lower_bound(_pts.begin(), _pts.end(), Pt{xl, yr}, comp));
        int r = n + std::distance(_pts.begin(), std::lower_bound(_pts.begin(), _pts.end(), Pt{xr, yr}, comp));
        S ret = e();
        while (l < r) {
            if (l & 1) ret = op(ret, _prod(l++, yl, yr));
            if (r & 1) ret = op(ret, _prod(--r, yl, yr));
            l >>= 1, r >>= 1;
        }
        return ret;
    }
    S get(Coordinate x, Coordinate y) const { return prod(x, x + 1, y, y + 1); }
};

P e() { return {0, 1 << 30}; }
P op(P l, P r) { return {l.first + r.first, min(l.second, r.second)}; }

//verify https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2021Day2/problems/H
// Reference:https://github.com/hitonanode/cplib-cpp/blob/4d2b2c32202aa9b86c2e9c660ac409fc79cfb41e/segmenttree/rangetree.hpp

int main() {
  int n, m;
  cin >> n >> m;
  rangetree<P, op, e, int> tree;
  vector<tuple<int, int, int>> qs;
  while (m--) {
        int y, x, a;
        cin >> y >> x >> a;
        y--, x--;
        qs.emplace_back(y, x, a);
        tree.add_point(y, x);
    }
    tree.build();
    for (auto [y, x, a] : qs) tree.set(y, x, {1, a});

    int q;
    cin >> q;
    while (q--) {
      int u, d, l, r;
      cin >> u >> d >> l >> r;
      u--, l--;
      auto ret = tree.prod(u, d, l, r);
      ll retval = ret.second;
      if (ret.second == (1 << 30)) chmin(retval, 0LL);
      if (ret.first < ll(r - l) * (d - u)) chmin(retval, 0LL);
      cout << retval << '\n';
    }
}