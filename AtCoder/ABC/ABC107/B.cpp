#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h){
    cin >> grid[i];
  }
  vector<bool> row(w,false);
  vector<bool> line(h,false);
  rep(i,h){
    int num = 1;
    int b;
    rep(j,w){
      if(grid[i][j] == '.'){
        b = 1;
      }else{
        b = 0;
      }
      num *= b;
    }
    if(num == 1){
      line[i] = true;
    }
  }
  rep(i,w){
    int num = 1;
    int b;
    rep(j,h){
      if(grid[j][i] == '.'){
        b = 1;
      }else{
        b = 0;
      }
      num *= b;
    }
    if(num == 1){
      row[i] = true;
    }
  }
  rep(i,h){
    if(line[i])continue;
    rep(j,w){
      if(row[j])continue;
      cout << grid[i][j];
    }
    cout << endl;
  }
}