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

int a[4][4];
bool b[4][4];

int main() {
  rep(i, 4) rep(j, 4) cin >> a[i][j];
  int ans = 0;
  rep(i, (1 << 16)){
    if(i == 0)continue;
    rep(j, 16){
      if (i & (1 << j)) {
        b[j/ 4][j % 4] = true;
      }else{
        b[j / 4][j % 4] = false;
      }
    }
    int cnt = 0;
    bool used[4][4] = {};
    rep(j, 4)rep(k, 4){
      if (!used[j][k]&& b[j][k]) {
        cnt++;
        used[j][k] = true;
        queue<P> que;
        que.push({j, k});
        while(!que.empty()){
          auto [x, y] = que.front();
          que.pop();
          rep(v, 4){
            int nx = x + dx[v];
            int ny = y + dy[v];
            if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4)continue;
            if(used[nx][ny])continue;
            if(!b[nx][ny])continue;
            used[nx][ny] = true;
            que.push({nx, ny});
          }
        }
      }
    }
    if (cnt != 1)continue;
    bool ok = true;
    rep(j, 4)rep(k, 4) {
			if (a[j][k] && !b[j][k])ok = false;
		}
    dsu d(17);
    rep(j, 4)rep(k, 4){
      if (!b[j][k]) {
        if(j == 0 || j == 3 || k == 0 || k == 3){
          d.merge(j * 4 + k, 16);
        }
        rep(v, 4){
          int nx = j + dx[v];
          int ny = k + dy[v];
          if(nx < 0 || ny < 0 || nx >= 4 || ny >= 4)continue;
          if(b[nx][ny])continue;
          d.merge(j * 4 + k, nx * 4 + ny);
        }
      }
    }
    rep(j, 4)rep(k, 4)if (!b[j][k]) {
			if (!d.same(j * 4 + k, 16))ok = false;
		}
    if(ok)ans++;
  }
  cout << ans << endl;
}