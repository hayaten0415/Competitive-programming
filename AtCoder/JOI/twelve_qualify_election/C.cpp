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
  string res;
  cin >> res;
  int k = res.size();
  int ans = 0;
  rep(i, n){
    bool ok = false;
    string tmp;
    cin >> tmp;
    int t = tmp.size();
    if(t < k)continue;
    for (int c = 1; (k - 1) * c + 1 <= t; c++){
      if(ok)break;
      for (int d = 0; d < t; d++){
        bool ng = false;
        if(ok)break;
        if(d + (k - 1) * c >=t)break;
        rep(s, k){
          if(res[s] != tmp[d + s * c]){
            ng = true;
            break;
          }
        }
        if(!ng)ok = true;
      }
    }
    if(ok)ans++;
  }
  cout << ans << endl;
}