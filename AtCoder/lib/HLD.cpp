#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
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
using namespace std;
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
// verify https://judge.yosupo.jp/problem/vertex_add_subtree_sum
// verify https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_D
// verify https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_E

int op(int a,int b){
    return gcd(a,b);
}
int e(){
    return 0;
}

int main(void){
    int N;
    cin >> N;
    int A[N];
    rep(i,N) cin >> A[i];
    heavy_light_decomposition hl(N);
    rep(i,N-1){
        int u,v;
        cin >> u >> v;
        u--,v--;
        hl.add_edge(u,v);
    }
    hl.build();
    segtree<int,op,e> seg(N);
    rep(i,N){
        hl.path_query(i,i,[&](int l,int r){ //u,v間の頂点
            seg.set(l,A[i]);
        }, 0);
    }
    int ans=0;
    for(int i=0;i<N;i++) for(int j=i+1;j<N;j++){
        int res=0;
        hl.path_query(i,j,[&](int l,int r){ //u,v間の頂点
            res=gcd(res,seg.prod(l,r));
        }, 0);
        if(res==1) ans++;
    }
    cout << ans << endl;
}
