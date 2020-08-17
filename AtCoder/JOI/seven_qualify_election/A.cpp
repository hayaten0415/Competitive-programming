#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, rest, ans =0;
  cin >> n;
  rest = 1000 - n;
  if(rest >= 500){
    ans += rest / 500;
    rest -= 500 * (rest / 500);
  }
  if(rest >= 100){
    ans += rest / 100;
    rest -= 100 * (rest / 100);
  }
  if(rest >= 50){
    ans += rest / 50;
    rest -= 50 * (rest / 50);
  }
  if(rest >= 10){
    ans += rest / 10;
    rest -= 10 * (rest / 10);
  }
  if(rest >= 5){
    ans += rest / 5;
    rest -= 5 * (rest / 5);
  }
  if(rest >= 1){
    ans += rest;
  }
  cout << ans << endl;
}