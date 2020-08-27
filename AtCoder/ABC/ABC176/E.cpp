#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
  int h, w, m;
  cin >> h >> w >> m;
  map<int, int> hm, wm;
  set<P> st;
  rep(i, m){
    int a, b;
    cin >> a >> b;
    hm[a]++;
    wm[b]++;
    st.insert({a, b});
  }
  int hmax = 0, wmax = 0;
  vector<int> hm_candidate, wm_candidate;
  for(auto k : hm){
    if(k.second > hmax) hmax = k.second;
  }
  for(auto k : wm){
    if(k.second > wmax) wmax = k.second;
  }
  for(auto k : hm){
    if(k.second == hmax) hm_candidate.emplace_back(k.first);
  }
  for(auto k : wm){
    if(k.second == wmax) wm_candidate.emplace_back(k.first);
  }
  rep(i, hm_candidate.size()){
    rep(j, wm_candidate.size()){
      if(st.find({hm_candidate[i], wm_candidate[j]}) == st.end()){
        cout << hmax + wmax << "\n";
        return 0;
      }
    }
  }
  cout << hmax + wmax - 1<< "\n";
}