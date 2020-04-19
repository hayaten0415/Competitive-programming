#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  int num = 0;
  ll sum = 0;
  cin >> n;
  vector<int> a(n);
  unordered_map<int, int> b;
  rep(i,n){
    cin >> num;
    a[i] = num;
    //キーがすでに含まれていればインクリメント
    if (b.find(num) != b.end()) {
      b.at(num)++;
      sum += b.at(num) - 1;
    //キーが含まれていなければ新たにキーを入れて値は1に設定
    } else {
      b[num] = 1;
    }
  }
  rep(i,n){
    if(b.at(a[i]) > 0){
      cout << sum - b.at(a[i]) + 1 << endl;
    }else {
      cout << sum << endl;
    }
  }
}