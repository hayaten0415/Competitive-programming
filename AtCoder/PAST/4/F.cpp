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
  int n, k;
  cin >> n >> k;
  vector<int> cn(n+1);
  map<string, int> mp;
  rep(i, n){
    string s;
    cin >> s;
    mp[s]++;
  }
  for(auto v : mp){
    cn[v.second]++;
  }
  int num = 0;
  int ans = 0;
  rrep(i, n+1){
    num += cn[i];
    if(num >= k){
      if(cn[i] > 1){
        cout << "AMBIGUOUS" << endl;
        return 0;
      }
      ans = i;
      break;
    }
  }
  for(auto v : mp){
    if(v.second == ans){
      cout << v.first << endl;
      return 0;
    }
  }
}