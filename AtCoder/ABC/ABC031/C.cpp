#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  ll ans = -1000000000;
  rep(i, n) cin >> a[i];
  //高橋くんが丸つける場所
  rep(i, n){
    //青木くんが丸つける場所
    int max_aoki_index = 0;
    ll mx_aoki = -100000000;
    for (int j = n - 1; j >= 0; j--){
      if(i == j)continue;
      ll tmp_aoki = 0;
      vector<int> tmp;
      int left, right;
      if(i < j){
        left = i;
        right = j;
        ll ans = -1000000000;
      }else{
        left = j;
        right = i;
      }
      for (int k = left; k <= right; k++){
        tmp.push_back(a[k]);
      }
      for (int k = 0; k < tmp.size(); k++){
        if(k % 2 == 1)tmp_aoki+= tmp[k];
      }
      if(tmp_aoki >= mx_aoki){
        max_aoki_index = j;
        mx_aoki = tmp_aoki;
      }
    }
    int left, right;
    if(i < max_aoki_index){
      left = i;
      right = max_aoki_index;
    }else{
      left = max_aoki_index;
      right = i;
    }
    vector<int> tmp;
    ll mx_takahashi = 0;
    for (int s = left; s <= right; s++){
      tmp.push_back(a[s]);
    }
    for (int t = 0; t < tmp.size(); t++){
      if(t % 2 == 0)mx_takahashi += tmp[t];
    }
    ans = max(ans,mx_takahashi);   
  }
  cout << ans << endl;
}
