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
  string s;
  int n;
  cin >> s >> n;
  int k = s.size();
  int ans = 0;
  rep(i, n){
    string tmp;
    cin >> tmp;
    int g = tmp.size();
    rep(i, g){
      bool seen = true;
      for (int j = 0; j < k; j++){
        int t = j + i;
        t %= g;
        if(s[j] != tmp[t]){
          seen = false;
          break;
        }
      }
      if(seen){
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;
}