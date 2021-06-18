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
  ll a, b, k;
  cin >> a >> b >> k;
  ll d = lcm(a, b);
  ll left = 0;
  ll right = 1000000000000000000;
  while (right - left > 1){
    ll mid = (right + left) / 2;
    auto ok = [&](ll x) {
      ll num = (x / a) + (x / b) - (x / d);
      return num >= k;
    };
    if(ok(mid)){
      right = mid;
    }else{
      left = mid;
    }
  }
  cout << right << endl;
}