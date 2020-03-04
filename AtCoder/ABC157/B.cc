#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

const int MOD = 1000000007;
const int MAX =200000;


int main() {
  int bingo[3][3];
  bool marked[3][3];
  int n;
  bool cond = false;
  int num;
  rep(i, 3) {
    rep(j, 3){
      cin >> bingo[i][j];
      marked[i][j] = false;
    }
  }
  cin >> n;
  rep(i, n) {
    cin >> num;
    rep(j, 3) {
      rep(k, 3) {
        if(num == bingo[j][k]) marked[j][k] = true;
      }
    }
  }
  rep(i, 3) {
    if(marked[i][0] && marked[i][1] && marked[i][2]) cond = true;
    if(marked[0][i] && marked[1][i] && marked[2][i]) cond = true;
  }
  if(marked[0][0] && marked[1][1] && marked[2][2]) cond = true;
  if(marked[0][2] && marked[1][1] && marked[2][0]) cond = true;
  cout << (cond? "Yes" : "No") << endl;
}
