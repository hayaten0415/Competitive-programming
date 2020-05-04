#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int MOD = 1000000007;

//繰り返し自乗法(modあり)
ll RepeatSquaring(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
    return N * RepeatSquaring(N, P-1, M);
}

int main() {
  ll n;
  cin >> n;
  bool cond = true;
  vector<ll> A(n);
  map<ll, int> mp;
  rep(i, n){
    cin >> A[i];
    mp[A[i]]++;
  }
  for (ll j = n - 1; j >= 0; j -= 2){
    if(n % 2 == 0){
      if(mp[j] != 2){
        cond = false;
        break;
      }
    }else {
      if(j > 0){
        if(mp[j] != 2){
          cond = false;
          break;
        }
      }else {
        if(mp[j] != 1) {
          cond = false;
          break;
        }
      }
    }
  }
  cout << (cond ? RepeatSquaring(2, n / 2, MOD) : 0) << endl;
}