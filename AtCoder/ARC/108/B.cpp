#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  stack<char> st;
  rep(i, n){
    int ok = 1;
    st.push(s[i]);
    if(st.size() < 3)continue;
    while(true){
      if(st.size() > 2){
        char three = st.top();
        st.pop();
        char two = st.top();
        st.pop();
        char one = st.top();
        st.pop();
        if(one != 'f' || two != 'o' || three != 'x'){
          st.push(one);
          st.push(two);
          st.push(three);
          break;
        }
      }else{
        break;
      }
    }
  }
  cout << st.size() << endl;
}