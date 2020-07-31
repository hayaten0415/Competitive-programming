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
  vector<P> A(n);
  ll aoki_sum = 0;
  ll takahashi_sum = 0;
  rep(i, n){
    int a, b;
    cin >> a >> b;
    aoki_sum += b;
    A[i] = {a, b};
  }
  sort(A.begin(), A.end(), [](P x, P y) {
    return (x.first + x.second) >  (y.first+ y.second);
  });
  rep(i, n){
    if(i % 2 == 0)takahashi_sum += A[i].first + A[i].second;
  }
  cout << takahashi_sum - aoki_sum << endl;
}