#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
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


void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> tree(n);
  set<ll> st;
  priority_queue<PL, vector<PL>, greater<PL>> pq;
  rep(i, n){
    cin >> tree[i];
    st.insert(tree[i]);
  }
  sort(ALL(tree));
  vector<ll> ans(m);
  rep(i, n){
    if(st.find(tree[i]-1) == st.end()){
      pq.push({1, tree[i] - 1});
      st.insert(tree[i] - 1);
    }
    if(st.find(tree[i]+1) == st.end()){
      pq.push({1, tree[i] + 1});
      st.insert(tree[i] + 1);
    }
  }
  ll res = 0;
  rep(i, m){
    ll a = pq.top().first;
    ll b = pq.top().second;
    pq.pop();
    ans[i] = b;
    res += a;
    if(st.find(b-1) == st.end()){
      pq.push({a + 1, b - 1});
      st.insert(b - 1);
    }
    if(st.find(b+1) == st.end()){
      pq.push({a + 1, b + 1});
      st.insert(b + 1);
    }
  }
  cout << res << endl;
  rep(i, m){
    cout << ans[i] << (i == m - 1 ? "\n" : " ");
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t = 1;
  while(t--) solve();
}