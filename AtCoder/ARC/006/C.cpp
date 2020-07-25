#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> compare;
  rep(i, n){
    int w;
    cin >> w;
    if (compare.size() == 0){
      compare.push_back(w);
    }else{
      sort(compare.begin(), compare.end(), greater<int>());
      bool find = false;
      rep(j,compare.size()){
        if(compare[j] >= w){
          if(j + 1 < compare.size() && compare[j + 1] >= w){
            continue;
          }else{
            compare[j] = w;
            find = true;
            break;
          }
        }
      }
      if(!find)compare.push_back(w);
    }
  }
  cout << compare.size() << endl;
}