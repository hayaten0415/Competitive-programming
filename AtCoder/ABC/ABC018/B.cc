#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  string s; 
  int n;
  int first, second;
  cin >> s >> n;
  vector<char> a(n);
  for (int i = 0; i < n; i++)
  {
    cin >> first >> second;
    first--;
    second--;
    for (int j = 0; j < (second - first + 1) / 2; j++){
      if(first + j < second - j) swap(s[first + j], s[second - j]);
    }
  }
  cout << s << endl;
  return 0;
}
