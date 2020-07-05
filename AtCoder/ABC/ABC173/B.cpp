#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(4);
  rep(i, n){
    string s;
    cin >> s;
    if(s == "AC")a[0]++;
    if(s == "WA") a[1]++;
    if(s == "TLE")a[2]++;
    if(s == "RE")a[3]++;
  }
  cout << "AC" << " x " << a[0] << endl;
  cout << "WA" << " x " << a[1] << endl;
  cout << "TLE" << " x " << a[2] << endl;
  cout << "RE" << " x " << a[3] << endl;
}