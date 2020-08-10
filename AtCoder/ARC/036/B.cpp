#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  if(n == 1){ 
    cout << 1 << endl;
    return 0;
  }
  int ans = 1;
  int num = 1;
  bool right_bigger = true;
  rep(i, n-1){ 
    if(a[i] == a[i+1]){ 
      ans = max(ans,num);
      num=1;
      continue;
    }
    if(num == 1){ 
      if(a[i] < a[i+1])right_bigger =true;
      else right_bigger =false;
    }
    if(a[i] < a[i+1]){ 
      if(right_bigger){ 
        num++;
        continue;
      }else{ 
        right_bigger = true;
        ans = max(ans, num);
        num = 2;
        continue;
      }
    }
    if(a[i] > a[i+1]){ 
      if(!right_bigger){ 
        num++;
        continue;
      }else{ 
        right_bigger = false;
        num++;
      }
    }
  }
  ans = max(ans, num);
  cout << ans << endl;
}