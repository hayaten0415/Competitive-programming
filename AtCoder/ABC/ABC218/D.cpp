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
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
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

int main() {
  int n;
  cin >> n;
  vector<P> XY(n);
  set<P> st;
  set<array<int, 4>> ans;
  map<P, int> mp;
  rep(i, n){
    cin >> XY[i].fi >> XY[i].se;
    st.insert(XY[i]);
  }
  sort(ALL(XY));
  rep(i, n){
    mp[XY[i]] = i;
  }
  rep(i, n) for (int j = i + 1; j < n; j++){
    if(XY[i].fi == XY[j].fi)continue;
    if(XY[i].se == XY[j].se)continue;
    int b = (XY[j].fi - XY[i].fi);
    int c = (XY[j].se - XY[i].se);
    if(st.find({XY[i].fi + b, XY[i].se}) != st.end() && st.find({XY[i].fi, XY[i].se + c}) != st.end()){
      array<int, 4> tmp = {i, j, mp[{XY[i].fi + b, XY[i].se}], mp[{XY[i].fi, XY[i].se + c}]};
      sort(ALL(tmp));
      ans.insert(tmp);
    }
  }
  cout << ans.size() << endl;
}