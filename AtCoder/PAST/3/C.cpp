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
const ll mx = 1000000000;

ll mypow(ll x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return mypow(x * x, n / 2);
  else
    return x * mypow(x, n - 1);
}

int main() {
  ll a, r, n;
  cin >> a >> r >> n;
  if(r == 1){
    cout << a << endl;
    return 0;
  }
  ll num = a;
  ll count = 1;
  while (num <= mx){
    num *= r;
    count++;
  }
  if(count >=n){
    ll ans =  a * mypow(r, n - 1);
    if(ans <= mx){
      cout << ans << endl;
    }else{
      cout << "large" << endl;
    }
  }else{
    cout << "large" << endl;
  }
}