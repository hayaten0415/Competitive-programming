#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
int a[1020][120];

int main() {
  int n, m;
  cin >> n >> m;
  vector<P> ans(m);
  rep(i, m) {
    ans[i].first = i + 1;
    ans[i].second = 0;
  }
  rep(i, n) {
    rep(j, m) {
      int num;
      cin >> num;
      if(num == 1)ans[j].second++;
    }
  }
  sort(ans.begin(), ans.end(), [](P a, P b) {
    if(a.second == b.second){
      return a.first < b.first;
    }
    return a.second > b.second;
  });
  rep(i, m) {
    cout << ans[i].first << (i == m - 1 ? "\n" : " ");
  }
}