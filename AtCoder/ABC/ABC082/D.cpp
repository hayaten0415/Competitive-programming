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

bool dp1[8001][16001][4];
bool dp2[8001][16001][4];
int main() {
  string s;
  cin >> s;
  int x, y;
  cin >> x >> y;
  int n = s.size();
  dp1[0][8000][0] = true;
  dp2[0][8000][0] = true;
  rep(i, n){
    for(int j = 8000 - n; j <= 8000 + n; j++){
      if(s[i] == 'F'){
        rep(k, 4){
          if(dp1[i][j][k]){
            if(k % 2 == 0){
              if(k == 0 && j + 1 <= 8000 + n)dp1[i+1][j+1][k] = true;
              if(k == 2 && j-1 >= 0)dp1[i+1][j-1][k] = true;
            }else{
              dp1[i + 1][j][k] = true;
            }
          }
          if(dp2[i][j][k]){
            if(k % 2 == 1){
              if(k == 1 && j + 1 <= 8000 + n)dp2[i+1][j+1][k] = true;
              if(k == 3 && j-1 >= 0)dp2[i+1][j-1][k] = true;
            }else{
              dp2[i + 1][j][k] = true;
            }
          }
        }
      }else{
        rep(k, 4){
          if(dp1[i][j][k]){
            if(k % 2 == 0){
              dp1[i + 1][j][1] = true;
              dp1[i + 1][j][3] = true;
            }else{
              dp1[i + 1][j][0] = true;
              dp1[i + 1][j][2] = true;
            }
          }
          if(dp2[i][j][k]){
            if(k % 2 == 0){
              dp2[i + 1][j][1] = true;
              dp2[i + 1][j][3] = true;
            }else{
              dp2[i + 1][j][0] = true;
              dp2[i + 1][j][2] = true;
            }
          }
        }
      }
    }
  }
  bool ok = false;
  rep(j, 4){
    rep(k, 4){
      if(dp1[n][8000+ x][j] & dp2[n][8000+ y][k])ok = true;
    }
  }
  if(ok){
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}