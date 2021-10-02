#include <iostream>
#include <vector>
#include <functional>
using namespace std;

// Referrence https://null-mn.hatenablog.com/entry/2020/04/14/124151

template <typename T>
struct ReRooting
{
  using F = function<T(T, int)>;
  using F2 = function<T(T, T)>;
  static const int MAX_V = 200010;
  vector<int> E[MAX_V];
  vector<T> dp[MAX_V];
  int V;
  //f(v) = g(merge(f(dp_c1,c1), f(dp_c2,c2), ..., f(dp_ck,ck)) , v)
  F f;
  F2 merge;
  T mi; //identity of merge
  F g;

  ReRooting(int V_, F f_, F2 merge_, T mi_, F g_ = [](T a, int c) { return a; })
    : V(V_), f(f_), merge(merge_), mi(mi_), g(g_) {}

  void add_E(int a, int b)
  {
    E[a].push_back(b);
    E[b].push_back(a);
  }

  T dfs1(int p, int v)
  {
    T res = mi;
    for (int i = 0; i < (int)E[v].size(); ++i)
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
    for (int i = 0; i < (int)E[v].size(); ++i)
    {
      if (E[v][i] == p)
      {
        dp[v][i] = add;
        break;
      }
    }

    vector<T> pL((int)E[v].size() + 1), pR(E[v].size() + 1);
    pL[0] = mi;
    for (int i = 0; i < (int)E[v].size(); ++i)
      pL[i + 1] = merge(pL[i], f(dp[v][i], E[v][i]));
    pR[E[v].size()] = mi;
    for (int i = (int)E[v].size(); i > 0; --i)
      pR[i - 1] = merge(pR[i], f(dp[v][i - 1], E[v][i - 1]));

    for (int i = 0; i < (int)E[v].size(); ++i)
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
      dp[i].resize((int)E[i].size());
    dfs1(-1, root);
    dfs2(-1, root, mi);
  }

  T solve(int v)
  {
    T ans = mi;
    for (int i = 0; i < (int)E[v].size(); ++i)
    {
      ans = merge(ans, f(dp[v][i], E[v][i]));
    }
    return g(ans, v);
  }
};

int main()
{
  int n, m;
  cin >> n >> m;
  //auto f = [&](long long a, int v) {
  //  (void)v;
  //  return (a + 1) % m;
  //};
  //auto merge = [&](long long a, long long b) {
  //  return a * b % m;
  //};
  //ReRooting<long long> re(n, f, merge, 1);
  for (int i = 0; i < n - 1; ++i)
  {
    int x, y;
    cin >> x >> y;
    x--, y--;
    re.add_E(x, y);
  }
  re.calc();
  for (int i = 0; i < n; ++i)
    cout << re.solve(i) << endl;
  return 0;
}
