#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int a = n / 10;
  int b = n - 10 * a;
  cout << a + b << endl;
}
