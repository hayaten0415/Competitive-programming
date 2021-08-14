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
  int n, p, q;
  cin >> n >> p >> q;
  vector<ll> A(n);
  rep(i, n){
    cin >> A[i];
    A[i] %= p;
  }
  ll ans = 0;
  rep(i, n)for(int j = i + 1; j < n; j++)for (int s = j + 1; s < n; s++)for (int k = s + 1; k < n; k++)for (int d = k + 1; d < n; d++){
    ll num = A[i] * A[j];
    num %= p;
    num *= A[s];
    num %= p;
    num *= A[k];
    num %= p;
    num *= A[d];
    num %= p;
    if(num == q)ans++;
  }
  cout << ans << endl;
}