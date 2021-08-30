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
  int n;
  ll k;
  cin >> n >> k;
  vector<ll> A(n);
  rep(i, n) cin >> A[i];
  sort(ALL(A), greater{});
  ll num = 1;
  ll ans = 0;
  bool finish = false;
  rep(i, n-1){
    ll d = A[i] - A[i+1];
    if(num * d > k){
      ll c = k / num;
      ans += num * (A[i] + A[i] - c + 1) * c / 2;
      ll f = k % num;
      ans += (A[i] - c) * f;
      finish = true;
      break;
    }else{
      ans += num * (A[i + 1] + 1 + A[i]) * (A[i] - A[i + 1]) / 2;
      A[i] = A[i + 1];
      k -= d * num;
      num++;
    }
  }
  if(finish){
    cout << ans << endl;
  }else{
    if(A[n-1] * n <= k){
      ans += n * ((1 + A[n - 1]) * A[n - 1]) / 2;
      cout << ans << endl;
    }else{
      ll c = k / n;
      ans += n * (A[n - 1] + A[n - 1] - c + 1) * c / 2;
      ll f = k % n;
      ans += (A[n - 1] - c) * f;
      cout << ans << endl;
    }
  }
}