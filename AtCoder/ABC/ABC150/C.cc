#include <bits/stdc++.h>
#include <algorithm>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;


int main() {
  int n;
  int c = 0;
  int ansa = 0, ansb = 0;
  cin >> n;
  vector<int> A(n);
  vector<int> B(n);
  vector<int> C(n);
  rep(i, n) A[i] = i + 1;
  rep(i, n) cin >> B[i];
  rep(i, n) cin >> C[i];
  while (next_permutation(A.begin(), A.end())){
    c++;
    if (A == B){
      ansa = c;
    }
    if(A == C) ansb = c;
  }
  cout << abs(ansa - ansb) << endl;
  return 0;
}