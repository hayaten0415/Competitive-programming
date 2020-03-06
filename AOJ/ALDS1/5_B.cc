#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int L[500000 / 2 + 2], R[500000 / 2 + 2];
int cnt;

void merge(int A[], int n, int left, int mid, int right){
  int n1 = mid - left;
  int n2 = right - mid;
  rep(i, n1) L[i] = A[left + i];
  rep(i, n2) R[i] = A[mid + i];
  //番兵の設定
  L[n1] = R[n2] = 2000000000;
  int i = 0, j = 0;
  for (int k = left; k < right; k++) {
    cnt++;
    if(L[i] <= R[j]) {
      A[k] = L[i++];
    } else {
      A[k] = R[j++];
    }
  }
}

void mergeSort(int A[], int n, int left, int right) {
  if(left+1 < right) {
    int mid = (left + right) / 2;
    mergeSort(A, n, left, mid);
    mergeSort(A, n, mid, right);
    merge(A, n, left, mid, right);
  }
}

int main() {
  int A[500000], n;
  cnt = 0;
  cin >> n;
  rep(i, n) cin >> A[i];
  mergeSort(A, n, 0, n);
  rep(i, n) {
    cout << A[i];
    if(i < n - 1) {
      cout << " ";
    }
  }
  cout << endl;
  cout << cnt << endl;
  return 0;
}