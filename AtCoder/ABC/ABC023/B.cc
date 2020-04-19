#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  int n, i;
  string S, s="b";
  cin >> n >> S;
  for (i = 0; i <= n; i++){
    if(s.size()>=n) break;
    if(i % 3 == 0) s = 'a' + s +'c';
    if(i % 3 == 1) s = 'c' + s +'a';
    if(i % 3 == 2) s = 'b' + s + 'b';
  }
  cout << (s == S ? i : -1) << endl;
  return 0;
}