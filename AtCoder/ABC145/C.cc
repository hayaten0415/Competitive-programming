#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;


int main(){
  int n;
  cin >> n;
  vector<int> xi(n);
  vector<int> yi(n);
  double ans = 0;
  rep(i, n){
    cin >> xi[i] >> yi[i];
    for(int j = 0; j < i; j++){
      ans += (sqrt(pow((xi[i]-xi[j]),2) + pow((yi[i]-yi[j]),2)) * 2)/ n;
    }
  }
  cout << fixed << setprecision(10) << ans << endl;
  return 0;
}