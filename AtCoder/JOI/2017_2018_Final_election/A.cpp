#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
using P = pair<ll, int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, k;
  cin >> n >> k;
  k--;
  vector<ll> time(n);
  rep(i, n) cin >> time[i];
  vector<ll> between_time(n - 1);
  vector<int> fire(n - 1, 0);
  vector<P> sort_between_time(n - 1);
  rep(i, n-1){
    between_time[i] = time[i + 1] - time[i];
    sort_between_time[i] = {between_time[i], i};
  }
  sort(ALL(sort_between_time), greater<P>());
  rep(i, k){
    fire[sort_between_time[i].second] = 1;
  }
  ll first = time[0];
  ll ans = 0;
  rep(i, n-1){
    if(fire[i] == 1){
      ans += time[i] + 1LL - first;
      first = time[i + 1];
    }
  }
  ans += time[n - 1] + 1LL - first;
  cout << ans << endl;
}