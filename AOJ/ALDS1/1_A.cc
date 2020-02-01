#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void trace(vector<int> nums, int N) 
{
  for (int k = 0; k < N; k++){
    if (k != N - 1){
      printf("%d ", nums[k]);
    }else{
      printf("%d\n", nums[k]);
    }
  }
}

void insertionSort(vector<int> nums, int N)
{
  int key;
  int j;
  for (int i = 1; i < N; i++){
    key = nums[i];
    j = i - 1;
    while (j >= 0 && nums[j] > key) {
      nums[j + 1] = nums[j];
      j--;
    }
    nums[j + 1] = key;
    trace(nums, N);
  }
}

int main()
{
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) cin >> A[i];
  trace(A, n);
  insertionSort(A, n);
  return 0;
}