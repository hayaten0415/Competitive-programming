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
  string s;
  cin >> s;
  int n = s.size();
  if(n == 1){
    cout << 0 << endl;
    return 0;
  }
  ll ans = 0;
  bool even = (n % 2 == 0);
  bool palindrome;
  int differ = 0;
  rep(i, (n+ 1) / 2){
    if(s[i] != s[n-1-i]){
      differ++;
    }
  }
  palindrome = (differ == 0);
  rep(i, (n + 1) /2){
    int left = i;
    int right = n - 1 - i;
    if(i == n / 2){
      if(!even){
        if(palindrome){
          continue;
        }else{
          ans += 25;
        }
      }else{
        if(s[left] != s[right]){
          if(differ > 1){
            ans += 25 * 2;
          }else{
            ans += 24 * 2;
          }
        }else{
          ans += 25 * 2;
        }
      }
    }else{
      if(s[left] != s[right]){
        if(differ > 1){
          ans += 25 * 2;
        }else{
          ans += 24 * 2;
        }
      }else{
        ans += 25 * 2;
      }
    }
  }
  cout << ans << endl;
}