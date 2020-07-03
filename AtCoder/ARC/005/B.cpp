#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int x, y;
  string w;
  cin >> x >> y >> w;
  x--; y--;
  string ans = "";
  vector<string> num(9);
  rep(i, 9){
    cin >> num[i];
  }
  rep(i, 4){
    ans += num[y][x];
    if(w == "R"){
      if(x + 1 >= 9)w = "L", x--;
      else x++;
    }else if(w == "L"){
      if(x - 1< 0) w = "R", x++;
      else x--;
    }else if(w == "U"){
      if(y -1 < 0)w = "D", y++;
      else y--;
    }else if(w == "D"){
      if(y + 1 >= 9) w = "U", y--;
      else y++;
    }else if(w == "RU"){
      if (x + 1 >= 9 && y -1 < 0) w = "LD", x--, y++;
      else if(x + 1 >= 9 && y - 1 >= 0) w = "LU", x--, y--;
      else if(x + 1 < 9 && y -1 < 0) w = "RD", x++, y++;
      else x++, y--;
    }else if(w == "RD"){
      if (x + 1 >= 9 && y + 1 >= 9) w = "LU", x--, y--;
      else if(x + 1 >= 9 && y + 1 < 9) w = "LD", x--, y++;
      else if(x + 1 < 9 && y + 1 >= 9) w = "RU", x++, y--;
      else x++, y++;
    }else if(w == "LD"){
      if (x - 1 < 0 && y + 1 >= 9) w = "RU", x++, y--;
      else if(x - 1 < 0 && y + 1 < 9) w = "RD", x++, y++;
      else if(x - 1 >= 0&& y + 1 >= 9 ) w = "LU", x--, y--;
      else x--, y++;
    }else if(w == "LU"){
      if(x -1 < 0 && y - 1 < 0) w = "RD", x++, y++;
      else if (x - 1 < 0 && y - 1 >= 0) w = "RU", x++, y--;
      else if (x - 1 >= 0 && y - 1 < 0) w = "LD", x--, y++;
      else x--, y--;
    }
  }
  cout << ans << endl;
}