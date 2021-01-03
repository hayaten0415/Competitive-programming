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
  int n, a;
  cin >> n >> a;
  string s;
  cin >> s;
  a--;
  vector<ll> right, left;
  for (int i = a; i < n; i++){
    if(s[i] == '#')right.emplace_back(i -a);
  }
  for (int i = a; i >= 0; i--){
    if(s[i] == '#')left.emplace_back(a-i);
  }
  ll ans = 0;
  int left_count = left.size();
  int right_count = right.size();
  if(left_count < right_count){
    rep(i, left_count){
      ans += 2 * left[i];
    }
    rep(i, right_count){
      if(i == right_count-1)ans += right[i];
      else ans += 2 * right[i];
    }
    ans += (ll)(right_count - left_count - 1) * 2 * (a + 1);
  }else{
    rep(i, left_count){
      if(i == left_count-1) ans += left[i];
      else ans += 2 * left[i];
    }
    rep(i, right_count){
      ans += 2 * right[i];
    }
    ans += (ll)(left_count- right_count) * 2 * (n - a);
  }
  cout << ans << endl;
}