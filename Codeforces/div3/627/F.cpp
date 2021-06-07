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

template <typename T>
struct ReRooting
{
  using F = function<T(T, int)>;
  using F2 = function<T(T, T)>;
  static const int MAX_V = 200010;
  int V;
  vector<int> E[MAX_V];
  vector<T> dp[MAX_V];
  //f(v) = g(merge(f(dp_c1,c1), f(dp_c2,c2), ..., f(dp_ck,ck)) , v)
  F f, g;
  F2 merge;
  T mi; //identity of merge

  ReRooting(int V_, F f_, F2 merge_, T mi_, F g_ = [](T a, int b) { return a; })
      : V(V_), f(f_), merge(merge_), mi(mi_), g(g_) {}

  void add_E(int a, int b)
  {
    E[a].push_back(b);
    E[b].push_back(a);
  }

  T dfs1(int p, int v)
  {
    T res = mi;
    for (int i = 0; i < E[v].size(); ++i)
    {
      if (E[v][i] == p)
        continue;
      dp[v][i] = dfs1(v, E[v][i]);
      res = merge(res, f(dp[v][i], E[v][i]));
    }
    return g(res, v);
  }

  void dfs2(int p, int v, T add)
  {
    for (int i = 0; i < E[v].size(); ++i)
    {
      if (E[v][i] == p)
      {
        dp[v][i] = add;
        break;
      }
    }

    vector<T> pL(E[v].size() + 1), pR(E[v].size() + 1);
    pL[0] = mi;
    for (int i = 0; i < E[v].size(); ++i)
      pL[i + 1] = merge(pL[i], f(dp[v][i], E[v][i]));
    pR[E[v].size()] = mi;
    for (int i = E[v].size(); i > 0; --i)
      pR[i - 1] = merge(pR[i], f(dp[v][i - 1], E[v][i - 1]));

    for (int i = 0; i < E[v].size(); ++i)
    {
      if (E[v][i] == p)
        continue;
      T val = merge(pL[i], pR[i + 1]);
      dfs2(v, E[v][i], g(val, v));
    }
  }

  void calc(int root = 0)
  {
    for (int i = 0; i < V; ++i)
      dp[i].resize(E[i].size());
    dfs1(-1, root);
    dfs2(-1, root, mi);
  }

  T solve(int v){
    T ans = mi;
    for (int i = 0; i < E[v].size(); ++i)
    {
      ans = merge(ans, f(dp[v][i], E[v][i]));
    }
    return g(ans, v);
  }
};

int main()
{
  int n;
  cin >> n;
  int c[200010];
  for (int i = 0; i < n; ++i){
    int ci;
    cin >> ci;
    c[i] = (ci == 1 ? 1 : -1);
  }
  auto f = [&](int a, int v) {
    (void)v;
    return max(0, a);
  };
  auto g = [&](int a, int v) {
    return a + c[v];
  };
  ReRooting<int> re(n, f, plus<int>(), 0, g);
  for (int i = 0; i < n - 1; ++i){
    int x, y;
    cin >> x >> y;
    x--, y--;
    re.add_E(x, y);
  }
  re.calc();
  rep(i, n)cout << re.solve(i) << (i == n - 1 ? "\n" : " ");
  return 0;
}