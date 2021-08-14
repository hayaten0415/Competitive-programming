#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int ans = 0;

ll mypow(ll x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return mypow(x * x, n / 2);
  else
  return x * mypow(x, n - 1);
}

void solve(ll n, ll num) {
  if(n <= 0)return;
  string s = to_string(n);
  int k = s.size();
  ll res = 1;
  rep(i, k){
    res *= (ll)(s[i] - '0');
  }
  if(res == num){
    ans++;
  }
}

int main() {
  ll n, b;
  cin >> n >> b;
  rep(i, 50)rep(j, 40)rep(k, 13)rep(s, 13){
    ll num = mypow(2LL, i) * mypow(3LL, j) * mypow(5LL, k) * mypow(7LL, s);
    ll m = num + b;
    if(m <= 0)continue;
    if(m > n)continue;
    if(num < 0)continue;
    solve(m,num);
  }
  if(b <= n)solve(b, 0);
  cout << ans << endl;
}