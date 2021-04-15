//#pragma region Macros
// #pragma GCC target("avx2")
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


void solve() {
  int x, y, z;
  cin >> x >> y >> z;
  int a,b,c;
  rep(i, 2)rep(j, 2)rep(k, 2){
    a = 1, b = 1, c = 1;
    if(i == 0)a = x;
    if(i == 1)b = x;
    if(j == 0)a = y;
    if(j == 1)c = y;
    if(k == 0)b = z;
    if(k == 1)c = z;
    if(max(a, b) == x && max(a,c) == y && max(b, c) == z){
      cout << "YES" << endl;
      cout << a << " " << b << " " << c << endl;
      return;
    }
  }
  cout << "NO" << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}