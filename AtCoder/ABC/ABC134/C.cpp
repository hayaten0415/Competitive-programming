#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  int mx = 0;
  cin >> n;
  vector<int> a(n);
  priority_queue<int> A;
  rep(i, n) {
    cin >> a[i];
    A.push(a[i]);
  }
  rep(i ,n){
    if(a[i] != A.top()) {
      cout << A.top() << endl;
    }else {
      int tmp = A.top();
      A.pop();
      cout << A.top() << endl;
      A.push(tmp);
    }
  }
}