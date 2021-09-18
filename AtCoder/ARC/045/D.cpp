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
using namespace atcoder;
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

/* Lowlink: グラフの関節点・橋を列挙する構造体
    作成: O(E+V)
    関節点の集合: vector<int> aps
    橋の集合: vector<P> bridges
*/
struct LowLink {
    const Graph &G;
    vector<int> used, ord, low;
    vector<int> aps; // articulation points
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


int main() {
  int n;
  cin >> n;
  Graph G(2 * n + 1);
  vector<vector<P>> X(200010), Y(200010);
  rep(i,2*n+1){
    int x,y;
    cin >> x >> y;
    X[x].emplace_back(y,(int)i);
    Y[y].emplace_back(x,(int)i);
  }
  dsu d(2 * n + 1);
  rep(i,200010){
    if(X[i].size()<2)continue;
    sort(ALL(X[i]));
    rep(j,X[i].size()){
      rep(k,max(0LL,j-2),min(j+3,(ll)X[i].size())){
        if(j==k)continue;
        d.merge(X[i][j].second,X[i][k].second);
        G[X[i][j].second].emplace_back(X[i][k].second);
      }
    }
  }
  rep(i,200010){
    if(Y[i].size()<2)continue;
    sort(ALL(Y[i]));
    rep(j,Y[i].size()){
      rep(k,max(0LL,j-2),min(j+3,(ll)Y[i].size())){
        if(j==k)continue;
        d.merge(Y[i][j].second,Y[i][k].second);
        G[Y[i][j].second].emplace_back(Y[i][k].second);
      }
    }
  }
  vector<ll> root;
  rep(i, 2* n + 1){
    if(d.leader(i) == i && d.size(i) % 2 == 1)root.pb(i);
  }
  if(root.size()!=1){
    rep(i,2*n+1){
      cout << "NG" << endl;
    }
    return 0;
  }
  ll rt = root[0];
  vector<ll> ord(2*n+1,INF<ll>),low(2*n+1,-1);
  ll k = 0;
  vector<bool> is_odd(2*n+1,false),kansetsu(2*n+1,false);
  auto dfs = [&](auto f, ll n,ll p)->void{
    ord[n] = k++;
    low[n] =  k;
    for(auto nn : G[n]){
      if(nn==p)continue;
      if(ord[nn]!=INF<ll>){
        chmin(low[n],ord[nn]);
        continue;
      }
    ll now = k;
      f(f,nn,n);
      chmin(low[n],low[nn]);
      if(low[nn]>=ord[n])kansetsu[n] = true;
      if(low[nn]>=ord[n]&&(k-now)%2)is_odd[n] = true;
    }
  };

  dfs(dfs,rt,-1);

  rep(i,2*n+1){
    if(d.same(i,rt)){
      OKNG(!((kansetsu[i]&&is_odd[i])));
    }else{
      cout << "NG" << endl;
    }
  }
}