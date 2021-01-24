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
  int n = s.size();
  reverse(ALL(s));
  int sum = 0;
  int ten = 1;
  bool minus = false;
  bool point = false;
  rep(i, n){
    if(s[i] == '.'){
      point = true;
      continue;
    }
    if(s[i] == '-'){
      minus = true;
      continue;
    }
    sum += (s[i] - '0') * ten;
    ten *= 10;
  }
  if(minus)sum *= -1;
  if(!point) sum *= 10;
  return sum;
}

int main() {
  int n;
  cin >> n;
  vector<int> low(n), high(n);
  vector<int> ans(6);
  rep(i, n){
    string a, b;
    cin >> a >> b;
    low[i] = string_to_int(b);
    high[i] = string_to_int(a);
  }
  rep(i, n){
    if(high[i] >= 350)ans[0]++;
    if(high[i] >= 300 && high[i] < 350)ans[1]++;
    if(high[i] >= 250 && high[i] < 300)ans[2]++;
    if(low[i] >= 250)ans[3]++;
    if(low[i] < 0 && high[i] >= 0)ans[4]++;
    if(high[i] < 0)ans[5]++;
  }
  rep(i, 6){
    cout << ans[i] << (i == 5 ? "\n" : " ");
  }
}