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

int string_toint(string k){
  int n = k.size();
  reverse(ALL(k));
  int ten = 1;
  int res = 0;
  rep(i, n){
    res += ten * (k[i] - '0');
    ten *= 10;
  }
  return res;
}


int main() {
  string n;
  int k;
  cin >> n >> k;
  vector<string> ans;
  ans.emplace_back(n);
  rep(i, k){
    string mx, mn;
    mx = ans[i];
    mn = ans[i];
    sort(ALL(mx), greater{});
    sort(ALL(mn));
    int ma = string_toint(mx);
    int mi = string_toint(mn);
    int res = ma - mi;
    string re = to_string(res);
    ans.emplace_back(re);
  }
  cout << ans[k] << endl;
}