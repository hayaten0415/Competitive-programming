#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n;
  int sum = 0;
  cin >> n;
  int v[n], c[n];
  for (int i = 0; i < n; i++){
    cin >> v[i];
  }
  for (int i = 0; i < n; i++){
    cin >> c[i];
  }
  for (int i = 0; i < n; i++){
    sum = max(sum, sum + v[i] - c[i]);
  }
  cout << sum << endl;
}