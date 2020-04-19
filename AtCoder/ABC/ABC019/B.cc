#include <iostream>
#include <string>
using namespace std;

int main()
{
  string s;
  cin >> s;
  string ans;
  int count = 1;
  for (int i = 0; i < s.size(); i++)
  {
    if (i + 1 < s.size() && s.at(i) == s.at(i + 1))
    {
      count++;
    }
    else
    {
      ans += s.at(i);
      ans += to_string(count);
      count = 1;
    }
  }
  cout << ans << endl;
  return 0;
}
