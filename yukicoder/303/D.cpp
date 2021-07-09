#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define popcount(bit) __builtin_popcount(bit)
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<bool>> dist(n, vector<bool>(n, false));
  vector<vector<bool>> black(n, vector<bool>(n, false));
  dist[0][0] = true;
  queue<P> que;
  que.push(P(0, 0));
  auto cond = [&](int a, int b){
    cout << a << " " << b << endl;
    cout.flush();
    string s;
    cin >> s;
    return s == "Black";
  };
  while (!que.empty()){
    P p = que.front();
    que.pop();
    rep(i, 4){
      int nx = p.first + dx[i], ny = p.second + dy[i];
      if(nx < 0 || ny < 0 || nx >= n || ny >= n)continue;
      if(dist[nx][ny])continue;
      if(cond(nx + 1, ny + 1)){
        black[nx][ny] = true;
        que.push(P(nx, ny));
      }
      dist[nx][ny] = true;
    }
  }
  if(black[n-1][n-1]){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}