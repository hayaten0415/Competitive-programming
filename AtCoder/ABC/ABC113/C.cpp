#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  vector<pair<int, pair<int, int>>> a(m);
  vector<int> cnt(n + 1, 0);
  rep(i,m){
    cin >> a[i].second.first >> a[i].first;
    a[i].second.second = i;
  }
  sort(a.begin(), a.end());
  vector<pair<int, string>> ans(m);
  rep(i,m){
    cnt[a[i].second.first]++;
    stringstream ss;
    //0埋め
    ss << setw(6) << setfill('0') << a[i].second.first;
    ss << setw(6) << cnt[a[i].second.first];
    ans[i].first = a[i].second.second;
    ans[i].second = ss.str();
  }
  sort(ans.begin(), ans.end());
  rep(i, m) cout << ans[i].second << endl;
}