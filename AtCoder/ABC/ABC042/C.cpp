#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;


int main() {
  int n, k;
  cin >> n >> k;
  vector<int> d(k);
  rep(i,k){
    cin >> d[i];
  }
  for (int i = n; i < 100000; i++){
    int num = i;
    bool ans = true;
    while(num > 0){
      int a = num % 10;
      rep(i, k){
        if(d[i] == a){
          ans = false;
        }
      }
      num /= 10;
    }
    if(ans){
      cout << i << endl;
      return 0;
    }
  }
}