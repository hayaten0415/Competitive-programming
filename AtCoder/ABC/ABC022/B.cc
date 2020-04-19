#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int n, anscount;
  int i = 0;
  int count = 1;
  anscount = 0;
  cin >> n;
  int A[n];
  for (int s = 0; s < n; s++){
    cin >> A[s];
  }
  sort(A, A + n);
  while (i < n){
    for (int j = i; j < n; j++){
      if (A[j] == A[j + 1]){
        anscount++;
        count++;
      } else {
        i += count;
        count = 1;
        break;
      }
    }
  }
  cout << anscount << endl;
}