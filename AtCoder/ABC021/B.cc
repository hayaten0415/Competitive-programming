#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int n, a, b, k;
  bool condition = true;
  cin >> n >> a >> b >> k;
  int p[k + 2];
  for (int i = 0; i < k; i++){
    cin >> p[i];
  }
  p[k] = a;
  p[k + 1] = b;
  sort(p, p + k + 1);
  for (int i = 0; i < k + 1; i++){
    if (p[i] == p[i + 1]){
      condition = false;
      break;
    }
  }
  cout << (condition ? "YES" : "NO") << endl;
}