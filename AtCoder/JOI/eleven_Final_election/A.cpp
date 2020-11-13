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
  int J, O;
  J = 0;
  O = 0;
  char tmp = s[0];
  int cn = 0;
  int ans = 0;
  rep(i, n){
    if(s[i] == tmp)cn++;
    else{
      if(s[i-1] == 'J' && s[i] == 'O'){
        J = cn;
      }else if (s[i - 1] == 'O' && s[i] == 'I'){
        O = cn;
      }else if(J > 0 && O > 0 && s[i-1] == 'I' && O <= cn && O <= J){
        chmax(ans, O);
        J = 0;
        O = 0;
      }else{
        J = 0;
        O = 0;
      }
      cn = 1;
      tmp = s[i];
    }
  }
  if(J > 0 && O > 0 && O <= cn && O <= J && s[n-1] == 'I')chmax(ans, O);
  cout << ans << endl;
}