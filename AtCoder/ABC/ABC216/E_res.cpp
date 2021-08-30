#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max()/2;

int main() {
  ll n, k;
  cin >> n >> k;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  auto f = [&](ll x) {
    ll cn = 0;
    rep(i, n){
      if(A[i] > x){
        cn += A[i] - x;
      }
    }
    return cn <= k;
  };
  ll ng = -1, ok = 2e9+ 1;
  while(ok - ng > 1){
    ll mid = (ng + ok) / 2;
    if(f(mid)){
      ok = mid;
    }else{
      ng = mid;
    }
  }
  ll ans = 0;
  rep(i, n){
    if(A[i] > ok){
      k -= (A[i] - ok);
      ans += (ok + 1 + A[i]) * (A[i] - ok)/ 2;
    }
  }
  if(k > 0)ans += k * ok;
  cout << ans << endl;
}