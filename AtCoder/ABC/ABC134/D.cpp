#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
int n;

void dfs(int k, vector<int> &a, vector<int> &b){
  //2倍したときの値がnより大きければa[k-1]と同じ値を入れれば良い
  if(2 * k > n){
    b[k-1] = a[k-1];
    return;
  }
  int d = n / k;
  int g = k * d;
  int num = 0;
  //kを2倍、3倍あるいはhoge倍したときのb[hogek-1]の値を加算し
  //その加算した値とa[k-1]との偶奇が一致していれば0一致していなければ1
  while(g > k){
    num += b[g-1];
    g -= k;
  }
  if(a[k-1] == num % 2){
    b[k - 1] = 0;
  }else{
    b[k - 1] = 1;
  }
  return;
}

int main() {
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> b(n);
  vector<int> ans;
  int ans_count = 0;
  for (int i = n - 1; i >= 0; i--){
    dfs(i + 1, a, b);
  }
  int d = 0;
  rep(i, n){
    if (b[i] > 0){
      ans.push_back(i + 1);
    }
    //前から決めていくことで必ず決定できる。
    //if(b[i] % 2 != a[i]){
    //  cout << -1 << endl;
    //  return 0;
    //}
  }
  if(ans.size() == 0){
    cout << 0 << endl;
  }else {
    cout << ans.size() << endl;
    rep(i,ans.size()){
      cout << ans[i] << (i == ans.size() - 1 ? "\n" : " ");
    }
  }
}