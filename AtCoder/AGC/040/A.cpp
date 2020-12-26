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
  int n = s.size() + 1;
  vector<ll> ans(n);
  rep(i, n-1){
    if(s[i]=='<'){
      chmax(ans[i+1], ans[i]+ 1);
    }
  }
  rrep(i, n-1){
    if(s[i]=='>'){
      chmax(ans[i], ans[i+1]+ 1);
    }
  }
  cout << accumulate(ALL(ans), ll(0)) << endl;
}