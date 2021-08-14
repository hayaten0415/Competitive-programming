#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
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
const auto INF = numeric_limits<T>::max();


//0-indexed
template<typename T>
struct BIT {
  int n;
  vector<T> d;
  BIT(int n = 0) : n(n), d(n + 1) {}
  void add(int i, T x) {
    for (i++; i <= n; i += i & -i){
      d[i] += x;
    }
  }
  
  T sum(int i) {
    T num = 0;
    for (i++; i; i -= i & -i){
      num += d[i];
    }
    return num;
  }
  /* [l, r), a and b are 0-indexed */
  T sum(int l, int r) {
    return sum(r) - sum(l);
  }

  int get(long long k) {
      ++k;
      int res = 0;
      int N = 1; while (N < (int)d.size()) N *= 2;
      for (int i = N / 2; i > 0; i /= 2) {
          if (res + i < (int)d.size() && d[res + i] < k) {
              k = k - d[res + i];
              res = res + i;
          }
      }
      return res + 1;
  }
};


int main() {
  int h, w, m;
  cin >> h >> w >> m;
  vector<int> A(w, h), B(h, w);
  rep(i, m){
    int x, y;
    cin >> x >> y;
    x--,y--;
    chmin(A[y], x);
    chmin(B[x], y);
  }
  ll ans = 0;
  rep(i, B[0]) ans += A[i];
  rep(i, A[0]) ans += B[i];
  BIT<ll> b(w+1);
  rep(i, B[0]) b.add(i, 1);
  vector<vector<int>> ends(h + 1);
  rep(i, B[0]) ends[A[i]].pb(i);
  rep(i, A[0]){
    for(int j : ends[i])b.add(j, -1);
    ans -= b.sum(B[i]);
  }
  cout << ans << endl;
}