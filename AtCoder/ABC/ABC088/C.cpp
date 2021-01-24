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

int a[3][3];
int main() {
  ll sum = 0;
  
  rep(i, 3)rep(j, 3){
    cin >> a[i][j];
    sum += a[i][j];
  }
  if(sum % 3 != 0){
    cout << "No" << endl;
    return 0;
  }
  sum /= 3;
  if(sum - a[1][1] - a[2][2] != a[0][0]){
    cout << "No" << endl;
    return 0;
  }
  if(sum - a[1][2]- a[2][0] != a[0][1]){
    cout << "No" << endl;
    return 0;
  }
  if(sum - a[1][0]- a[2][1] != a[0][2]){
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
}