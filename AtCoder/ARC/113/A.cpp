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
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int cnxy[220000];

int main() {
  int k;
  cin >> k;
  for (int i = 1; i < 220000; i++){
    for (int j = 1; i * j < 220000; j++){
      cnxy[i * j]++;
    }
  }
  ll ans = 0;
  for(int c = 1; c <=k; c++){
    for (int d = 1; d * c <= k; d++){
      ans += cnxy[c];
    }
  }
  cout << ans << endl;
}