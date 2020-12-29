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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if(a == c && b == d){
    cout << 0 << endl;
    return 0;
  }
  if(a + b == c + d){
    cout << 1 << endl;
    return 0;
  }
  if(a - b == c-d){
    cout << 1 << endl;
    return 0;
  }
  if(abs(a-c) + abs(b-d) <= 3){
    cout << 1 << endl;
    return 0;
  }
  if(abs(a-c) + abs(b-d) <= 6){
    cout << 2 << endl;
    return 0;
  }
  if(abs((a+b) - (c+d)) <= 3){
    cout << 2 << endl;
    return 0;
  }
  if(abs((a-b) - (c-d)) <= 3){
    cout << 2 << endl;
    return 0;
  }
  if ((a + b) % 2 == (c + d) % 2){
    cout << 2 << endl;
    return 0;
  }
  cout << 3 << endl;
}