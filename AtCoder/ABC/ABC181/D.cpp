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
    if(s != "8"){
      cout << "No" << endl;
      return 0;
    }else{
      cout << "Yes" << endl;
      return 0;
    }
  }
  if(n == 2){
    int num1 = s[1] - '0';
    int num2 = s[0] - '0';
    int tmp1 = 10 * num1 + num2;
    int tmp2 = 10 * num2 + num1;
    if(tmp1 % 8 == 0 || tmp2 % 8 == 0){
      cout << "Yes" << endl;
      return 0;
    }else{
      cout << "No" << endl;
      return 0;
    }
  }
  vector<int> eight;
  for (int k = 104; k < 1000; k += 8){
    eight.emplace_back(k);
  }
  int c = eight.size();
  rep(i, c){
    int cn1 = 0, cn2 = 0, cn3 = 0;
    string t = to_string(eight[i]);
    char one = t[0];
    char two = t[1];
    char three = t[2];
    rep(j, n){
      if(s[j] == one)cn1++;
      if(s[j] == two)cn2++;
      if(s[j] == three)cn3++;
    }
    if(cn1 > 0 && cn2 > 0 && cn3 > 0 && one != two && two != three && three != one){
      cout << "Yes" << endl;
      return 0;
    }
    if(cn1 > 1 && cn2 > 1 && cn3 > 0 && one == two && two != three && three != one){
      cout << "Yes" << endl;
      return 0;
    }
    if(cn1 > 0 && cn2 > 1 && cn3 > 1 && one != two && two == three && three != one){
      cout << "Yes" << endl;
      return 0;
    }
    if(cn1 > 1 && cn2 > 0 && cn3 > 1 && one != two && two != three && three == one){
      cout << "Yes" << endl;
      return 0;
    }
    if(cn1 > 2 && cn2 > 2 && cn3 > 2 && one == two && two == three && three == one){
      cout << "Yes" << endl;
      return 0;
    }
  }
  cout << "No" << endl;
}