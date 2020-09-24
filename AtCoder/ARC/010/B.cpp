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
const int days_cn[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};

int main() {
  int n;
  cin >> n;
  vector<bool> days(366, false);
  int ans = 2;
  int cn = 0;
  int another = 0;
  rep(i, n){
    string s;
    cin >> s;
    int num = 1;
    bool a_ok = true;
    int a = 0, b = 0;
    rep(i, s.size()){
      if(s[i] == '/'){
        num = 1;
        a_ok = false;
        continue;
      }
      int tmp = s[i] - '0';
      if(a_ok){
        a *= num;
        a += tmp;
      }else{
        b *= num;
        b += tmp;
      }
      num *= 10;
    }
    int day = days_cn[a - 1] + b-1;
    days[day] = true;
  }
  for (int i = 0; i < 366; i++){
    if(days[i]){
      cn++;
      if(i % 7 == 0 || i % 7 == 6){
        another++;
      }
    }else if(i % 7 == 0 || i % 7 == 6){
      cn++;
    }else{
      if(another > 0){
        another--;
        cn++;
      }else{
        ans = max(ans, cn);
        cn = 0;
      }
    }
  }
  ans = max(ans, cn);
  cout << ans << endl;
}