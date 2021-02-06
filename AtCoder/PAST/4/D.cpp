#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int x = 0, y = 0;
  vector<int> wall;
  rep(i, n){
    if(s[i] == '#')wall.emplace_back(i);
  }
  x = wall[0] - 0;
  y = n - 1 - wall[wall.size()-1];
  int k = wall.size();
  rep(i, k-1){
    int c = wall[i + 1] - x - (wall[i] + y +1);
    if(c > 0){
      int a = c / 2;
      int b = c % 2;
      x += a + b;
      y += a;
    }
  }
  cout << x << " " << y << endl;
}