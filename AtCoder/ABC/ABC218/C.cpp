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
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
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

vector<string> rev(vector<string> s) {
	int h = s.size();
	int w = s[0].size();
	vector<string> res(w);
	rep(i, w)res[i].resize(h);
	rep(i, h)rep(j, w) {
		res[j][h - 1 - i] = s[i][j];
	}
	return res;
}


int main() {
  int n;
  cin >> n;
  vector<string> s(n), t(n);
  rep(i, n) cin >> s[i];
  rep(i, n) cin >> t[i];
  vector<P> st;
  rep(i, n) rep(j, n){
    if(t[i][j] == '#')st.pb({i, j});
  }
  rep(k, 4){
    vector<P> st2;
    rep(i, n)rep(j, n){
      if(s[i][j] == '#')st2.pb({i, j});
    }
    if(st.size() != st2.size()){
      cout << "No" << endl;
      return 0;
    }
    P a = st[0];
    P c = st2[0];
    P ress = {c.fi - a.fi, c.se - a.se};
    int d = st.size();
    bool ok = true;
    rep(i, d){
      P tmp = {st[i].fi + ress.fi, st[i].se + ress.se};
      if (tmp != st2[i]){
        ok = false;
        break;
      }
    }
    if(ok){
      cout << "Yes" << endl;
      return 0;
    }
    s = rev(s);
  }
  cout << "No" << endl;
}