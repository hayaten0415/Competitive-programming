#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int t, n;
  cin >> t >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  int m;
  cin >> m;
  vector<int> b(m);
  rep(i, m) cin >> b[i];
  if(n < m){
    cout << "no" << endl;
    return 0;
  }
  int index = 0;
  vector<bool> ok(m,false);
  rep(i, m){
    while(index < n){
      if(a[index] <= b[i]){
        if(a[index] >= b[i] -t){
          index++;
          ok[i] = true;
          break;
        }
        index++;
      }else{
        index++;
        break;
      }
    }
  }
  rep(i, m){
    if(!ok[i]){
      cout << "no" << endl;
      return 0;
    }
  }
  cout << "yes" << endl;
}