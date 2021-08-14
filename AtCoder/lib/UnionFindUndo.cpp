#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
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

struct UnionFindUndo {
  vector< int > data;
  stack< pair< int, int > > history;

  UnionFindUndo(int sz) {
    data.assign(sz, -1);
  }

  bool unite(int x, int y) {
    x = find(x), y = find(y);
    history.emplace(x, data[x]);
    history.emplace(y, data[y]);
    if(x == y) return (false);
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return (true);
  }

  int find(int k) {
    if(data[k] < 0) return (k);
    return (find(data[k]));
  }

  int size(int k) {
    return (-data[find(k)]);
  }

  void undo() {
    data[history.top().first] = history.top().second;
    history.pop();
    data[history.top().first] = history.top().second;
    history.pop();
  }

  void snapshot() {
    while(history.size()) history.pop();
  }

  void rollback() {
    while(history.size()) undo();
  }
};