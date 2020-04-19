#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;


ll RepeatSquaring(ll N, ll P){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2);
        return t*t;
    }
    return N * RepeatSquaring(N, P-1);
}

int main() {
  int n, k;
  cin >> n >> k;
  double ans = 0;
  for (int i = 1; i <= n; i++){
    double per = (1 / n);
    ()
  }
}