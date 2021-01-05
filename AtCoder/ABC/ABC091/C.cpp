#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n;
  cin >> n;
  mf_graph<ll> g(n * 2 + 2);
  int s = n * 2 , t = n * 2 + 1;
  vector<int> A(n), B(n), C(n), D(n);
  rep(i, n){
    cin >> A[i] >> B[i];
    g.add_edge(s, i, 1);
  }
  rep(i, n){
    cin >> C[i] >> D[i];
    g.add_edge(i + n, t, 1);
  }
  rep(i, n){
    rep(j, n){
      if(A[i] < C[j] && B[i] < D[j]){
        g.add_edge(i, n + j, 1);
      }
    }
  }
  cout << g.flow(s, t) << endl;
}