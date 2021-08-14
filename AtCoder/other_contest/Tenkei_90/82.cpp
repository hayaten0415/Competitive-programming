#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#include <boost/multiprecision/cpp_int.hpp>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
namespace mp = boost::multiprecision;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  ll a, b;
  cin >> a >> b;
  mp::cpp_int l = a, r = b;
  mp::cpp_int num = 1;
  mp::cpp_int d = 1;
  mp::cpp_int ans = 0;
  mp::cpp_int t = 2;
  while(r >= num){
    ans += (((min(num * 10 - 1, r) + num) * (min(num * 10 - 1, r) - (num - 1))) / t) * d;
    num *= 10;
    d++;
  }
  l--;
  num = 1;
  d = 1;
  while(l >= num){
    ans -= (((min(num * 10 - 1, l) + num) * (min(num * 10 - 1, l) - (num - 1))) / t) * d;
    num *= 10;
    d++;
  }
  ans %= (mp::cpp_int)(1e9 + 7);
  cout << ans << endl;
}