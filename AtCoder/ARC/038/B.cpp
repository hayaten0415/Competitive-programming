#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[3] = {1, 0, 1};
const int dy[3] = {0, 1, 1};
const int INF = (1 << 30);
int h, w;

int memo[105][105];

int rec(int i, int j, const vector<string> &grid){
  int now = 0;
  if(memo[i][j] != -1)return memo[i][j];
  rep(k,3){
    int ny=i+dy[k],nx=j+dx[k];
    if(ny>=h||nx>=w||grid[ny][nx]=='#'){continue;}
    if(!rec(ny,nx, grid)){now=1;}
  }
  return memo[i][j] =now;
}

int main() {
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  rep(i, h)rep(j, w)memo[i][j] = -1;
  if(rec(0, 0,grid)){
    cout << "First" << endl;
  }else{
    cout << "Second" << endl;
  }
}