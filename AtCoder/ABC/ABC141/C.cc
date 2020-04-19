#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
  int n, k, q;
  int num;
  cin >> n >> k >> q;
  vector<int> A(n, k - q);
  rep(i, q) {
    cin >> num;
    num--;
    A[num]++;
  }
  rep(i ,n) {
    if(A[i] > 0){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
  return 0;
}