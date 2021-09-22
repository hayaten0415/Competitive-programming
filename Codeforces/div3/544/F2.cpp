#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
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
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
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
const auto INF = numeric_limits<T>::max() / 2;


void solve() {
  int n, m, d;
  cin >> n >> m >> d;
  Graph G(n);
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].pb(b);
    G[b].pb(a);
  }
  if((int)G[0].size() < d){
    cout << "NO" << endl;
    return;
  }
  int cnt = 0;
  vector<int> c(n, -1);
  auto bfs = [&](int start)-> void {
    if(c[start] != -1)return;
    queue<int> q;
    q.push(start);
    c[start] = cnt;
    while(!q.empty()){
      int v = q.front();
      q.pop();
      for(int s : G[v]){
        if(c[s] != -1)continue;
        if(s == 0)continue;
        c[s] = cnt;
        q.push(s);
      }
    }
    cnt++;
  };
  rep(i, n){
    if(i == 0)continue;
    bfs(i);
  }
  if(d < cnt){
    cout << "NO" << endl;
    return;
  }
  vector<vector<int>> A(cnt);
  for (int i : G[0]){
    A[c[i]].push_back(i);
  }
  vector<int> B;
  for (int i = 0; i < cnt; i++){
    B.push_back(A[i].back());
    A[i].pop_back();
    d--;
  }
  for (int i = 0; i < cnt; i++){
    while (d > 0 && !A[i].empty()){
      B.push_back(A[i].back());
      A[i].pop_back();
      d--;
    }
  }
  cout << "YES" << endl;
  d = B.size();
  for (int i = 0; i < d; i++){
    cout << 1 << ' ' << B[i] + 1 << endl;
  }
  vector<bool> used(n, false);
  used[0] = true;
  queue<int> Q;
  for (int i = 0; i < d; i++){
    used[B[i]] = true;
    Q.push(B[i]);
  }
  while (!Q.empty()){
    int v = Q.front();
    Q.pop();
    for (int w : G[v]){
      if (!used[w]){
        cout << v + 1 << ' ' << w + 1 << endl;
        used[w] = true;
        Q.push(w);
      }
    }
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}