#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
using namespace atcoder;
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

// Lazy randomized binary search tree
template <int LEN, class S, S (*op)(S, S), class F, S (*reversal)(S), S (*mapping)(F, S), F (*composition)(F, F), F (*id)()> struct lazy_rbst {
    // Do your RuBeSTy! ⌒°( ・ω・)°⌒
    inline uint32_t _rand() { // XorShift
        static uint32_t x = 123456789, y = 362436069, z = 521288629, w = 88675123;
        uint32_t t = x ^ (x << 11);
        x = y;
        y = z;
        z = w;
        return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
    }

    struct Node {
        Node *l, *r;
        S val, sum;
        F lz;
        bool is_reversed;
        int sz;
        Node(const S &v) : l(nullptr), r(nullptr), val(v), sum(v), lz(id()), is_reversed(false), sz(1) {}
        Node() : l(nullptr), r(nullptr), lz(id()), is_reversed(false), sz(0) {}
        template <class OStream> friend OStream &operator<<(OStream &os, const Node &n) {
            os << '[';
            if (n.l) os << *(n.l) << ',';
            os << n.val << ',';
            if (n.r) os << *(n.r);
            return os << ']';
        }
    };
    using Nptr = Node *;
    std::array<Node, LEN> data;
    int d_ptr;

    int size(Nptr t) const { return t != nullptr ? t->sz : 0; }

    lazy_rbst() : d_ptr(0) {}

protected:
    Nptr update(Nptr t) {
        t->sz = 1;
        t->sum = t->val;
        if (t->l) {
            t->sz += t->l->sz;
            t->sum = op(t->l->sum, t->sum);
        }
        if (t->r) {
            t->sz += t->r->sz;
            t->sum = op(t->sum, t->r->sum);
        }
        return t;
    }

    void all_apply(Nptr t, F f) {
        t->val = mapping(f, t->val);
        t->sum = mapping(f, t->sum);
        t->lz = composition(f, t->lz);
    }
    void _toggle(Nptr t) {
        auto tmp = t->l;
        t->l = t->r, t->r = tmp;
        t->sum = reversal(t->sum);
        t->is_reversed ^= true;
    }

    void push(Nptr &t) {
        _duplicate_node(t);
        if (t->lz != id()) {
            if (t->l) {
                _duplicate_node(t->l);
                all_apply(t->l, t->lz);
            }
            if (t->r) {
                _duplicate_node(t->r);
                all_apply(t->r, t->lz);
            }
            t->lz = id();
        }
        if (t->is_reversed) {
            if (t->l) _toggle(t->l);
            if (t->r) _toggle(t->r);
            t->is_reversed = false;
        }
    }

    virtual void _duplicate_node(Nptr &) {}

    Nptr _make_node(const S &val) {
        if (d_ptr >= LEN) throw;
        return &(data[d_ptr++] = Node(val));
    }

public:
    Nptr new_tree() { return nullptr; } // 新たな木を作成

    int mem_used() const { return d_ptr; }
    bool empty(Nptr t) const { return t == nullptr; }

    // lとrをrootとする木同士を結合して，新たなrootを返す
    Nptr merge(Nptr l, Nptr r) {
        if (l == nullptr or r == nullptr) return l != nullptr ? l : r;
        if (_rand() % uint32_t(l->sz + r->sz) < uint32_t(l->sz)) {
            push(l);
            l->r = merge(l->r, r);
            return update(l);
        } else {
            push(r);
            r->l = merge(l, r->l);
            return update(r);
        }
    }

    // [0, k)の木と[k, root->size())の木に分けて各root
    // （部分木の要素数が0ならnullptr）を返す
    std::pair<Nptr, Nptr> split(Nptr &root, int k) { // rootの子孫からあとk個欲しい
        if (root == nullptr) return std::make_pair(nullptr, nullptr);
        push(root);
        if (k <= size(root->l)) { // leftからk個拾える
            auto p = split(root->l, k);
            root->l = p.second;
            return std::make_pair(p.first, update(root));
        } else {
            auto p = split(root->r, k - size(root->l) - 1);
            root->r = p.first;
            return std::make_pair(update(root), p.second);
        }
    }

    // 0-indexedでarray[pos]の手前に新たな要素 x を挿入する
    void insert(Nptr &root, int pos, const S &x) {
        auto p = split(root, pos);
        root = merge(p.first, merge(_make_node(x), p.second));
    }

    // 0-indexedでarray[pos]を削除する（先頭からpos+1個目の要素）
    void erase(Nptr &root, int pos) {
        auto p = split(root, pos);
        auto p2 = split(p.second, 1);
        root = merge(p.first, p2.second);
    }

    // 1点更新 array[pos].valにupdvalを入れる
    void set(Nptr &root, int pos, const S &x) {
        auto p = split(root, pos);
        auto p2 = split(p.second, 1);
        _duplicate_node(p2.first);
        *p2.first = Node(x);
        root = merge(p.first, merge(p2.first, p2.second));
    }

    // 遅延評価を利用した範囲更新 [l, r)
    void apply(Nptr &root, int l, int r, const F &f) {
        auto p = split(root, l);
        auto p2 = split(p.second, r - l);
        all_apply(p2.first, f);
        root = merge(p.first, merge(p2.first, p2.second));
    }

    // array[pos].valを取得する
    S prod(Nptr &root, int l, int r) {
        auto p = split(root, l);
        auto p2 = split(p.second, r - l);
        if (p2.first != nullptr) push(p2.first);
        S res = p2.first->sum;
        root = merge(p.first, merge(p2.first, p2.second));
        return res;
    }

    S get(Nptr &root, int pos) { return prod(root, pos, pos + 1); }

    void reverse(Nptr &root) { _duplicate_node(root), _toggle(root); }
    void reverse(Nptr &root, int l, int r) {
        auto p2 = split(root, r);
        auto p1 = split(p2.first, l);
        reverse(p1.second);
        root = merge(merge(p1.first, p1.second), p2.second);
    }

    // データを壊して新規にinitの内容を詰める
    void assign(Nptr &root, const std::vector<S> &init) {
        d_ptr = 0;
        int N = init.size();
        root = N ? _assign_range(0, N, init) : new_tree();
    }
    Nptr _assign_range(int l, int r, const std::vector<S> &init) {
        if (r - l == 1) {
            Nptr t = _make_node(init[l]);
            return update(t);
        }
        return merge(_assign_range(l, (l + r) / 2, init), _assign_range((l + r) / 2, r, init));
    }

    // データをvecへ書き出し
    void dump(Nptr &t, std::vector<S> &vec) {
        if (t == nullptr) return;
        push(t);
        dump(t->l, vec);
        vec.push_back(t->val);
        dump(t->r, vec);
    }

    // gc
    void re_alloc(Nptr &root) {
        std::vector<S> mem;
        dump(root, mem);
        assign(root, mem);
    }
};

