#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n){
    cin >> a[i];
  }
  int ans = 0;
  set<int> num;
  int right = 0;
  for (int left = 0; left < n; left++){
    while(right < n && num.find(a[right]) == num.end()){
      num.insert(a[right]);
      right++;
    }
    ans = max(ans,right - left);
    if(right == left)right++;
    else num.erase(a[left]);
  }
  cout << ans << endl;
}