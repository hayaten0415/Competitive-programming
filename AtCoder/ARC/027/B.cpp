#include <bits/stdc++.h>
#include <atcoder/dsu>
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
  string s1, s2;
  cin >> s1 >> s2;
  vector<bool> ok(37, false);
  ok[36] = true;
  dsu d(37);
  vector<int> A(n), B(n);
  rep(i, n){
    if(isdigit(s1[i])){
      A[i] = s1[i] - '0';
    }else{
      A[i] = s1[i] - 'A' + 10;
    }
    ok[A[i]] = true;
  }
  rep(i, n){
    if(isdigit(s2[i])){
      B[i] = s2[i] - '0';
    }else{
      B[i] = s2[i] - 'A' + 10;
    }
    ok[B[i]] = true;
  }
  rep(i, n){
    d.merge(A[i], B[i]);
    if(i == 0)d.merge(A[i], 36);
  }
  ll ans = 1;
  vector<vector<int>> G = d.groups();
  int k = G.size();
  rep(i, k){
    if(!ok[G[i][0]])continue;
    if(G[i][0] <= 9)continue;
    if(d.same(G[i][0], 36)){
      ans *= 9;
    }else{
      ans *= 10;
    }
  }
  cout << ans << endl;
}