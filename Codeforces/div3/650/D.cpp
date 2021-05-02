#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};


void solve() {
  string s;
  cin >> s;
  int n = s.size();
  int m;
  cin >> m;
  vector<int> b(m);
  rep(i, m) cin >> b[i];
  map<char, int> cnts;
  rep(i, n) cnts[s[i]]++;
  vector<vector<int>> groups;
  while(true){
    vector<int> pos;
    rep(i, m){
      if(b[i] == 0){
        pos.push_back(i);
      }
    }
    if (pos.empty())break;
    groups.push_back(pos);
    rep(i, m){
      if(b[i] == 0){
        b[i] = INT_MAX;
      }else{
        for(auto pp: pos){
          b[i] -= abs(i - pp);
        }
      }
    }
  }
  auto j = cnts.rbegin();
  string t(m, '?');
  for (auto g : groups){
    while (j->second < g.size())j++;
    for (int pp : g)t[pp] = j->first;
    j++;
  }
  cout << t << endl;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t;
  cin >> t;
  while(t--) solve();
}