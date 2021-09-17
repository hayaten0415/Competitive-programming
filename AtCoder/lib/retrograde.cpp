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
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max()/2;

//verify https://atcoder.jp/contests/arc038/tasks/arc038_d

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> X(n);
  rep(i, n) cin >> X[i];
  Graph G(2 * n), revG(2 * n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].pb(b + n);
    G[a+ n].pb(b);
    revG[b + n].pb(a);
    revG[b].pb(a + n);
  }
  /**
 * 後退解析
 */
  auto retrograde = [&](vector<int> &d) {
    int V = G.size();
    vector<int> count(V);
    rep(i, V)count[i] = (int)G[i].size();
    rep(i, V){
      if (d[i] == 1) {
          for (int v: revG[i]) {
            count[v]--;
          }
      }
      if (d[i] == -1) {
        for (int v: revG[i]) {
          if (d[v]) continue;
          d[v] = 1;
          for (int c: revG[v]) {
            count[c]--;
          }
        }
      }
    }
    queue<int> q;
    rep(i, V){
      if (count[i]) continue;
      q.push(i);
    }
    while(!q.empty()){
      int v = q.front(); q.pop();
      if (d[v]) continue;
      d[v] = -1;
      for (int e: revG[v]) {
        if (d[e]) continue;
        d[e] = 1;
        for (int f: revG[e]) {
            count[f]--;
            if (!count[f]) {
              q.push(f);
            }
        }
      }
    }
  };
  auto f = [&](int x)-> bool {
    vector<int> d(2* n);
    rep(i, n){
      if(x < X[i]){
        d[i] = 1;
        d[i + n] = 0;
      }else{
        d[i] = 0;
        d[i + n] = 1;
      }
    }
    retrograde(d);
    return d[0] == 1;
  };
  int l = -1, r = 1e9+1;
  while (r-l > 1) {
    int md = (l+r)/2;
    if (f(md)) {
        l = md;
    } else {
        r = md;
    }
  }
  cout << r << endl;
}