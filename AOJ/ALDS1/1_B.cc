#include <iostream>
#include <algorithm>

using namespace std;

int gcd(int a, int b)
{
  int smaller = min(a, b);
  int bigger = max(a, b);
  int surplus = bigger % smaller;
  if(surplus == 0) return smaller;
  surplus = gcd(smaller, surplus);
  return surplus;
}
int main()
{
  int a, b;
  cin >> a >> b;
  cout << gcd(a, b) << endl;
  return 0;
}