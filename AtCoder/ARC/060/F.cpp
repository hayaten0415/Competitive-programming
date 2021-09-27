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

using S = int;
S op(S x, S y) { return min(x, y); }
S e() { return INF<int>; }

int main() {
  string s;
  cin >> s;
  int n = s.size();
  if(count(ALL(s), s.front()) == n) {
    cout << n << endl;
    cout << 1 << endl;
    return 0;
  }
  auto slv = [](const string &s) {
		auto sa = suffix_array(s);
		auto lcp = lcp_array(s, sa);
    int n = s.size();
    segtree<S, op, e> seg(n - 1);
    rep(i, n - 1) { seg.set(i, lcp[i]); }
		vector pl(n, 0);
		rep(i, n) { pl[sa[i]] = i; }
		vector<bool> ret(n + 1);
		rep(d, 1, n + 1) {
			for(int i = d * 2; i <= n; i += d) {
				int x = pl[0], y = pl[d];
				auto [l, r] = minmax({x, y});
				if(seg.prod(l, r) >= i - d) ret[i] = 1;
			}
		}
		return ret;
	};


	if(!slv(s).back()) {
    cout << 1 << endl;
    cout << 1 << endl;
    return 0;
  }

	auto vec = slv(s);
	auto vec2 = slv({s.rbegin(), s.rend()});
	reverse(ALL(vec2));
	int res = 0;
	rep(i, 1, n) {
		if(!vec[i] and !vec2[i]) res++;
	}
  cout << 2 << endl << res << endl;
}