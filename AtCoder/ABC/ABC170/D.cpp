#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> cn(1000005, 0);
  rep(i, n){
    cin >> A[i];
  }
  int ans = 0;
  sort(A.begin(), A.end());
  for(int x: A){
    if(cn[x] > 0){
      cn[x] = 2;
      continue;
    }
    for (int i = x; i < 1000005; i += x){
      cn[i]++;
    }
  }
  for(int x: A){
    if(cn[x] == 1)ans++;
  }
  cout << ans << endl;
}