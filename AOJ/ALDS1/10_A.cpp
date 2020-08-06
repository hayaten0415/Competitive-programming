#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
vector<ll> memo(45, -1);


ll fib(ll n){
  if(memo[n] != -1)return memo[n];
  return memo[n] = fib(n-1) + fib(n-2);
}


int main() {
  ll n;
  cin >> n;
  memo[0] = 1;
  memo[1] = 1;
  cout << fib(n) << endl;
}