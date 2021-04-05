#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using namespace atcoder;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

int main() {
  string s;
  cin >> s;
  int n = s.size();
  if(s == "a" || s == "zzzzzzzzzzzzzzzzzzzz"){
    cout << "NO"<< endl;
    return 0;
  }
  if(s == string(s.size(), s[0])){
    int ans = 0;
    rep(i, n){
      ans += (s[i] - 'a') + 1;
    }
    for (int i = 1; i <= 26; i++){
      int d = ans / i;
      int k = ans % i;
      if(d > 20)continue;
      if(k > 0 && d >= 20)continue;
      string res = "";
      res += string(d, 'a' + (i - 1));
      if(k > 0)res += string(1, ('a' + k-1));
      if(res != s){
        cout << res << endl;
        return 0;
      }
    }
  }else{
    rep(i, n-1){
      if(s[i] != s[i+1]){
        swap(s[i], s[i + 1]);
        break;
      }
    }
    cout << s << endl;
  }
}