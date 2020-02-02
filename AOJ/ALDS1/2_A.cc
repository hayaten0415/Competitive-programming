#include <iostream>
#include <algorithm>

using namespace std;

int bubbleSort(int A[], int N) 
{
  int changecount = 0;
  bool flag = 1;
  for (int i = 0; flag; i++){
    flag = 0;
    for (int j =  N - 1;  j >= i + 1; j--){
      if (A[j] < A[j - 1]){
        swap(A[j], A[j - 1]);
        flag = 1;
        changecount++;
      }
    }
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
  changecount = bubbleSort(A, n);
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
