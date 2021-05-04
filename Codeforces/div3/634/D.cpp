#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
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
  vector<string> grid(9);
  rep(i, 9) cin >> grid[i];
  vector<P> num;
  num.push_back({0, 0});
  num.push_back({1, 4});
  num.push_back({2, 8});
  num.push_back({3, 1});
  num.push_back({4, 3});
  num.push_back({5, 6});
  num.push_back({6, 2});
  num.push_back({7, 5});
  num.push_back({8, 7});
  vector<int> cn(10);
  for (int i = 0; i < 9; i++){
    int f = grid[num[i].first][num[i].second] - '0';
    for (int j = 1; j < 10; j++){
      if(f == j)continue;
      grid[num[i].first][num[i].second] = j +  '0';
      break;
    }
  }
  rep(i, 9){
    cout << grid[i] << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}