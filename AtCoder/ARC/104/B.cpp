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
  string s;
  cin >> n >> s;
  ll ans = 0;
  rep(i, n){
    int a = 0;
    int t = 0;
    int c = 0;
    int g = 0;
    for (int j = i; j < n; j++){
      if(s[j] == 'A')a++;
      if(s[j] == 'T')t++;
      if(s[j] == 'C')c++;
      if(s[j] == 'G')g++;
      if(a == t && c == g){
        ans++;
      }
    }
  }
  cout << ans << endl;
}