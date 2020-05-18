#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, k, s;
  cin >> n >> k >> s;
  rep(i,n){
    if(i < k){
      cout << s << (i == n - 1 ? "\n" : " ");
    }else {
      if(s == 1000000000){
        cout << s - 1 << (i == n - 1 ? "\n" : " ");
      }else {
        cout << s + 1 << (i == n - 1 ? "\n" : " ");
      }
    }
  }
  return 0;
}