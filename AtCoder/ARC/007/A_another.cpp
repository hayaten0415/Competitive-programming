#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int h, w;
  cin >> h >> w;
  vector<string> grid(h);
  rep(i, h) cin >> grid[i];
  int cnt = 0;
  rep(i,h){
    rep(j,w){
      if(grid[i][j] == '#'){
        cnt++;
      }
    }
  }
  cout << (cnt == h + w - 1? "Possible" : "Impossible") << endl;
}