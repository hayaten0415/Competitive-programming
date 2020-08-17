#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> taro_hand(2 * n + 1, 0);
  vector<int> hanako_hand(2 * n + 1, 0);
  int taro_hand_count = n;
  int hanako_hand_count = n;
  rep(i, n) {
    int num;
    cin >> num;
    taro_hand[num] = 1;
  }
  for (int i = 1; i < 2 * n + 1; i++){
    if(taro_hand[i] == 0){
      hanako_hand[i] = 1;
    }
  }
  int mx = 0;
  bool taro_turn = true;
  while(taro_hand_count > 0 && hanako_hand_count > 0){
    if(taro_turn){
      int tmp = taro_hand_count;
      for (int i = 1; i < 2 * n + 1; i++){
        if(taro_hand[i] == 1 && i > mx){
          taro_hand_count--;
          mx = i;
          taro_hand[i] = 0;
          break;
        }
      }
      if(tmp == taro_hand_count)mx = 0;
    }else{
      int tmp = hanako_hand_count;
      for (int i = 1; i < 2 * n + 1; i++){
        if(hanako_hand[i] == 1 && i > mx){
          hanako_hand_count--;
          mx = i;
          hanako_hand[i] = 0;
          break;
        }
      }
      if(tmp == hanako_hand_count)mx = 0;
    }
    taro_turn = taro_turn ^ 1;
  }
  cout << hanako_hand_count << endl;
  cout << taro_hand_count << endl;
}