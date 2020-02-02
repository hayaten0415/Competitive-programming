#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool IsPrime(int num)
{
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2){
      if (num % i == 0){
        // 素数ではない
        return false;
      }
    }
    // 素数である
    return true;
}

int main()
{
  int n;
  int count = 0;
  cin >> n;
  int A[n];
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    if (IsPrime(A[i])) count++;
  }
  std::cout << count << endl;
  return 0;
}
