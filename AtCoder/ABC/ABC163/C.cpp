#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> b(n);
  for (int i = 1; i < n; i++){
    int a;
    cin >> a;
    a--;
    b[a].emplace_back(i);
  }
  rep(i,n){
    if(i == n - 1){
      cout << 0 << endl;
    }else {
      cout << b[i].size() << endl;
    }
  }
}