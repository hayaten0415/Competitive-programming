#include <bits/stdc++.h>
#include <atcoder/dsu>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace atcoder;
using namespace std;
using P = pair<int, int>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

bool judge(string s, string t){
  if(s.size() != t.size()){
    return s.size() < t.size();
  }else {
    return s < t;
  }
}

int string_toint(string k){
  int n = k.size();
  reverse(ALL(k));
  int ten = 1;
  int res = 0;
  rep(i, n){
    res += ten * (k[i] - '0');
    ten *= 10;
  }
  return res;
}

int string_toint_modk(string k, int mod){
  int n = k.size();
  reverse(ALL(k));
  int ten = 1;
  int res = 0;
  rep(i, n){
    res += ten * (k[i] - '0');
    ten *= 10;
    ten %= mod;
    res %= mod;
  }
  return res;
}

int main() {
  int n, a;
  cin >> n >> a;
  a--;
  string k;
  cin >> k;
  vector<int> B(n);
  rep(i, n){
    cin >> B[i];
    B[i]--;
  }
  dsu d(n);
  map<int, int> mp;
  deque<int> loop;
  loop.emplace_back(B[a]);
  int pre = B[a];
  mp[pre] = 0;
  int now = B[pre];
  int s = 1;
  int loop_num = -1;
  while(s < n){
    if(d.same(pre, now)){
      loop_num= now;
      break;
    }
    d.merge(pre, now);
    mp[now] = s;
    loop.emplace_back(now);
    pre = now;
    now = B[now];
    s++;
  }
  int pre_loopnum = mp[loop_num];
  string t = to_string(pre_loopnum);
  //ループに入る前によりもkが小さければ出力
  if(!judge(t, k)){
    int ans = string_toint(k);
    cout << loop[ans-1] + 1 << endl;
    return 0;
  }
  //ループに関係ない部分を削除
  rep(i, pre_loopnum)loop.pop_front();
  int e = loop.back();
  loop.pop_back();
  loop.push_front(e);
  int f = loop.size();
  int ans = string_toint_modk(k, f);
  ans -= pre_loopnum;
  if(ans < 0){
    int p = (abs(ans) + f -1) / f;
    ans += f * p;
  }
  ans %= f;
  cout << loop[ans] + 1 << endl;
}