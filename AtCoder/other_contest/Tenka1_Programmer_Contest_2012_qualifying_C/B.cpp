#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  string s;
  cin >> s;
  int S = 0, H = 0, D = 0, C = 0;
  int n = s.size();
  char alpha;
  string ans = "";
  int end = 0;
  rep(i, n){
    if(s[i] == 'S' && (s[i+1] == '1' || s[i+1] == 'J' || s[i+1] == 'Q' || s[i+1] == 'K' || s[i+1] == 'A'))S++;
    if(s[i] == 'H'&& (s[i+1] == '1' || s[i+1] == 'J' || s[i+1] == 'Q' || s[i+1] == 'K' || s[i+1] == 'A'))H++;
    if(s[i] == 'D'&& (s[i+1] == '1' || s[i+1] == 'J' || s[i+1] == 'Q' || s[i+1] == 'K' || s[i+1] == 'A'))D++;
    if(s[i] == 'C'&& (s[i+1] == '1' || s[i+1] == 'J' || s[i+1] == 'Q' || s[i+1] == 'K' || s[i+1] == 'A'))C++;
    if(S== 5 || H == 5 || D == 5 || C == 5){
      alpha = s[i];
      end = i;
      break;
    }
  }
  int i = 0;
  while(i < end){
    if(s[i] == alpha){
      if(s[i+1] == '1'){
        i+=3;
        continue;
      }else if(s[i+1] == 'J' || s[i+1] == 'Q' || s[i+1] == 'K' || s[i+1] == 'A'){
        i+= 2;
        continue;
      }
    }
    ans += s[i];
    i++;
  }
  cout << (ans.size() == 0 ? "0" : ans) << endl;
}
