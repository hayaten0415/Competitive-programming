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
const char joi[3] = {'J', 'O', 'I'};

int two_pow[31];

string dfs(int s, int k, string &ans){
  if(s == 0 && k== 0){
    ans += 'J';
    return ans;
  }
  if(k < two_pow[s-1]){
    ans += string(two_pow[s - 1], joi[0]);
    ans += string(two_pow[s - 1], joi[1]);
    return ans;
  }else{
    ans += string(two_pow[s - 1], joi[2]);
    return dfs(s - 1, k - two_pow[s - 1], ans);
  }
}

int main() {
  int n, k;
  cin >> n >> k;
  two_pow[0] = 1;
  k--;
  rep(i, 30){
    two_pow[i + 1] = 2 * two_pow[i];
  }
  string tmp = "";
  string ans = dfs(n, k, tmp);
  cout << ans << endl;
}