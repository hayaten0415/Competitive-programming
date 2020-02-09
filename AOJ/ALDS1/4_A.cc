#include<iostream>
using namespace std;
bool linearSearch(int A[], int n, int key){
  int i = 0;
  A[n] = key;
  while (A[i] != key) i++;
  return i != n ? true : false;
}

int main() {
  int i, n, q, key, sum = 0;
  cin >> n;
  int A[n + 1];
  for (i = 0; i < n; i++){
    cin >> A[i];
  }
  cin >> q;
  for (i = 0; i < q; i++){
    cin >> key;
    if(linearSearch(A, n, key)) sum++;
  }
  cout << sum << endl;
}