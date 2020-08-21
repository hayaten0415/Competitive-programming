#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
vector<int> ans;

void dfs(int n, int k) {
  if(n == 0){
    rep(i, ans.size()) cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
  }
  for (int i = k; i > 0; i--){
    ans.emplace_back(i);
    dfs(n - i, min(i, n - i));
    ans.pop_back();
  }
}

int main() {
  int n;
  cin >> n;
  dfs(n, n);
}