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


int string_to_int(string s){
  int num = 0;
  int ten = 1;
  reverse(ALL(s));
  rep(i, s.size()){
    num += ten * (s[i] - '0');
    ten *= 10;
  }
  return num;
}

int main() {
  string a, b;
  cin >> a >> b;
  int ans = -999;
  int B = string_to_int(b);
  int A = string_to_int(a);
  rep(i, 3){
    if(i == 0){
      for (int k = 1; k < 10; k++){
        string tmpa = a;
        tmpa[i] = ('0' + k);
        int tmpA = string_to_int(tmpa);
        chmax(ans, tmpA - B);
      }
    }else{
      rep(k, 10){
        string tmpa = a;
        tmpa[i] = ('0' + k);
        int tmpA = string_to_int(tmpa);
        chmax(ans, tmpA - B);
      }
    }
  }
  rep(i, 3){
    if(i == 0){
      for (int k = 1; k < 10; k++){
        string tmpb = b;
        tmpb[i] = ('0' + k);
        int tmpB = string_to_int(tmpb);
        chmax(ans, A - tmpB);
      }
    }else{
      rep(k, 10){
        string tmpb = b;
        tmpb[i] = ('0' + k);
        int tmpB = string_to_int(tmpb);
        chmax(ans, A - tmpB);
      }
    }
  }
  cout << ans << endl;
}
