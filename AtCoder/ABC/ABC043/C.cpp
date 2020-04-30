#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int sum = 0, ans1 = 0, ans2 = 0;
  vector<int> a(n);
  rep(i,n){
    cin >> a[i];
    sum += a[i];
  }
  int avg1 = sum / n;
  int avg2 = avg1 + 1;
  rep(i,n){
    ans1 += pow(abs(a[i] - avg1), 2);
    ans2 += pow(abs(a[i] - avg2), 2);
  }
  cout << min(ans1, ans2) << endl;
}