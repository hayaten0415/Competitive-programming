#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int n;
  cin >> n;
  vector<int> R(n);
  for (int i = 0; i < n; i++) cin >> R[i];
  int minp = R[0];
  int maxp = -2000000000;
  for (int i = 1; i < n; i++){
    maxp = max(maxp, R[i] - minp);
    minp = min(minp, R[i]);
  }
  cout << maxp << endl;
  return 0;
}
