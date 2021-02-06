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
long double eps = 0.005L;

int main() {
  int x, y;
  cin >> x >> y;
  if(y == 0){
    cout << "ERROR" << endl;
    return 0;
  }
  if(x == 0){
    cout << "0.00" << endl;
    return 0;
  }
  x *= 100;
  int ans = x / y;
  string res = to_string(ans);
  if(res.size() == 2){
    res = "0." + res;
  }else if(res.size() == 1){
    res = "0.0" + res;
  }else{
    res.insert(res.size() -2 , ".");
  }
  cout << res << endl;
}