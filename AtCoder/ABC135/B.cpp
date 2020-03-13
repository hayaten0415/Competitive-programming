#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  int num = 0;
  cin >> n;
  vector<int> p(n);
  vector<int> a;
  rep(i, n){
    cin >> p[i];
    p[i]--;
  }
  rep(i, n-1) {
    if(p[i] != i) {
      num++;
      a.push_back(i);
    }
  }
  if(num > 2){
    cout << "NO" << endl;
  }else {
    cout << "YES" << endl;
  }
}