#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  vector<string> A(n);
  rep(i,n){
    cin >> A[i];
  }
  rep(i,n){
    rep(j,m){
      int num = A[i][j] - '0';
      a[i][j] = num;
    }
  }
  vector<vector<int>> b(n, vector<int>(m,0));
  //左上から順番に確定していく。
  rep(i,n){
    rep(j,m){
      if(a[i][j] == 0) continue;
      if(i == n-1) continue;
      if(j == m-1) continue;
      b[i + 1][j] = a[i][j];
      rep(k,4){
        a[i + 1 + dy[k]][j + dx[k]] -= a[i][j];
      }
    }
  }
  //出力
  rep(i,n){
    rep(j,m){
      cout << b[i][j];
    }
    cout << endl;
  }
}