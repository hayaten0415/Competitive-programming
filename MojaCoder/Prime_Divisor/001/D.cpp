#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
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
const auto INF = numeric_limits<T>::max()/2;
Graph G;
int A[1000];
int ans = 0;

void dfs(int u, int p, int c){
  if(c == 1 && p != -1)ans++;
  for(auto v : G[u]){
    if(v == p)continue;
    dfs(v, u, gcd(A[v], c));
  }
  return;
}

int main() {
  int n;
  cin >> n;
  rep(i, n) cin >> A[i];
  G.resize(n);
  rep(i, n-1){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].eb(b);
    G[b].eb(a);
  }
  rep(i, n){
    dfs(i, -1, A[i]);
  }
  cout << ans / 2 << endl;
}