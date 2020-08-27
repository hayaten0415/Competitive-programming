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
  int n, a, b;
  string s;
  cin >> n >> a >> b >> s;
  a--, b--;
  rep(i, n){
    if(i < a || i > b){
      cout << s[i];
    }else if(i >=a && i <= b ){
      cout << s[b - (i -a)];
    }
  }
  cout << "\n"; 
}