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

ll mypow(ll x, ll n){
  if(n == 0)
    return 1;
 
  if(n % 2 == 0)
    return mypow(x * x, n / 2);
  else
    return x * mypow(x, n - 1);
}

int main() {
  ll n;
  cin >> n;
  for (ll i = 1; i <= 37; i++){
    for (ll j = 1; j <= 26; j++){
      //if((double)mypow(3LL, i) + mypow(5LL, j) <= 2e18)continue;
      if (mypow(3LL, i) + mypow(5LL, j) == n){
        cout << i << " " << j << endl;
        return 0;
      }
    }
  }
  cout << -1 << endl;
}