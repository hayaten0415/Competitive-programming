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
  cin >> n;
  vector<string> res(n), tmp(n);
  rep(i, n) cin >> tmp[i];
  rep(i, n) cin >> res[i];
  int num1, num2, num3, num4;
  num1 = num2 = num3 = num4 = 0;
  int ans = (1 << 30);
  //0
  rep(i, n){
    rep(j, n){
      if(tmp[i][j] != res[i][j])num1++;
    }
  }
  ans = min(ans, num1);
  //90
  rep(i, n){
    rep(j, n){
      if(tmp[n- 1 -j][i] != res[i][j])num2++;
    }
  }
  ans = min(ans, num2 + 1);
  //180
  rep(i, n){
    rep(j, n){
      if(tmp[n- 1 -i][n-1-j] != res[i][j])num3++;
    }
  }
  ans = min(ans, num3 + 2);
  //270
  rep(i, n){
    rep(j, n){
      if(tmp[j][n-1-i] != res[i][j])num4++;
    }
  }
  ans = min(ans, num4 + 1);
  cout << ans << endl;
}