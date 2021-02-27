#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
using PP = pair<int, P>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, c;
  cin >> n >> c;
  vector<PP> A(n);
  vector<int> C(c, 0);
  rep(i, n) cin >> A[i].first >> A[i].second.first >> A[i].second.second;
  sort(ALL(A));
  rep(i, n){
    rep(j, c){
      if(C[j] < A[i].first){
        C[j] = A[i].second.first;
        break;
      }
    }
  }
  int ans = 0;
  rep(i, c){
    if(C[i] > 0)ans++;
  }
  cout << ans << endl;
}