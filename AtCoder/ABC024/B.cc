#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n, t;
  int limit, count = 0;
  cin >> n >> t;
  int A[n];
  for (int i = 0; i < n; i++){
    cin >> A[i];
  }
  for (int i = 1; i < n; i++){
    if(A[i] - A[i - 1] <= t) {
      limit = A[i] + t;
      count += A[i] - A[i - 1];
    }else {
      count += t;
    }
  }
  count += t;
  cout << count << endl;
}
