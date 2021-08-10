#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define pb push_back
#define eb emplace_back
#define endl "\n"
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
using namespace std;
using P = pair<int, int>;
using PL = pair<long long, long long>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const int fx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const int fy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
template <typename T>
const auto INF = numeric_limits<T>::max();

bool ng[3][3];

void solve() {
  int n;
  cin >> n;
  rep(i, 2){
    string s;
    cin >> s;
    int a = s[0] - 'a';
    int b = s[1] - 'a';
    ng[a][b] = true;
  }
  vector<int> A(3), B(3);
  rep(i, 3){
    A[i] = i;
    B[i] = i;
  }
  auto build = [&](int cn, string &s, string &t)->bool {
    if(cn == 1){
      do{
        string a = "";
        rep(i, 3){
          a += char(A[i] + 'a');
        }
        bool ok2 = true;
        rep(i, 2){
          int c = a[i] - 'a';
          int d = a[i+1] - 'a';
          if(ng[c][d]){
            ok2 = false;
            break;
          }
        }
        if(ok2){
          s = a;
          return true;
        }
      } while (next_permutation(ALL(A)));
    }else{
      do{
        string a = "";
        rep(i, 3){
          a += char(A[i] + 'a');
        }
        bool ok2 = true;
        rep(i, 2){
          int c = a[i] - 'a';
          int d = a[i+1] - 'a';
          if(ng[c][d]){
            ok2 = false;
            break;
          }
        }
        if(!ok2){
          continue;
        }
        do{
          string b = "";
          rep(i, 3){
            b += char(B[i] + 'a');
          }
          bool ok3 = true;
          rep(i, 2){
            int c = b[i] - 'a';
            int d = b[i+1] - 'a';
            if(ng[c][d]){
              ok3 = false;
              break;
            }
          }
          if(!ok3){
            continue;
          }else{
            bool ok4 = true;
            string tmp1 = a + b;
            string tmp2 = b + a;
            if(n == 2){
              rep(i, 5){
                int c = tmp1[i] - 'a';
                int d = tmp1[i + 1] - 'a';
                if (ng[c][d]){
                  ok4 = false;
                  break;
                }
              }
            }else{
              rep(i, 5){
                int c = tmp1[i] - 'a';
                int d = tmp1[i + 1] - 'a';
                int e = tmp2[i] - 'a';
                int f = tmp2[i + 1] - 'a';
                if (ng[c][d]){
                  ok4 = false;
                  break;
                }
                if(ng[e][f]){
                  ok4 = false;
                  break;
                }
              }
            }
            if(!ok4){
              continue;
            }else{
              s = a;
              t = b;
              return true;
            }
          }
        } while (next_permutation(ALL(B)));
      } while (next_permutation(ALL(A)));
    }
    return false;
  };
  auto build2 = []()-> vector<int> {
    vector<int> D(3);
    rep(i, 3)D[i] = i;
    do{
      bool ok = true;
      rep(i, 2){
        if(ng[D[i]][D[i+1]]){
          ok = false;
          break;
        }
      }
      if(ok){
        break;
      }else{
        continue;
      }
    }while(next_permutation(ALL(D)));
    return D;
  };
  string res1 = "";
  string res2 = "";
  if(build(n, res1, res2)){
    cout << "YES" << endl;
    rep(i, n){
      if(i % 2 == 0){
        cout << res1;
      }else{
        cout << res2;
      }
    }
    cout << endl;
  }
  else{
    vector<int> D = build2();
    cout << "YES" << endl;
    rep(i, 3){
      cout << string(n, char(D[i] + 'a'));
    }
    cout << endl;
  }
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  int t = 1;
  while(t--) solve();
}