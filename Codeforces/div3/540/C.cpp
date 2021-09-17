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
#define forn(i, n) for (int i = 0; i < int(n); i++)
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
const auto INF = numeric_limits<T>::max() / 2;
int ans[20][20];

const int N = 1000 + 7;

int cnt[N];
int a[20][20];

int main() {
	int n;
	scanf("%d", &n);
	forn(i, n * n){
		int x;
		scanf("%d", &x);
		++cnt[x];
	}
	
	vector<pair<int, P>> cells;
	forn(i, (n + 1) / 2) forn(j, (n + 1) / 2){
		if (i != n - i - 1 && j != n - j - 1)
			cells.push_back({4, {i, j}});
		else if ((i != n - i - 1) ^ (j != n - j - 1))
			cells.push_back({2, {i, j}});
		else
			cells.push_back({1, {i, j}});
	}
	
	for (auto cur : {4, 2, 1}){
		int lst = 1;
		for (auto it : cells){
			if (it.first != cur) continue;
			int i = it.second.first;
			int j = it.second.second;
			while (lst < N && cnt[lst] < cur)
				++lst;
			if (lst == N){
				puts("NO");
				return 0;
			}
			a[i][j] = a[n - i - 1][j] = a[i][n - j - 1] = a[n - i - 1][n - j - 1] = lst;
			cnt[lst] -= cur;
		}
	}
	
	puts("YES");
	forn(i, n){
		forn(j, n)
			printf("%d ", a[i][j]);
		puts("");
	}
	return 0;
}
