#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int ans = 0;
  vector<string> s(n);
  vector<int> d(n);
  rep(i,n){
    cin >> s[i] >> d[i];
  }
  rep(i,n){
    int num = 0;
    if(d[i] < a){
      num = a;
    }else if( b < d[i]){
      num = b;
    }else {
      num = d[i];
    }
    if(s[i] == "East"){
      ans += num;
    }else {
      ans -= num;
    }
  }
  if(ans > 0){
    cout << "East " << abs(ans) << endl;
  }else if (ans < 0){
    cout << "West " << abs(ans) << endl;
  }else {
    cout << 0 << endl;
  }
}
