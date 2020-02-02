#include <iostream>
#include <algorithm>

using namespace std;

int selectionSort(int A[], int N)
{
  int minj;
  int changecount = 0;
  for (int i = 0; i < N - 1; i++){
    minj = i;
    for (int j = i; j < N; j++){
      if (A[j] < A[minj]){
        minj = j;
      }
    }
    swap(A[i], A[minj]);
    if (i != minj) changecount++;
  }
  return changecount;
}

int main()
{
  int n;
  int changecount;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) cin >> A[i];
  changecount = selectionSort(A, n);
  for (int i = 0; i < n; i++){
    if (i != 0){
      cout << " ";
    }
    cout << A[i];
  }
  cout << endl;
  cout << changecount << endl;
  return 0;
}
