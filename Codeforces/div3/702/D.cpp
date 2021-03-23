#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
using Graph = vector<vector<int>>;
int A[101];
int dist[101];

void dfs(int l, int r, int d){
  if(l == r)return;
  int maxind = l;
  for (int i = l; i < r; i++){
    if(A[i] > A[maxind])maxind = i;
  }
  dist[maxind] = d;
  dfs(l, maxind, d + 1);
  dfs(maxind + 1,r,  d + 1);
}

void solve(){
  int n;
  cin >> n;
  rep(i, n){
    cin >> A[i];
    A[i]--;
  }
  dfs(0, n, 0);
  rep(i, n){
    cout << dist[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  int t;
  cin >> t;
  while(t--) solve();
}