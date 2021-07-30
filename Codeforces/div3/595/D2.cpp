#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int mx = 202020;
vector<int> in[202020];
vector<int> out[202020];
vector<int> l(mx);
vector<int> r(mx);

void solve() {
  int n, k;
  cin >> n >> k;
  rep(i, n){
    cin >> l[i] >> r[i];
    in[l[i]].push_back(i);
    out[r[i] + 1].push_back(i);
  }
  set<P> st;
  vector<int> ans;
  rep(i, mx){
    for (int j : in[i])st.insert({r[j], j});
		for (int j : out[i])st.erase({r[j], j});
    while ((int)st.size() > k){
      auto it = st.end();
      it--;
      ans.push_back((*it).second);
      st.erase(it);
    }
  }
  cout << ans.size() << endl;
  for(int d : ans){
    cout << d + 1 << " ";
  }
  cout << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t = 1;
  while(t--) solve();
}