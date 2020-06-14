#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;
const int MAX = 1000000000;
const int MIN = 0;

int main() {
  int n;
  cin >> n;
  vector<vector<int>> Subord(n);
  vector<int> salary(n);
  rep(i, n-1){
    int b;
    cin >> b;
    b--;
    Subord[b].push_back(i + 1);
  }
  for (int i = n - 1; i >= 0; i--){
    if(Subord[i].size() == 0)salary[i] = 1;
    else if(Subord[i].size() == 1)salary[i] = 2 * salary[Subord[i][0]] + 1;
    else {
      int mx = MIN;
      int mn = MAX;
      for(auto index: Subord[i]){
        mx = max(mx, salary[index]);
        mn = min(mn, salary[index]);
      }
      salary[i] = mx + mn + 1;
    }
  }
  cout << salary[0] << endl;
}