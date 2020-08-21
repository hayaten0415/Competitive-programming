#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
int n;
string ans;

void dfs(int k) {
  if(k == n)return;
  int sz = ans.size();
  string tmp = "";
  int num = 1;
  rep(i, sz) {
    if(i + 1 < sz && ans[i] == ans[i+1])num++;
    else{
      ostringstream oss;
      oss << num;
      tmp += oss.str();
      tmp += ans[i];
      num = 1;
    }
  }
  ans = tmp;
  dfs(k + 1);
}

int main(){
  cin >> n >> ans;
  dfs(0);
  cout << ans << endl;
}