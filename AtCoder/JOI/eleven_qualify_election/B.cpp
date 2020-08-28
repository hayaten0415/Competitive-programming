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
  vector<int> win_point(n);
  vector<int> ans(3 * (n-1) + 1);
  map<int, int, greater<int>> mp;
  rep(i, n * (n -1) / 2){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    a--, b--;
    if(c > d){
      win_point[a] += 3;
    }else if(c < d){
      win_point[b] += 3;
    }else{
      win_point[a]++;
      win_point[b]++;
    }
  }
  int rank = 1;
  rep(i, n){
    mp[win_point[i]]++;
  }
  for(auto x : mp){
    ans[x.first] = rank;
    rank += x.second;
  }
  rep(i, n){
    cout << ans[win_point[i]] << endl;
  }
}