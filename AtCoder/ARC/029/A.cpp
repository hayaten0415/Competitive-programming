#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  int num1 = 0;
  int num2 = 0;
  vector<int> a(n);
  if(n == 1){
    int a;
    cin >> a;
    cout << a << endl;
    return 0;
  }
  if(n == 2){
    int num1, num2;
    cin >> num1 >> num2;
    cout << max(num1, num2) << endl;
    return 0;
  }
  rep(i, n){
    cin >> a[i];
  }
  sort(a.begin(), a.end());
  if(n == 3){
    cout << max(a[0] + a[1], a[2]) << endl;
    return 0;
  }
  if(n == 4){
    cout << min(max(a[0] + a[3], a[1] + a[2]), max(a[3], a[0] + a[1] + a[2])) << endl;
    return 0;
  }
}