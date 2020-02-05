#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  int n, s, t, w, weight, bestcount;
  bestcount = 0;
  weight = 0;
  cin >> n >> s >> t;
  for (int i = 0; i < n; i++){
    scanf("%d", &w);
    weight += w;
    if(s <= weight && weight <= t) bestcount++;
  }
  cout << bestcount << endl;
}
