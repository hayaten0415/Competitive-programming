#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<string> num(10,"");
  vector<string> res(1000);
  vector<bool> open(1000, false);
  rep(i, 10){
    char a = i + '0';
    num[i] = a;
  }
  int index = 0;
  rep(i, 10){
    rep(j,10){
      rep(k,10){
        res[index] = num[i] + num[j] + num[k];
        index++;
      }
    }
  }
  rep(i, 1000){
    char one = res[i][0];
    char two = res[i][1];
    char three = res[i][2];
    string tmp = "";
    rep(j, n){
      if(tmp.size() == 0){
        if(s[j] == one){
          tmp += s[j];
          continue;
        }
      }else if(tmp.size() == 1){
        if(s[j] == two){
          tmp += s[j];
          continue;
        }
      }else if(tmp.size() == 2){
        if(s[j] == three){
          tmp += s[j];
          continue;
        }
      }
    }
    if(tmp.size() == 3){
      int ind = 0;
      ind += 100 * (tmp[0] - '0');
      ind += 10 * (tmp[1] - '0');
      ind += (tmp[2] - '0');
      open[ind] = true;
    }
  }
  int ans = 0;
  rep(i,1000){
    if(open[i])ans++;
  }
  cout << ans << endl;
}