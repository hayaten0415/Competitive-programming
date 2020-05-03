#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;


int main() {
  int n;
  cin >> n;
  int m[n][n];
  rep(i, n){
    rep(j,n){
      m[i][j] = 0;
    }
  }
  rep(i,n){
    int u, k;
    cin >> u >> k;
    u--;
    rep(j,k){
      int v;
      cin >> v;
      v--;
      m[u][v] = 1;
    }
  }
  rep(i,n){
    rep(j,n){
      cout << m[i][j] << (j == n - 1 ? "\n" : " ");
    }
  }
}