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
  int n, r;
  cin >> n >> r;
  string s;
  cin >> s;
  vector<int> sum(n);
  int max_right = 0;
  rrep(i, n){
    if(s[i] == '.'){
      max_right = max(i - r + 1, 0);
      break;
    }
  }
  int ans = max_right;
  rep(i, n){
    if(s[i] == '.'){
      ans++;
      i += r - 1;
    }
  }
  cout << ans << endl;
}