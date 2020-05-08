#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int a, b, c, d, e, f;
  cin >> a >> b >> c >> d >> e >> f;
  double per = (double)((double)e / (double)(100 + e));
  double mx = 0.0000000000;
  int ans_all = 0, ans_satou = 0;
  set<int> water;
  set<int> satou;
  for (int i = 0; i <= 30; i++){
    for (int j = 0; j <= 15; j++){
      if(i == 0 && j == 0) continue;
      if(100 * a * i + 100 * b * j > f) continue;
      water.insert(100 * a * i + 100 * b * j);
    }
  }
  for (int i = 0; c * i <= f; i++){
    for (int j = 0; d * j <= f; j++){
      if (c * i + d * j > f) continue;
      satou.insert(c * i + d * j);
    }
  }
  for(auto i : water){
    for(auto j :satou){
      if(i + j <= f){
        if((double)((double)j / (double)(i + j)) <= per){
          if (mx <= (double)((double)j / (double)(i + j))){
            ans_satou = j;
            ans_all = i + j;
            mx = (double)((double)j / (double)(i + j));
          }
        }
      }
    }
  }
  cout << ans_all << " " << ans_satou << endl;
}