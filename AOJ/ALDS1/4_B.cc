#include<iostream>
using namespace std;
int n;

bool binarySearch(int A[], int key){
  int left = 0;
  int right = n;
  int mid;
  while (left < right){
    mid = (left + right) / 2;
    if(key == A[mid]) return true;
    if(key > A[mid]){
       left = mid + 1;
    } else {
      right = mid;
    }
  }
  return false;
}

int main() {
  int q, key, sum = 0;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  cin >> q;
  for (int i = 0; i < q; i++){
    cin >> key;
    if(binarySearch(A, key)) sum++;
  }
  cout << sum << endl;
}