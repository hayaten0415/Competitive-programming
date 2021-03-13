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

int main() {
  int n;
  cin >> n;
  int u = 1;
  int v = 0;
  int z = 0;
  ll max_dist = 0;
  ll dist;
  for (int i = 1; i <= n; i++){
    cout << "? " << 1 << " " << i << endl;
    cin >> dist;
    if(chmax(max_dist, dist)){
      v = i;
    }
  }
  for (int i = 1; i <= n; i++){
    cout << "? " << v << " " << i << endl;
    cin >> dist;
    chmax(max_dist, dist);
  }
  cout << "! " << max_dist << endl;
}