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

/* Lowlink: グラフの関節点・橋を列挙する構造体
    作成: O(E+V)
    関節点の集合: vector<int> aps
    橋の集合: vector<P> bridges
*/
struct LowLink {
    const Graph &G;
    vector<int> used, ord, low;
    vector<int> aps;  // articulation points
    vector<P> bridges;

    LowLink(const Graph &G_) : G(G_) {
        used.assign(G.size(), 0);
        ord.assign(G.size(), 0);
        low.assign(G.size(), 0);
        int k = 0;
        for (int i = 0; i < (int)G.size(); i++) {
            if (!used[i]) k = dfs(i, k, -1);
        }
        sort(aps.begin(), aps.end()); // 必要ならソートする
        sort(bridges.begin(), bridges.end()); // 必要ならソートする
    }

    int dfs(int id, int k, int par) { // id:探索中の頂点, k:dfsで何番目に探索するか, par:idの親
        used[id] = true;
        ord[id] = k++;
        low[id] = ord[id];
        bool is_aps = false;
        int count = 0; // 子の数
        for (auto &e : G[id]) {
            if (!used[e]) {
                count++;
                k = dfs(e, k, id);
                low[id] = min(low[id], low[e]);
                if (par != -1 && ord[id] <= low[e]) is_aps = true; 
                if (ord[id] < low[e]) bridges.emplace_back(min(id, e), max(id, e)); // 条件を満たすので橋  
            } else if (e != par) { // eが後退辺の時
                low[id] = min(low[id], ord[e]);
            }
        }
        if (par == -1 && count >= 2) is_aps = true; 
        if (is_aps) aps.push_back(id);
        return k;
    }
};

//verify https://atcoder.jp/contests/abc075/tasks/abc075_c

int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].eb(b);
    G[b].eb(a);
  }
  LowLink lw(G);
  cout << lw.bridges.size() << endl;
}