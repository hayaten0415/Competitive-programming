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
  vector<int> rest(3, 0);
  ll sum = 0;
  if(n == 1){
    if(s == "3" || s == "6" || s== "9"){
      cout << 0 << endl;
      return 0;
    }else{
      cout << -1 << endl;
      return 0;
    }
  }
  rep(i, n){
    int k = s[i] - '0';
    rest[k % 3]++;
    sum += k;
  }
  if(sum % 3== 0){
    cout << 0 << endl;
    return 0;
  }
  if(rest[sum % 3] > 0){
    cout << 1 << endl;
    return 0;
  }else{
    if(sum % 3 == 1){
      if (rest[2] > 1 && n > 2){
        cout << 2 << endl;
        return 0;
      }else{
        cout << -1 << endl;
        return 0;
      }
    }else if(sum % 3 == 2){
      if (rest[1] > 1 && n > 2){
        cout << 2 << endl;
        return 0;
      }else{
        cout << -1 << endl;
        return 0;
      }
    }
  }
}