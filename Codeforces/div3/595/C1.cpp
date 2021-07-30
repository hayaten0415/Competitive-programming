#include <bits/stdc++.h>
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
const ll INF = (1LL << 62);
vector<ll> three;

void solve() {
  ll n;
  cin >> n;
  //
  int n1 = three.size() / 2;
  int n2 = three.size() - n1;
  vector<ll> three1, three2;
  rep(bit, (1<< n1)){
    ll sum = 0;
    rep(i, n1){
      if(bit & (1 << i)){
        sum += three[i];
      }
    }
    if(sum > three[38])continue;
    three1.pb(sum);
  }
  rep(bit, (1<< n2)){
    ll sum = 0;
    rep(i, n2){
      if(bit & (1 << i)){
        sum += three[n1 + i];
      }
    }
    if(sum > three[38])continue;
    three2.pb(sum);
  }
  sort(ALL(three2));
  sort(ALL(three1));
  int s = three1.size();
  ll ans = INF;
  int b = lower_bound(ALL(three1), n) - three1.begin();
  rrep(i, b){
    if(three1[i] >= n){
      chmin(ans, three1[i]);
      break;
    }
    auto e = lower_bound(ALL(three2), n - three1[i]);
    ll b = *e;
    if(three1[i] + b >= n){
      chmin(ans, three1[i] + b);
    }
  }
  cout << ans << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  ll d = 1;
  while(d < INF / 3){
    three.pb(d);
    d *= 3;
  }
  int t;
  cin >> t;
  while(t--) solve();
}