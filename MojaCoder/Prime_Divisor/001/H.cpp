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


struct Sieve_prime{
  vector<int> f, primes;
  int n;
  Sieve_prime(int n = 1): n(n), f(n +1){
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; i++){
      if(f[i])continue;
      primes.emplace_back(i);
      f[i] = i;
      for (ll j = i * i; j <= n; j += i){
        //この条件をつけると最小素因数が記録される
        //つけないと最大素因数が記録される。
        if(!f[j]) f[j] = i;
      }
    }
  }
  bool isPrime(int x) { return f[x] == x; }
  vector<int> factorlist(int x){
    vector<int> res;
    while (x != 1){
      res.emplace_back(f[x]);
      x /= f[x];
    }
    return res;
  }
  vector<P> factor(int x) {
    vector<int> fl = factorlist(x);
    if (fl.size() == 0) return {};
    vector<P> res(1, P(fl[0], 0));
    for (int p : fl) {
      if (res.back().first == p) {
        res.back().second++;
      } else {
        res.emplace_back(p, 1);
      }
    }
    return res;
  }
  vector<int> divisors(int x){
    assert(x > 0);
    vector<int> res = {1};
    for(auto [p, e] : factor(x)){
      int n = res.size() * e;
      for(int i=0; i<n; ++i){
        res.push_back(res[i] * p);
      }
    }
    sort(ALL(res));
    return res;
  }
};

Sieve_prime Sieve(1e6 + 1);


struct BipartiteMatching {
    int V;
    std::vector<std::vector<int>> to; // Adjacency list
    std::vector<int> dist;            // dist[i] = (Distance from i'th node)
    std::vector<int> match;           // match[i] = (Partner of i'th node) or -1 (No parter)
    std::vector<int> used, vv;        //
    std::vector<int> color;           // color of each node(checking bipartition): 0/1/-1(not determined)

    BipartiteMatching() = default;
    BipartiteMatching(int V_) : V(V_), to(V_), match(V_, -1), used(V_), color(V_, -1) {}

    void add_edge(int u, int v) {
        assert(u >= 0 and u < V and v >= 0 and v < V and u != v);
        to[u].push_back(v);
        to[v].push_back(u);
    }

    void bfs() {
        dist.assign(V, -1);
        std::queue<int> q;
        for (int i = 0; i < V; i++) {
            if (!color[i] and !used[i]) { q.emplace(i), dist[i] = 0; }
        }

        while (!q.empty()) {
            int now = q.front();
            q.pop();
            for (auto nxt : to[now]) {
                int c = match[nxt];
                if (c >= 0 and dist[c] == -1) { q.emplace(c), dist[c] = dist[now] + 1; }
            }
        }
    }

    bool dfs(int now) {
        vv[now] = true;
        for (auto nxt : to[now]) {
            int c = match[nxt];
            if (c < 0 or (!vv[c] and dist[c] == dist[now] + 1 and dfs(c))) {
                match[nxt] = now, match[now] = nxt;
                used[now] = true;
                return true;
            }
        }
        return false;
    }

    bool _color_bfs(int root) {
        color[root] = 0;
        std::queue<int> q;
        q.emplace(root);
        while (!q.empty()) {
            int now = q.front(), c = color[now];
            q.pop();
            for (auto nxt : to[now])
                if (color[nxt] == -1)
                    color[nxt] = !c, q.emplace(nxt);
                else if (color[nxt] == c)
                    return false;
        }
        return true;
    }

    int solve() {
        for (int i = 0; i < V; i++)
            if (color[i] == -1) {
                if (!_color_bfs(i)) return -1;
            }
        int ret = 0;
        while (true) {
            bfs();
            vv.assign(V, false);
            int flow = 0;
            for (int i = 0; i < V; i++)
                if (!color[i] and !used[i] and dfs(i)) flow++;
            if (!flow) break;
            ret += flow;
        }
        return ret;
    }

    friend std::ostream &operator<<(std::ostream &os, const BipartiteMatching &bm) {
        os << "{N=" << bm.V << ':';
        for (int i = 0; i < bm.V; i++)
            if (bm.match[i] > i) { os << '(' << i << '-' << bm.match[i] << "),"; }
        os << '}';
        return os;
    }
};



int main() {
  int n;
  cin >> n;
  set<int> st;
  vector<int> A(n);
  vector<int> prime;
  rep(i, n){
    cin >> A[i];
    auto c = Sieve.factor(A[i]);
    for(auto b : c){
      int f = b.first;
      st.insert(f);
      prime.eb(f);
    }
  }
  int d = st.size();
  BipartiteMatching bm(n + d);
  sort(ALL(prime));
  prime.erase(unique(ALL(prime)), prime.end());
  rep(i, n){
    auto c = Sieve.factor(A[i]);
    for(auto b : c){
      int f = b.first;
      int e = lower_bound(ALL(prime), f) - prime.begin();
      bm.add_edge(i, n + e);
    }
  }
  int ret = bm.solve();
  ll ans = d + (n - ret);
  cout << ans << endl;
}