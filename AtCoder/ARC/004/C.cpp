#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll string_to_long(string s){
  reverse(ALL(s));
  int n = s.size();
  ll ten = 1;
  ll res = 0;
  rep(i, n){
    ll k = s[i] - '0';
    res += k * ten;
    ten *= 10;
  }
  return res;
}

int main() {
  string s;
  cin >> s;
  vector<string> v;
  regex separator{"/"};
  auto ite = std::sregex_token_iterator(s.begin(), s.end(), separator, -1);
  auto end = std::sregex_token_iterator();
  while (ite != end) {
    v.push_back(*ite++);     // 分割文字列を格納
  }
  ll x = string_to_long(v[0]);
  ll y = string_to_long(v[1]);
  ll d = gcd(x, y);
  x /= d;
  y /= d;
  bool ok = false;
  ll mn = 2 * x / y - 1;
  ll mx = 2 * x / y + 1;
  for (ll n = mn; n <= mx; n++){
    if(n % y != 0)continue;
    ll m = n * (n + 1) / 2 - n / y * x;
    if(0 < m && m <= n){
      cout << n << " " << m << endl;
      ok = true;
    }
  }
  if(!ok){
    cout << "Impossible" << endl;
  }
}