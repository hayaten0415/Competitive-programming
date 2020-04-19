#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int a, b, t;
  int sum = 0;
  cin >> a >> b >> t;
  for (int i = 1; a * i <= t; i++){
    sum += b;
  }
  cout << sum << endl;
}