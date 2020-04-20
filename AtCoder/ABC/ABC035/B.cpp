#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
  string s;
  int t;
  int x = 0, y = 0;
  int question = 0;
  cin >> s >> t;
  rep(i, s.size()){
    if(s[i] == 'L'){
      x += dx[2];
      y += dy[2];
    }else if(s[i] == 'R'){
      x += dx[0];
      y += dy[0];
    }else if(s[i] == 'U'){
      x += dx[1];
      y += dy[1];
    }else if(s[i] == 'D'){
      x += dx[3];
      y += dy[3];
    }else {
      question++;
    }
  }
  rep(i, question){
    if(t == 1){
      cout << abs(x) + abs(y) + question << endl;
      return 0;
    }else {
      if(x>0) x--;
      else if(x < 0) x++;
      else if(y > 0) y--;
      else if(y < 0) y++;
      else x++;
    }
  }
  cout << abs(x) + abs(y) << endl;
}