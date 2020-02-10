#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  bool unique = true;
  cin >> n;
  long A[n];
  for (int i = 0; i < n; i++){
    cin >> A[i];
  }
  sort(A, A + n);
  for (int i = 0; i < n - 1; i++){
    if(A[i] == A[i + 1]) {
      unique = false;
      break;
    }
  }
  cout << (unique ? "YES" : "NO") << endl;
}
