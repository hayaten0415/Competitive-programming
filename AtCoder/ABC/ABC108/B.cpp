#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  int x3 = x2 - (y2 - y1);
  int y3 = y2 + (x2 - x1);
  int x4 = x3 - (x2 - x1);
  int y4 = y3 - (y2 - y1);
  cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}