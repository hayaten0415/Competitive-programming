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

template <typename T>
struct binary_indexed_tree{
  int N;
  vector<T> BIT;
  binary_indexed_tree(int N): N(N), BIT(N + 1, 0){
  }
  void add(int i, T x){
    i++;
    while (i <= N){
      BIT[i] += x;
      i += i & -i;
    }
  }
  T sum(int i){
    T ans = 0;
    while (i > 0){
      ans += BIT[i];
      i -= i & -i;
    }
    return ans;
  }
  T sum(int L, int R){
    return sum(R) - sum(L);
  }
};

//配列Aを配列Bに変えるための隣接swapの最小回数
ll inversion(vector<ll> A, vector<ll> B){
	if(sz(A) != sz(B)) return -1;
	int n = sz(A);
	
	map<ll, vector<int> > mp;
	rep(i, sz(B)) mp[B[i]].push_back(i);
	for(auto &p : mp) reverse(ALL(p.second));
	
	vector<int> perm;
	for(auto x : A){
		if(sz(mp[x]) == 0) return -1;
		perm.push_back(mp[x].back());
		mp[x].pop_back();
	}
	ll ret = 0; binary_indexed_tree<ll> bit(n);
	for(auto x : perm){
		ret += bit.sum(x, n);
		bit.add(x, 1);
	}
	return ret;
}

// verify https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2021Day3/problems/F

int main(){
  int n;
  cin >> n;
  vector<ll> A(n), B(n);
  rep(i, n){
    cin >> A[i];
    if(i)A[i] += A[i-1];
  }
  rep(i, n){
    cin >> B[i];
    if(i)B[i] += B[i-1];
  }
  if(A[n-1] != B[n-1]){
		cout << -1 << endl;
		return 0;
	}
  cout << inversion(A, B) << endl;
}
