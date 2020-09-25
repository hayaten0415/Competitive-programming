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
const int INF = (1 << 30);
using Graph = vector<vector<int>>;

bool diff(string s, string t, int k){
  int dif = 0;
  rep(i, k){
    if(s[i] != t[i])dif++;
  }
  return dif == 1;
}

int main() {
  string first, last;
  cin >> first >> last;
  int n;
  cin >> n;
  n += 2;
  Graph G(n);
  vector<string> str(n);
  int k = first.size();
  str[0] = first;
  str[n - 1] = last;
  vector<int> dist(n, INF);
  vector<int> prev(n, -1);
  for (int i = 1; i < n - 1; i++){
    cin >> str[i];
  }
  if(first == last){
    cout << 0 << endl;
    cout << first << endl;
    cout << last << endl;
    return 0;
  }
  rep(i, n){
    rep(j, n){
      if(i == j)continue;
      if(diff(str[i], str[j], k))G[i].push_back(j);
    }
  }
  vector<string> ans;
  queue<int> que;
  dist[0] = 0;
  que.push(0);
  while (!que.empty()){
    int c = que.front();
    que.pop();
    for(auto g : G[c]){
      if(dist[g] != INF)continue;
      dist[g] = dist[c] + 1;
      prev[g] = c;
      que.push(g);
    }
  }
  if(dist[n-1] == INF){
    cout << -1 << endl;
    return 0;
  }
  int now = n - 1;
  while(now != -1){
    ans.push_back(str[now]);
    now = prev[now];
  }
  reverse(ALL(ans));
  cout << ans.size() - 2 << endl;
  rep(i, ans.size()){
    cout << ans[i] << endl;
  }
}
