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
  int n, l, r;
  ll s;
  cin >> n >> l >> r >> s;
  ll sz = r - l + 1;
  ll mn = (sz * (sz + 1)) / 2;
  ll mx = 0;
  vector<ll> mx_ar(sz);
  int d = 0;
  for (ll i = n - sz + 1; i <= n; i++){
    mx_ar[d] = i;
    mx += i;
    d++;
  }
  if (mn <= s && s <= mx){
    ll ma = n;
    ll mi = 1;
    int idx = sz-1;
    while (ma - mi < mx - s){
      mx_ar[idx] = mi;
      mi++;
      idx--;
      ma--;
      mx -= (ma + 1 - (mi -1));
    }
    set<int> st;
    set<int> st2;
    rep(i, n) st2.insert(i + 1);
    l--, r--;
    map<int, int> mp;
    rep(i, sz){
      st.insert(mx_ar[i]);
      st2.erase(mx_ar[i]);
    }
    rep(i, sz){
      int f = mx_ar[i] - (mx- s);
      if(f <= 0)continue;
      if(st.find(f) == st.end()){
        st.insert(f);
        st.erase(mx_ar[i]);
        st2.insert(mx_ar[i]);
        st2.erase(f);
        mx_ar[i] = f;
        break;
      }
    }
    vector<int> ans(n);
    int e =l;

    for(auto w : st){
      ans[e] = w;
      e++;
    }
    rep(i, n){
      if(l <= i && i <= r)continue;
      ans[i] = *st2.begin();
      st2.erase(ans[i]);
    }
    rep(i, n){
      cout << ans[i] << (i == n - 1 ? "\n" : " ");
    }
  }else{
    cout << -1 << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}