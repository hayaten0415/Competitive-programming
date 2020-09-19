#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  ll n;
  ll x, m;
  cin >> n >> x >> m;
  ll ans = 0;
  ll num = x;
  bool loop_on = false;
  int last = -1;
  int start = -1;
  vector<ll> tmp(m + 1);
  vector<ll> loop(m + 1);
  map<ll, ll> mp;
  rep(i, min(m, n)){
    tmp[i] = num;
    mp[num]++;
    if(mp[num]> 1){
      last = i;
      loop_on = true;
      break;
    }
    ans += num;
    num *= num;
    num %= m;
  }
  if(loop_on){
    rep(i, m){
      if(tmp[i] == num){
        start = i;
        break;
      }
    }
  }else{
    cout << ans << endl;
    return 0;
  }
  for (int i = start; i < last; i++){
    loop[i + 1 - start] = tmp[i];
  }
  rep(i, last-start){
    loop[i+1] += loop[i];
  }
  if(loop_on){
    n -= last;
    ll count = (ll)n / (ll)(last - start);
    ans += loop[last - start] * count;
    ans += loop[n % (last - start)];
  }
  cout << ans << endl;
}