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
using P = pair<double, double>;
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
  vector<P> A(n);
  rep(i, n){
    int t;
    cin >> t >> A[i].first >> A[i].second;
    if(t ==2)A[i].second-= 0.5;
    if(t ==3){
      A[i].first += 0.5;
    }
    if(t == 4){
      A[i].first += 0.5;
      A[i].second -= 0.5;
    }
  }
  int ans = 0;
  rep(i, n) for (int j = i + 1; j < n; j++){
    if(max(A[i].first, A[j].first) <= min(A[i].second, A[j].second))ans++;
  }
  cout << ans << endl;
}