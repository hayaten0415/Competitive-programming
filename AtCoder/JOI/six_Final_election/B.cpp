#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, k;
  cin >> n >> k;
  vector<bool> a(n+1,false);
  rep(i, k){
    int num;
    cin >> num;
    a[num] = true;
  }
  bool blankpaper_exist = a[0];
  bool blankpaper_used = false;
  int blankblankpaper_used_index = -1;
  int num = 0;
  int ans = 0;
  if(!blankpaper_exist){
    for(int i = 1; i <= n; i++){
      if(a[i])num++;
      else{ 
        ans = max(ans,num);
        num = 0;
      }
    }
    ans = max(ans, num);
  }else{ 
    for(int i = 1; i <= n; i++){
      if(a[i])num++;
      else{ 
        if(!blankpaper_used){ 
          num++;
          blankpaper_used = true;
          blankblankpaper_used_index = i;
          continue;
        }else{ 
          ans = max(ans,num);
          num = i - blankblankpaper_used_index;
          blankblankpaper_used_index = i;
          continue;
        }
      }
    }
    ans = max(ans, num);
  }
  cout << ans << endl;
}