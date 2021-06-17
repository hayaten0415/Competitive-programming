#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
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