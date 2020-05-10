#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n, q;
  string s;
  cin >> n >> q >> s;
  vector<int> sum(n, 0);
  for(int i = 1; i < n; i++){
    if(s[i-1] == 'A' && s[i] == 'C'){
      sum[i] = sum[i - 1] + 1;
    }else {
      sum[i] = sum[i - 1];
    }
  }
  rep(i,q){
    int l, q;
    cin >> l >> q;
    l--, q--;
    cout << sum[q] - sum[l] << endl;
  }
}