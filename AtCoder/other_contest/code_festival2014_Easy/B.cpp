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
  if(n <=20){
    cout << n << endl;
  }else if(n <= 40){
    n -= 20;
    cout << 20 -n +1 << endl;
  }else if(n <= 60){
    cout << (n - 40) << endl;
  }else if(n <= 80){
    n -= 60;
    cout << 20 - n + 1 << endl;
  }else if(n <= 100){
    cout << (n - 80) << endl;
  }else if(n <= 120){
    n -= 100;
    cout << 20 - n + 1 << endl;
  }else if(n <= 140){
    cout << (n - 120) << endl;
  }else if(n <= 160){
    n -= 140;
    cout << 20 - n + 1 << endl;
  }else if(n <= 180){
    cout << (n - 160) << endl;
  }else {
    n -= 180;
    cout << 20 - n + 1 << endl;
  }
}