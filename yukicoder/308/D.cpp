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
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
using boost::multiprecision::cpp_int;
using PS = pair<P, cpp_int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL <<60);

int main() {
  int n;
  cin >> n;
  int N = (n * (n - 1)) / 2;
  vector<PS> res(N);
  dsu d(n);
  rep(i, N){
    int a, b;
    cpp_int x;
    cin >> a >> b >> x;
    res[i].first = {a, b};
    res[i].second = x;
  }
  cpp_int ans = 0;
  rep(i, N){
    int a = res[i].first.first;
    int b = res[i].first.second;
    a--, b--;
    cpp_int c = res[i].second;
    if(d.same(a, b))continue;
    d.merge(a, b);
    chmax(ans, c);
    if(d.size(a)== n){
      cout << ans << endl;
      return 0;
    }
  }
}