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



vector<pair<ll,ll>> prime_factorize(ll n) {
  vector<pair<ll, ll>> res;
  for (long long a = 2; a * a <= n; a++){
    if(n % a != 0) continue;
    ll ex = 0; //指数
    while(n % a == 0){
      ex++;
      n /= a;
    }
    res.push_back(make_pair(a, ex));
  }
  if(n != 1){
    res.push_back(make_pair(n, 1));
  }
  return res;
}

ll mypow(ll x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return mypow(x * x, n / 2);
  else
    return x * mypow(x, n - 1);
}

void solve() {
  ll n;
  cin >> n;
  vector<pair<ll, ll>> ans = prime_factorize(n);
  ll a,b, c;
  if(ans.size() >= 3){
    a = mypow(ans[0].first, ans[0].second);
    b = mypow(ans[1].first, ans[1].second);
    c = 1;
    for (int i = 2; i < ans.size(); i++){
      c *= mypow(ans[i].first, ans[i].second);
    }
    cout << "YES" << endl;
    cout << a << " " << b << " " << c << endl;
  }else if(ans.size() == 2){
    if(ans[0].second >= 3){
      cout << "YES" << endl;
      a = mypow(ans[0].first, 1);
      b = mypow(ans[0].first, ans[0].second - 1);
      c = mypow(ans[1].first, ans[1].second);
      cout << a << " " << b << " " << c << endl;
    }else if(ans[1].second >= 3){
      cout << "YES" << endl;
      a = mypow(ans[1].first, 1);
      b = mypow(ans[1].first, ans[1].second - 1);
      c = mypow(ans[0].first, ans[0].second);
      cout << a << " " << b << " " << c << endl;
    }else if(ans[1].second == 2 && ans[0].second == 2){
      cout << "YES" << endl;
      a = mypow(ans[0].first, 1);
      b = mypow(ans[1].first, 1);
      c = a * b;
      cout << a << " " << b << " " << c << endl;
    }else{
      cout << "NO" << endl;
    }
  }else if(ans.size() == 1){
    if(ans[0].second >= 6){
      cout << "YES" << endl;
      a = mypow(ans[0].first, 1);
      b = mypow(ans[0].first, 2);
      c = mypow(ans[0].first, ans[0].second- 3);
      cout << a << " " << b << " " << c << endl;
    }else{
      cout << "NO" << endl;
    }
  }else{
    cout << "NO" << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}