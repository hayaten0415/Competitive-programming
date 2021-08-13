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

int op1(int a, int b) { return min(a, b); }
int e1() { return  INF<int>; }
int op2(int a, int b) { return max(a, b); }
int e2() { return -INF<int>; }
int target;

bool f1(int v) { return (v <= target); }
bool f2(int v) { return (v >= target); }

int main() {
  int n, q;
  cin >> n >> q;
  vector<int> L(n - 1), R(n - 1);
  rep(i, n - 1) cin >> L[i] >> R[i];
  segtree<int, op2, e2> segmx(L);
  segtree<int, op1, e1> segmn(R);
  rep(i, q){
    int b;
    cin >> target >> b;
    b--;
    int res = 1;
    if(b < n-1){
      int c = segmx.max_right<f1>(b);
      int d = segmn.max_right<f2>(b);
      res += min(c, d) - b;
    }
    if(b > 0){
      int c = segmx.min_left<f1>(b);
      int d = segmn.min_left<f2>(b);
      res += b - max(c, d);
    }
    cout << res << endl;
  }
}