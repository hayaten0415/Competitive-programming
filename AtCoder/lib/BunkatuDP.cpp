#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <atcoder/all>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <typename T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
struct __INIT{__INIT(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(15);}} __init;
#define rep(i, n) for (long long i = 0; i < (n); i++)
#define rrep(i, n) for (long long i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
#define endl "\n"
#define fi first
#define se second
#define popcount(bit) __builtin_popcount(bit)
#define popcountll(bit) __builtin_popcountll(bit)
#define pb push_back
#define eb emplace_back
using namespace atcoder;
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
const auto INF = numeric_limits<T>::max()/2;
using mint = modint1000000007;
mint dp[1007][1007];

void init(){
  rep(i, 1007)rep(j, 1007){
    if(i == 0 || j == 0){
      dp[i][j] = 1;
      continue;
    }
    if(i == 1 || j == 1){
      dp[i][j] = 1;
      continue;
    }
    if(j - i >= 0){
      dp[i][j] += dp[i][j - i];
    }
    dp[i][j] += dp[i-1][j];
  }
}

// Reference https://atcoder.jp/contests/arc057/submissions/2891684

vector<vector<int>> _partition_dfs(vector<int> &now, int num){
    int rem = num - accumulate(now.begin(), now.end(), 0);
    if (!now.empty()) rem = min(rem, now.back());
 
    vector<vector<int> > ans{now};
    now.push_back(0);
    for (int j=1; j<=rem; j++){
        now.back() = j;
        vector<vector<int> > tmp = _partition_dfs(now, num);
        ans.insert(ans.end(), tmp.begin(), tmp.end());
    }
    now.pop_back();
    return ans;
}
// num以下の分割を具体的に列挙する（昇順、各分割内は降順）
vector<vector<int> > partitions(int num){
    vector<int> d;
    return _partition_dfs(d, num);
}



int main() {
  int n, m;
  cin >> n >> m;
  init();
}