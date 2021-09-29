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

// reference https://onlinejudge.u-aizu.ac.jp/services/review.html#ACPC2021Day2/5914978

struct MaxClique{
	int n;
	vector<int> tableL, tableH;
	vector<ll> wsum, wsum2;
	vector<int> valid, valid2;
	vector<PL> dp;
	
	vector<vector<int> > G;
	vector<ll> weight;
	vector<int> ans;
	
	MaxClique(){}
	MaxClique(int n){ //頂点は0-indexedにするべし
		this->n = n;
		G.resize(n), weight.resize(n);
		for(int i = 0; i < n; i++) G[i].resize(n), G[i][i] = 1, weight[i] = 1;
	}
	void add_edge(int u, int v){
		G[u][v] = G[v][u] = 1;
	}
	void set_weight(vector<ll> &vec){
		weight = vec;
	}
		
	ll calc() //最大重みクリークをansに格納しその重みを返す
	{
		if(n == 1){
			ans.clear();
			ans.push_back(0);
			return weight[0];
		}
		
		int N = 1<<(n/2), N2 = 1<<(n-n/2);
		tableL.resize(n), tableH.resize(n);
		wsum.resize(N), wsum2.resize(N2), valid.resize(N2), valid2.resize(N2), dp.resize(N2);
		
		for(int i = 1; i < N; i++) rep(j, 0, n/2) if(i & (1<<j)) wsum[i] += weight[j];
		for(int i = 1; i < N2; i++) rep(j, 0, (n-n/2)) if(i & (1<<j)) wsum2[i] += weight[n/2+j];
		
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n/2; j++) tableL[i] |= G[i][j] << j;
			for(int j = n/2; j < n; j++) tableH[i] |= G[i][j] << (j-n/2);
		}
		
		for(int i = 0; i < N; i++){
			int val = i;
			for(int j = 0; j < n/2; j++) if(i & (1<<j)) val &= tableL[j];
			if(val == i) valid[i] = 1;
		}
		for(int i = 0; i < N2; i++){
			int val = i;
			for(int j = 0; j < n-n/2; j++) if(i & (1<<j)) val &= tableH[j+n/2];
			if(val == i) valid2[i] = 1;
		}
		
		for(int i = 0; i < N2; i++){
			if(valid2[i]){
				dp[i] = PL(wsum2[i], i);
				continue;
			}
			dp[i] = PL(0, i);
			for(int j = 0; j < n-n/2; j++) dp[i] = max(dp[i], dp[i & ~(1<<j)]);
		}
		
		ll ret = 0; int ret_i = 0, ret_j = 0;
		for(int i = 0; i < N; i++){
			if(!valid[i]) continue;
			int val = (1<<(n-n/2)) - 1;
			for(int j = 0; j < n/2; j++) if(i & (1<<j)) val &= tableH[j];
			
			if(ret < wsum[i] + dp[val].first){
				ret = wsum[i] + dp[val].first;
				ret_i = i, ret_j = dp[val].second;
			}
		}
		
		ans.clear();
		for(int i = 0; i < n/2; i++) if(ret_i & (1<<i)) ans.push_back(i);
		for(int i = 0; i < n-n/2; i++) if(ret_j & (1<<i)) ans.push_back(i+n/2);
		
		return ret;
	}
};

// verify https://judge.yosupo.jp/problem/maximum_independent_set

ll m, n;
vector<ll> vec[1005];
int A[45][45];


int main() {
	cin >> n >> m;
	ll u, v;
	rep(i, m){
		cin >> u >> v;
		A[u][v] = A[v][u] = 1;
	}
	MaxClique mc(n);
	rep(i, n) rep(j, n) if (i < j && A[i][j] == 0) mc.add_edge(i, j);
	mc.calc();
	cout << sz(mc.ans) << endl;
	for(auto d : mc.ans){
		cout << d << " ";
	}
	cout << endl;
}