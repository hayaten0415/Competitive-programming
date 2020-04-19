#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  long n;
  int first, second;
  cin >> n;
  int changecount =(int)(n % 30);
  int A[] = {1, 2, 3, 4, 5, 6};
  for (int i = 0; i < changecount; i++){
    first = (i % 5);
    second = (i % 5) + 1;
    swap(A[first], A[second]);
  }
  for (int i = 0; i < 6; i++){
    cout << A[i];
  }
}