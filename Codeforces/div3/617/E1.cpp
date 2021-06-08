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


int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> color(n, -1);
  vector<int> index(n);
  rep(i, n) index[i] = i;
  color[n - 1] = 0;
  bool ok = true;
  rep(i, n - 1) for (int j = n - 1; j > i; j--){
    if(s[j-1] > s[j]){
      if(color[index[j-1]] != -1 && color[index[j - 1]] == color[index[j]]){
        ok = false;
      }
      if(color[index[j-1]] == -1){
        color[index[j - 1]] = color[index[j]] ^ 1;
      }
      swap(s[j - 1], s[j]);
      swap(index[j-1], index[j]);
    }else{
      if(color[index[j-1]] == -1){
        color[index[j - 1]] = color[index[j]];
      }
    }
  }
  if(ok){
    cout << "YES" << endl;
    rep(i, n)cout << color[i];
    cout << endl;
  }else{
    cout << "NO" << endl;
  }
}