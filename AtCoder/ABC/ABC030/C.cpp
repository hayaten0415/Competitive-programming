#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, m, x, y;
  cin >> n >> m >> x >>y;
  vector<int> a(n);
  vector<int> b(m);
  rep(i, n) cin >> a[i];
  rep(i, m) cin >> b[i];
  bool now_a = true;
  int cn = 0;
  int num = a[0] + x;
  while(true){
    if(now_a){
      auto itr = lower_bound(b.begin(), b.end(), num);
      cn++;
      if(itr == b.end())break;
      else{
        num = *itr + y;
      }
    }else{
      auto itr = lower_bound(a.begin(), a.end(), num);
      cn++;
      if(itr == a.end())break;
      else{
        num = *itr + x;
      }
    }
    now_a = (now_a ^ 1);
  }
  cout << cn /2  << endl;
}