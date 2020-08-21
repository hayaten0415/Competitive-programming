#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int dice[6] = {1, 2, 3, 4, 5, 6};

void East() {
  int tmp1 = dice[0];
  int tmp2 = dice[2];
  int tmp3 = dice[3];
  int tmp4 = dice[5];
  dice[2] = tmp1;
  dice[5] = tmp2;
  dice[0] = tmp3;
  dice[3] = tmp4;
}

void West() {
  int tmp1 = dice[0];
  int tmp2 = dice[2];
  int tmp3 = dice[3];
  int tmp4 = dice[5];
  dice[3] = tmp1;
  dice[0] = tmp2;
  dice[5] = tmp3;
  dice[2] = tmp4;
}

void North() {
  int tmp1 = dice[0];
  int tmp2 = dice[1];
  int tmp3 = dice[4];
  int tmp4 = dice[5];
  dice[4] = tmp1;
  dice[0] = tmp2;
  dice[5] = tmp3;
  dice[1] = tmp4;
}

void South() {
  int tmp1 = dice[0];
  int tmp2 = dice[1];
  int tmp3 = dice[4];
  int tmp4 = dice[5];
  dice[1] = tmp1;
  dice[5] = tmp2;
  dice[0] = tmp3;
  dice[4] = tmp4;
}

void Left() {
  int tmp1 = dice[1];
  int tmp2 = dice[2];
  int tmp3 = dice[3];
  int tmp4 = dice[4];
  dice[2] = tmp1;
  dice[4] = tmp2;
  dice[1] = tmp3;
  dice[3] = tmp4;
}

void Right() {
  int tmp1 = dice[1];
  int tmp2 = dice[2];
  int tmp3 = dice[3];
  int tmp4 = dice[4];
  dice[3] = tmp1;
  dice[1] = tmp2;
  dice[4] = tmp3;
  dice[2] = tmp4;
}

int main() {
  int n;
  cin >> n;
  int ans = 1;
  rep(i, n) {
    string s;
    cin >> s;
    if(s[0] == 'E')East();
    if(s[0] == 'W')West();
    if(s[0] == 'N')North();
    if(s[0] == 'S')South();
    if(s[0] == 'L')Left();
    if(s[0] == 'R')Right();
    ans += dice[0];
  }
  cout << ans << endl;
}
