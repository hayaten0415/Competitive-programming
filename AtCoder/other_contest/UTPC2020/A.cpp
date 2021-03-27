#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
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
  int n, L;
  cin >> n >> L;
  vector<ll> A(n), X(n);
  rep(i, n) cin >> X[i] >> A[i];
  auto ok = [&](ll x) {
    ll energy = x;
    ll now = 0;
    rep(i, n){
      energy = min(x, energy + (X[i] - now));
      energy -= A[i];
      if(energy < 0)return false;
      now = X[i];
    }
    return true;
  };
  ll left = 0, right = 1e18;
  while (right - left > 1){
    ll mid = (right + left) / 2;
    if(ok(mid)){
      right = mid;
    }else{
      left = mid;
    }
  }
  cout << right << endl;
}