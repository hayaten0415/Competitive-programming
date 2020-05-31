#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

const int MOD = 1000000007;
const ll MAX = 1000000000000000000;


int main() {
  int n;
  cin >> n;
  bool not_ok = false;
  ll sum = 1;
  vector<ll> a(n);
  rep(i,n){
    cin >> a[i];
    sum *= a[i];
    if(a[i] == 0){
      cout << 0 << endl;
      return 0;
    }
    if(sum <= 0 || sum > MAX){
      not_ok = true;
    }
  }
  if(not_ok){
    cout << -1 << endl;
  }else{
    cout << sum << endl;
  }
}