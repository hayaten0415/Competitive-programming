#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
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


void solve(){
  int n;
  cin >> n;
  int left = 1, right = n + 1;
  int ans = 0;
  auto f = [&](int x){
    cout << "? " << x << endl;
    cout.flush();
    int d;
    cin >> d;
    chmax(ans, d);
    return d;
  };
  rep(i, 19){
    int t1 = (2 * left + right) / 3;
    int t2 = (left + 2 * right) / 3;
    if(f(t1) > f(t2)){
      right = t2;
    }else{
      left = t1;
    }
  }
  cout << "! " << ans << endl;
  return;
}

int main() {
  int t;
  cin >> t;
  while(t--)solve();
}