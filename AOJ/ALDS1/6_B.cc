#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 100000
using namespace std;
using ll = long long;

int A[MAX], n;

int partition(int p, int r) {
  int x = A[r];
  int i = p - 1;
  for (int j = p; j < r; j++) {
    if(A[j] <= x) {
      i++;
      swap(A[i], A[j]);
    }
  }
  swap(A[i + 1], A[r]);
  return i + 1;
}

int main() {
  int b;
  cin >> n;
  rep(i, n) cin >> A[i];
  b = partition(0, n - 1);
  rep(i,n) {
    if(i == b) {
      cout << "[" << A[i] << "]";
    } else {
      cout << A[i];
    }
    if(i < n - 1) {
      cout << " ";
    }
  }
  cout << endl;
  return 0;
}