#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int a, b, c;
  cin >> a >> b >> c;
  vector<int> d = {a, b, c};
  sort(d.begin(), d.end());
  cout << d.at(1) << endl;
  return 0;
}