// Persistent lazy randomized binary search tree
// Verified: https://atcoder.jp/contests/arc030/tasks/arc030_4
// CAUTION: https://yosupo.hatenablog.com/entry/2015/10/29/222536
template <int LEN, class S, S (*op)(S, S), class F, S (*reversal)(S), S (*mapping)(F, S), F (*composition)(F, F), F (*id)()> struct persistent_lazy_rbst : lazy_rbst<LEN, S, op, F, reversal, mapping, composition, id> {
    using RBST = lazy_rbst<LEN, S, op, F, reversal, mapping, composition, id>;
    using Node = typename RBST::Node;
    using Nptr = typename RBST::Nptr;
    persistent_lazy_rbst() : RBST() {}

protected:
    void _duplicate_node(Nptr &t) override {
        if (t == nullptr) return;
        if (RBST::d_ptr >= LEN) throw;
        t = &(RBST::data[RBST::d_ptr++] = *t);
    }

public:
    void copy(Nptr &root, int l, int d, int target_l) { // [target_l, )に[l, l+d)の値を入れる
        auto p1 = RBST::split(root, l);
        auto p2 = RBST::split(p1.second, d);
        root = RBST::merge(p1.first, RBST::merge(p2.first, p2.second));
        auto p3 = RBST::split(root, target_l);
        auto p4 = RBST::split(p3.second, d);
        root = RBST::merge(p3.first, RBST::merge(p2.first, p4.second));
    }
};


struct S {
    long long sum;
    int sz;
};
using F = long long;
S reversal(S x) { return x; }
S op(S l, S r) { return {l.sum + r.sum, l.sz + r.sz}; }
S mapping(F f, S x) {
    if (!f) return x;
    return {x.sum + x.sz * f, x.sz};
}
F composition(F f, F g) { return f + g; }
F id() { return 0; }


#include <iostream>
using namespace std;

int main() {
    constexpr int mem_size = 12000000;
    persistent_lazy_rbst<mem_size, S, op, F, reversal, mapping, composition, id> rbst;

    int N, Q;
    cin >> N >> Q;
    vector<S> v(N);
    for (auto &x : v) cin >> x.sum, x.sz = 1;
    auto tree = rbst.new_tree();
    rbst.assign(tree, v);

    while (Q--) {
        int type, a, b, c, d, v;
        cin >> type;
        if (type == 1) {
            cin >> a >> b >> v;
            rbst.apply(tree, a - 1, b, v);
        }
        if (type == 2) {
            cin >> a >> b >> c >> d;
            rbst.copy(tree, c - 1, b - a + 1, a - 1);
        }
        if (type == 3) {
            cin >> a >> b;
            cout << rbst.prod(tree, a - 1, b).sum << endl;
        }
        if (rbst.mem_used() > mem_size * 0.8) rbst.re_alloc(tree);
    }
}
