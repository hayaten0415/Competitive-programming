#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  string s;
  cin >> s;
  int n = s.size();
  string nonx = "";
  rep(i, n){
    if(s[i] != 'x')nonx += s[i];
  }
  string reverse_nonx = nonx;
  reverse(ALL(reverse_nonx));
  if(reverse_nonx != nonx){
    cout << -1 << endl;
    return 0;
  }
  int left = 0;
  int right = n - 1;
  int ans = 0;
  while (left <= right){
    if(s[left] == s[right]){
      left++;
      right--;
      continue;
    }else{
      if(s[left] == 'x')left++;
      else if(s[right] == 'x')right--;
      ans++;
    }
  }
  cout << ans << endl;
}