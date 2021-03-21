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
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

ll mypow(ll x, ll n){
  if(n == 0)
    return 1;
  if(n % 2 == 0)
    return mypow(x * x, n / 2);
  else
    return x * mypow(x, n - 1);
}

int main() {
  ll m, k;
  cin >> m >> k;
  ll d = mypow(2, m);
  if(k >=d){
    cout << -1 << endl;
    return 0;
  }
  if(m == 1 && k != 0){
    cout << -1 << endl;
    return 0;
  }
  if(m == 1 && k == 0){
    cout << 1 << " " << 1 << " " << 0 << " " << 0 << endl;
    return 0;
  }
  vector<ll> A;
  rep(i, d){
    if(i != k)A.eb(i);
  }
  vector<ll> rev_A = A;
  reverse(ALL(rev_A));
  A.eb(k);
  rev_A.eb(k);
  rep(i, 1LL << (m + 1)){
    if(i < (1LL << m)){
      cout << A[i] << " ";
    }else{
      cout << rev_A[i - (1LL << m)] << " ";
    }
  }
  cout << endl;
}