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
  int t;
  cin >> t;
  rep(i, t){
    int a, b, n;
    cin >> a >> b >> n;
    ll ans = 1;
    while (a % 2 == 0 || b % 2 == 0){
      if(a % 2 == 0){
        a /= 2;
        ans *= 2;
      }
      if(b % 2 == 0){
        b /= 2;
        ans *= 2;
      }
    }
    if(ans >= n){
      cout << "YES" << endl;
    }else{
      cout << "NO" << endl;
    }
  }
}