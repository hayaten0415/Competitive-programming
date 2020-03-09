#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
  int a, b, m;
  int numa, numb, numc;
  int c = 0;
  cin >> a >> b >> m;
  int A[a], B[b];
  priority_queue<int, vector<int>, greater<int>> aque;
  priority_queue<int, vector<int>, greater<int>> bque;
  rep(i, a){
    cin >> A[i];
    aque.push(A[i]);
  }
  rep(i ,b) {
    cin >> B[i];
    bque.push(B[i]);
  }
  ll ans = (ll)aque.top() + bque.top();
  rep(i ,m) {
    cin >> numa >> numb >> numc;
    numa--;
    numb--;
    ans = min(ans, (ll)A[numa] + B[numb] - numc);
  }
  cout << ans << endl;
  return 0;
}