#include <iostream>
#include <string>

using namespace std;

int main()
{
  int i = 0;
  string s;
  bool condition = true;
  cin >> s;
  while (i < s.size())
  {
    if (s.at(i) == 'o' || s.at(i) == 'k' || s.at(i) == 'u')
      i++;
    else if (s.at(i) == 'c' && s.at(i + 1) == 'h')
      i += 2;
    else
    {
      condition = false;
      break;
    }
  }
  cout << (condition ? "YES" : "NO") << endl;
}
