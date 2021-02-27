#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
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
  ll k;
  cin >> k;
  vector<ll> A(10, k);
  vector<ll> Taka(10, 0), Aoki(10, 0);
  string s, t;
  cin >> s >> t;
  rep(i, 4){
    int d = s[i] - '0';
    int a = t[i] - '0';
    A[a]--;
    A[d]--;
    Taka[d]++;
    Aoki[a]++;
  }
  ll denomin = (ll)(9 * k - 8) * (9 * k - 9);
  ll molecule = 0;
  for (ll i = 1; i < 10; i++){
    if(A[i] == 0)continue;
    for (ll j = 1; j < 10; j++){
      if(A[j] == 0)continue;
      if(i == j && A[i] < 2)continue;
      ll Taka_score = 0;
      ll Aoki_score = 0;
      for (ll d = 1; d< 10; d++){
        if(i == d){
          Taka_score += d * mypow(10, Taka[d] + 1);
        }else{
          Taka_score += d * mypow(10, Taka[d]);
        }
      }
      for (ll d = 1; d < 10; d++){
        if(j == d){
          Aoki_score += d * mypow(10, Aoki[d] + 1);
        }else{
          Aoki_score += d * mypow(10, Aoki[d]);
        }
      }
      if(Taka_score > Aoki_score){
        if(i == j){
          molecule += (A[i] * (A[i]-1));
        }else{
          molecule += (A[i] * A[j]);
        }
      }
    }
  }
  long double ans = (long double)molecule / (long double)denomin;
  cout << fixed << setprecision(9) << ans << endl;
}