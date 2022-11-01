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
#define sz(x) ((ll)(x).size())
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

vector<vector<int>> rev(vector<vector<int>> s) {
	int h = s.size();
	int w = s[0].size();
	vector<vector<int>> res(w);
	rep(i, w)res[i].resize(h);
	rep(i, h)rep(j, w) {
		res[j][h - 1 - i] = s[i][j];
	}
	return res;
}


int main() {
  int n;
  cin >> n;
  vector<vector<int>> A(n, vector<int>(n));
  map<int, ll> dp1[n][n], dp2[n][n];
  rep(i, n)rep(j, n) cin >> A[i][j];
  dp1[0][0][A[0][0]] = 1;
  rep(i, n)rep(j, n){
    if(i + j >= n)break;
    if(i -1 >= 0){
      for(auto [key, value] : dp1[i-1][j]){
        dp1[i][j][key ^ A[i][j]] += value;
      }
    }
    if(j- 1 >= 0){
      for(auto [key, value] : dp1[i][j-1]){
        dp1[i][j][key ^ A[i][j]] += value;
      }
    }
  }
  A = rev(A);
  A = rev(A);
  dp2[0][0][A[0][0]] = 1;
  rep(i, n)rep(j, n){
    if(i + j >= n)break;
    if(i -1 >= 0){
      for(auto [key, value] : dp2[i-1][j]){
        dp2[i][j][key ^ A[i][j]] += value;
      }
    }
    if(j- 1 >= 0){
      for(auto [key, value] : dp2[i][j-1]){
        dp2[i][j][key ^ A[i][j]] += value;
      }
    }
  }
  ll ans = 0;
  rep(i, n)rep(j, n){
    if(i + j != n-1)continue;
    for(auto [key, value] : dp1[i][j]){
      //cout << i << " " << key << " " << value << endl;
      if(j -1 >= 0)ans += value * dp2[j-1][i][key];
      if(i -1 >= 0)ans += value * dp2[j][i-1][key];
    }
  }
  cout << ans << endl;
}