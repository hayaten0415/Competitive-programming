#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int N, L;
  cin >> N >> L;
  vector<vector<char>> str(L+1, vector<char>(2 * N -1));
  string s;
  int point = 0;
  rep(i, L + 2){
    getline(cin, s);
    if(s.empty() == false){
      rep(j, s.size()){
        str[i - 1][j] = s[j];
        if(s[j] == 'o'){
          point = j;
        }
      }
    }
  }
  for (int i = L - 1; i >= 0; i--){
    if(point + 1 < 2 * N - 1 && str[i][point + 1] == '-'){
      point += 2;
    }else if(point - 1 >= 0 && str[i][point - 1] == '-'){
      point -= 2;
    }
  }
  cout << point / 2 + 1 << endl;
}