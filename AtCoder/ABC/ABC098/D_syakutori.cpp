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
  int n;
  cin >> n;
  deque<ll> q;
  ll ans = 0;
  vector<ll> A(n);
  rep(i, n){
    cin >> A[i];
  }
  ll sum_plus = 0;
  ll sum_xor = 0;
  rep(i, n){
    sum_plus += A[i];
    sum_xor ^= A[i];
    q.push_back(A[i]);
    while(sum_plus != sum_xor){ //条件を満たさない間左端をpopする
      ll d = q.front();
      q.pop_front();
      sum_xor ^= d;
      sum_plus -= d;
    }
    //条件を満たす範囲になった
    ll d = q.size();
    ans += d;
  }
  cout << ans << endl;
}