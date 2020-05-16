#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<ll> A(n), B(n);
  ll biga = 0, bigb = 0;
  rep(i, n) cin >> A[i];
  rep(i,n)  cin >> B[i];
  rep(i,n){
    if(A[i] > B[i]) biga += A[i] - B[i];
    if(B[i] > A[i]) bigb += (B[i] - A[i])/2;
  }
  if(bigb >= biga) cout << "Yes" << endl;
  else cout << "No" <<endl;
}