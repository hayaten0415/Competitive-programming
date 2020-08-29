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
  string s, t;
  cin >> s >> t;
  int ans = t.size();
  int n = s.size();
  int k = t.size();
  rep(i, n-k+1){
    int num = 0;
    rep(j, k){
      if(s[i+j] == t[j])num++;
    }
    ans = min(ans, k - num);
  }
  cout << ans << endl;
}