#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int h, w, n;
  cin >> h >> w >> n;
  vector<int> b(n);
  vector<vector<int>> ans(h, vector<int>(w));
  rep(i, n) cin >> b[i];
  vector<int> a;
  rep(i,n){
    rep(j, b[i]){
      a.push_back(i+1);
    }
  }
  //右向きに埋めていくか左向きに埋めていくかのflag
  int flag = 1;
  for (int i = 0; i < h; i++){
    if(flag){
      for (int j = 0; j < w; j++){
        ans[i][j] = a[w * i + j];
      }
      flag = 0;
    }else {
      for (int j = 0; j < w; j++){
        ans[i][w - 1 - j] = a[w * i + j];
      }
      flag = 1;
    }
  }
  rep(i,h){
    rep(j,w){
      cout << ans[i][j] << (j == w - 1 ? "\n" : " ");
    }
  }
}