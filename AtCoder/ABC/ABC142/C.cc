#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
  int n, num;
  cin >> n;
  vector<int> a(n);
  rep(i ,n) {
    cin >> num;
    num--;
    a[num] = i + 1;
  }
  rep(i ,n) {
    cout << a[i];
    if(i < n - 1){
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}