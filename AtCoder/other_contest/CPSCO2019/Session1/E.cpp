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

int main() {
  int n, q;
  cin >> n >> q;
  map<int, int> mp;
  rep(i, n){
    int a;
    cin >> a;
    mp[a]++;
  }
  auto f = [&](int l, int r, int x) -> void{
    auto begin = mp.lower_bound(l);
    auto last = mp.upper_bound(r);
    if(begin == last){
      cout << 0 << endl;
    }else{
      int res = 0;
      int cn = 0;
      while (begin != last) {
        int d = begin->first;
        int b = begin->second;
        if(b % 2 == 1){
          res ^= d;
        }
        cn += b;
        begin++;
      }
      cout << res << endl;
      begin = mp.lower_bound(l);
      mp.erase(begin, last);
      mp[x] += cn;
    }
  };
  rep(i, q){
    int a, b, c;
    cin >> a >> b >> c;
    f(a, b, c);
  }
}