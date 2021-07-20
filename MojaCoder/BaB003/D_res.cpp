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
const ll INF = (1LL <<60);

ll dist[8][8];

int main() {
  int n, m;
  cin >> n >> m;
  ll ans = INF;
  rep(i, n)rep(j, n)dist[i][j] = INF;
  rep(i, n)dist[i][i] = 0;
  rep(i, m){
    int a, b;
    ll c;
    cin >> a >> b >> c;
    a--, b--;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  rep(i, n) rep(j, n) rep(k, n) chmin(dist[j][k], dist[j][i] + dist[i][k]);
  vector<int> A(n);
  rep(i, n) A[i] = i;
  do{
    ll tmp = 0;
    vector<int> tmp_A = A;
    tmp_A.pb(A[0]);
    rep(i, n){
      tmp += dist[tmp_A[i]][tmp_A[i + 1]];
    }
    chmin(ans, tmp);
  }while(next_permutation(ALL(A)));
  cout << ans << endl;
}