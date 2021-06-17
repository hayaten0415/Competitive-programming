#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


//小数を10^x倍して整数で返すライブラリ
ll double_string_to_longlong(string s, int x){
  int c = x;
  int n = s.size();
  string res = "";
  bool float_ok = false;
  rep(i, n){
    if(s[i] == '.'){
      float_ok = true;
      continue;
    }
    if(float_ok){
      c--;
    }
    res.pb(s[i]);
  }
  ll num = stol(res);
  rep(i, c){
    num *= 10;
  }
  return num;
}

ll closedsection_k(ll a, ll b, ll k){
  if(a > b)return 0LL;
  ll r = a % k;
  ll m = a - r;
  ll res = ((b - m) / k) + 1;
  if(r > 0)res--;
  return res;
}

//閉区間[a,b]のうちkの倍数がいくつあるか
ll closedsection(ll a, ll b, ll k){
  if(a < 0 && b < 0){
    return closedsection_k(abs(b), abs(a), k);
  }else if(a < 0 && b >= 0){
    return closedsection_k(0, abs(a), k) + closedsection_k(1, b, k);
  }else{
    return closedsection_k(a, b, k);
  }
}


int main() {
  string x_tmp, y_tmp, r_tmp;
  cin >> x_tmp >> y_tmp >> r_tmp;
  ll x = double_string_to_longlong(x_tmp, 4);
  ll y = double_string_to_longlong(y_tmp, 4);
  ll r = double_string_to_longlong(r_tmp, 4);
  auto ok = [&](ll y_a, ll x_a) {
    return ((y -  y_a) * (y -  y_a) + (x - x_a) * (x - x_a)) <= (r * r);
  };
  ll start_x = x - r;
  ll d = abs(x - r);
  ll c = d % 10000;
  if(start_x < 0){
    start_x += c;
  }else{
    start_x += ((10000 - c) % 10000);
  }
  ll ans = 0;
  for (ll i = start_x; i <= x + r; i += 10000){
    ll left = y-1, right = y + r + 1;
    while(right - left > 1){
      ll mid = (left + right) / 2;
      if(ok(mid , i)){
        left = mid;
      }else{
        right = mid;
      }
    }
    ans += closedsection(y, left, (ll)10000);
    left = y - r - 1, right = y;
    while(right - left > 1){
      ll mid = (left + right) / 2;
      if(ok(mid , i)){
        right = mid;
      }else{
        left = mid;
      }
    }
    ans += closedsection(right, y, (ll)10000);
    if(y % 10000 == 0)ans--;
  }
  cout << ans << endl;
}