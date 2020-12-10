#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int N, M, D;
  cin >> N >> M >> D;
  vector<int> A(N);
  vector<int> ans(N);
  vector<int> Q(M);
  vector<vector<int>> next(30, vector<int>(N));
  rep(i, N){
    A[i] = i;
  }
  ans = A;
  rep(i, M){
    cin >> Q[i];
    Q[i]--;
    swap(A[Q[i]], A[Q[i] + 1]);
  }
  rep(i, N){
    next[0][A[i]] = i;
  }
  for (int i = 0; i + 1 < 30; i++){
    rep(j, N){
      next[i + 1][j] = next[i][next[i][j]];
    }
  }
  rep(i,N){
    rep(j, 30){
      if(D & (1 << j)) ans[i] = next[j][ans[i]];
    }
  }
  rep(i, N){
    cout << ans[i] + 1 << endl;
  }
}