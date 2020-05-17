#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int x1, y1, r;
  int x2, y2, x3, y3;
  cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;
  bool x2y2 = false;
  bool x2y3 = false;
  bool x3y2 = false;
  bool x3y3 = false;
  //長方形の4点が円の中に含まれているかの判定
  //円の中心から各4点の距離が全て円の半径以下だった場合長方形は円の中に完全に含まれる。
  if(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1),2 ) <= pow(r,2)) x2y2 = true;
  if(pow(abs(x2 - x1), 2) + pow(abs(y3 - y1),2 ) <= pow(r,2)) x2y3 = true;
  if(pow(abs(x3 - x1), 2) + pow(abs(y2 - y1),2 ) <= pow(r,2)) x3y2 = true;
  if(pow(abs(x3 - x1), 2) + pow(abs(y3 - y1),2 ) <= pow(r,2)) x3y3 = true;
  if(x2y2 && x2y3 && x3y2 && x3y3){
    cout << "YES" << endl;
    cout << "NO" << endl;
    return 0;
  };
  //円が長方形の中に完全に含まれているかの判定
  rep(i, 4){
    int ny = y1 + r * dy[i], nx = x1 + r * dx[i];
    //はみ出しているのでどちらも存在
    if(x2 > nx || x3 < nx || y2 > ny || y3 < ny){
      cout << "YES" << endl;
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  cout << "YES" << endl;
}