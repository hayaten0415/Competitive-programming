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

int main() {
  ll n, m, k;
  cin >> k >> n >> m;
  vector<ll> A(k);
  rep(i, k) cin >> A[i];
  auto ok = [&](ll mid)-> bool{
    ll mn = 0, mx = 0;
    rep(i, k){
      ll d1 = (A[i] * m + mid) / n;
      ll d2 = -(mid - A[i] * m - n +1) / n;
      mx += d1;
      mn += max(0ll, d2);
    }
    return (mn <= m && m <= mx);
  };
  ll left = -1, right = 1000000000000000000;
  while(right - left > 1){
    ll mid = (right + left) / 2;
    if(ok(mid)){
      right = mid;
    }else{
      left = mid;
    }
  }
  vector<ll> B(k);
  ll sum = 0;
  ll mn = 0, mx = 0;
  rep(i, k){
    ll d1 = (A[i] * m + right) / n;
    ll d2 = -(right - A[i] * m - n +1) / n;
    mx += d1;
    mn += max(0ll, d2);
    B[i] = max(0ll, d2);
  }
  ll b_sum = accumulate(ALL(B), 0);
  rep(i, k){
    ll d1 = (A[i] * m + right) / n;
    ll d2 = -(right - A[i] * m - n + 1) / n;
    ll x = min(m - b_sum, d1 - B[i]);
    B[i] += x;
    b_sum += x;
  }
  rep(i, k){
    cout << B[i] << (i == k - 1 ? "\n" : " ");
  }
}