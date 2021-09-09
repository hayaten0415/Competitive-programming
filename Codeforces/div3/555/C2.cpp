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
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using P = pair<int, char>;
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


void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  string res;
  int l = 0, r = n - 1;
  int lst = 0;
  while (l <= r) {
		vector<P> cur;
		if (lst < a[l]) cur.pb({a[l], 'L'});
		if (lst < a[r]) cur.pb({a[r], 'R'});
		sort(ALL(cur));
		if (int(cur.size()) == 2 && cur[0].fi != cur[1].fi) {
			cur.pop_back();
		}
		if (int(cur.size()) == 1) {
			if (cur[0].second == 'L') {
				res += 'L';
				lst = a[l];
				++l;
			} else {
				res += 'R';
				lst = a[r];
				--r;
			}
		} else if ((int)cur.size() == 2){
      int cl = 1, cr = 1;
			while (l + cl <= r && a[l + cl] > a[l + cl - 1]) ++cl;
			while (r - cr >= l && a[r - cr] > a[r - cr + 1]) ++cr;
			if (cl > cr) {
				res += string(cl, 'L');
			} else {
				res += string(cr, 'R');
			}
      break;
		}else{
      break;
    }
  }
  cout << res.size() << endl << res << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}