#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, c;
  cin >> n >> c;
  vector<int> odd(10, 0);
  vector<int> even(10, 0);
  rep(i, n){
    int a;
    cin >> a;
    a--;
    if(i % 2 == 0){
      odd[a]++;
    }else {
      even[a]++;
    }
  }
  int mn = 1000000;
  rep(i ,10){
    rep(j, 10){
      int num = 0;
      if(i == j) continue;
      if(n % 2 == 1){
        num += n / 2 + 1 - odd[i];
        num += n / 2 - even[j];
      }else {
        num += n / 2 - odd[i];
        num += n / 2 - even[j];
      }
      mn = min(mn, num);
    }
  }
  cout << mn * c << endl;
}