#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
  int n, sum = 0, avg = 0, ans = 0, avg1 = 0, ans1 = 0;
  cin >> n;
  int X[n];
  rep(i, n){
    cin >> X[i];
    sum += X[i];
  }
  avg = sum / n;
  avg1 = avg + 1;
  rep(i,n){
    ans += (int)pow((double)(X[i] - avg), 2.0);
    ans1 += (int)pow((double)(X[i] - avg1), 2.0);
  }
  cout << min(ans, ans1) << endl;
  return 0;
}