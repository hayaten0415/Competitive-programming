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

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}


void solve() {
  int n;
  ll x, y;
  cin >> n >> x >> y;
  if(n == 2){
    cout << x << " " << y << endl;
    return;
  }
  ll d = y - x;
  vector<ll> div = divisor(d);
  ll mn = 1LL << 60;
  ll num = -1;
  for(auto res: div){
    vector<ll> ans;
    ll s = y- res;
    ll f = y + res;
    ans.pb(y);
    rep(i, n-1){
      if(s > 0){
        ans.pb(s);
        s -= res;
      }else{
        ans.pb(f);
        f += res;
      }
    }
    sort(ALL(ans));
    if(ans[0] > x)continue;
    if (chmin(mn, ans[n-1])){
      num = res;
    }
  }
  rep(i, n){
    cout << mn << (i == n - 1 ? "\n" : " ");
    mn -= num;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}