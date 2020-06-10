#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;


int main() {
  int n;
  cin >> n;
  int ans = 0;
  vector<int> h(n);
  rep(i, n) cin >> h[i];
  while(true){
    if(*max_element(h.begin(), h.end()) == 0) break;
    int i = 0;
    while(i < n){
      if(h[i] == 0)i++;
      else{
        ans++;
        while(i < n && h[i] > 0){
          h[i]--;
          i++;
        }
      }
    }
  }
  cout << ans << endl;
}