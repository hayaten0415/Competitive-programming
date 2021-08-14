#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
const ll INF = (1LL << 60);

bool ng[10][10];
int A[10][10];

int main() {
  int n;
  cin >> n;
  rep(i, n) rep(j, n) cin >> A[i][j];
  int m;
  cin >> m;
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    ng[a][b] = true;
    ng[b][a] = true;
  }
  vector<int> B(n);
  rep(i, n) B[i] = i;
  ll ans = INF;
  do{
    bool ok = true;
    ll tmp = 0;
    rep(i, n){
      tmp += A[B[i]][i];
      if(i > 0)if(ng[B[i-1]][B[i]])ok = false;
    }
    if(ok)chmin(ans, tmp);
  } while (next_permutation(ALL(B)));
  if(ans == INF)ans = -1;
  cout << ans << endl;
}