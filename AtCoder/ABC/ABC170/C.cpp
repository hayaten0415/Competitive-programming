#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int x, n;
  cin >> x >> n;
  if(n == 0){
    cout << x << endl;
    return 0;
  }
  set<int> a;
  rep(i, n){
    int tmp;
    cin >> tmp;
    a.insert(tmp);
  }
  auto c = a.find(x);
  if(c== a.end()){
    cout << x << endl;
    return 0;
  }
  int minus = 1;
  int plus = 1;
  while (true){
    auto it = a.find(x-minus);
    auto ic = a.find(x + plus);
      if(it == a.end()){
        cout << x - minus << endl;
        return 0;
      }
      if(ic == a.end()){
        cout << x  + plus << endl;
        return 0;
      }
    minus++;
    plus++;
  }
}