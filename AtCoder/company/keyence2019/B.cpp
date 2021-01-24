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
  cin >> s;
  string ans = "keyence";
  if(s == ans){
    cout << "YES" << endl;
    return 0;
  }
  int n = s.size();
  rep(i, n){
    for (int j = i; j < n; j++){
      string S = "";
      rep(k, n){
        if(i <= k && k <= j)continue;
        else S.push_back(s[k]);
      }
      if(S == ans){
        cout << "YES" << endl;
        return 0;
      }
    }
  }
  cout << "NO" << endl;
}
