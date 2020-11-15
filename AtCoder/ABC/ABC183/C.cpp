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
  int n;
  ll k;
  cin >> n >> k;
  vector<vector<ll>> A(n, vector<ll>(n));
  vector<int> visit(n-1);
  rep(i, n)rep(j, n) cin >> A[i][j];
  rep(i, n-1) visit[i] = i+1;
  int ans = 0;
  do{
    ll num = 0;
    int pre = 0;
    rep(i, n-1){
      num += A[pre][visit[i]];
      pre = visit[i];
    }
    num += A[pre][0];
    if(num == k)ans++;
  }while(next_permutation(ALL(visit)));
  cout << ans << endl;
}