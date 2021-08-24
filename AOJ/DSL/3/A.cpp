#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
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
using namespace std;
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
  int n, k;
  cin >> n >> k;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  int sum = 0;
  deque<int> q;
  int ans = n + 1;
  rep(i, n){
    sum += A[i];
    q.push_back(A[i]);
    bool ok = false;
    while(sum >= k){ //条件を満たさない間左端をpopする
      ok = true;
      int d = q.front();
      q.pop_front();
      sum -= d;
    }
    //条件を満たす範囲になった
    if(ok)chmin(ans, (int)q.size() + 1);
  }
  if(ans == n + 1)ans = 0;
  cout << ans << endl;
}