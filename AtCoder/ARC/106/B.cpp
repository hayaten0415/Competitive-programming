#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};




int main() {
  int n, m;
  cin >> n >> m;
  ll sum_a = 0, sum_b = 0;
  dsu d(n);
  vector<int> A(n);
  vector<int> B(n);
  vector<P> edge(m);
  rep(i, n){
    cin >> A[i];
    sum_a += A[i];
  }
  vector<bool> cond(n, false);
  rep(i, n){
    cin >> B[i];
    sum_b += B[i];
  }
  set<int> st;
  int num = 0;
  rep(i, n){
    if(A[i] != B[i]){
      st.insert(i);
      num = i;
    }
  }
  rep(i,m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    edge[i] = {a, b};
    d.merge(a, b);
  }
  if(sum_a != sum_b){
    cout << "No" << endl;
    return 0;
  }
  Graph G = d.groups();
  int k = G.size();
  rep(i, k){
    ll tmp_a = 0;
    ll tmp_b = 0;
    for(auto s: G[i]){
      tmp_a += A[s];
      tmp_b += B[s];
    }
    if(tmp_a != tmp_b){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}