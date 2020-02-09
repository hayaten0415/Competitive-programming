#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int a, b, c, k, s, t;
  cin >> a >> b >> c >> k >> s >> t;

  cout << (s + t >= k ? a * s + b * t - c * (s + t) : a * s + b * t) << endl;
}
