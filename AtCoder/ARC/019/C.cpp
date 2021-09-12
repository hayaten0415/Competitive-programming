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
const auto INF = numeric_limits<T>::max()/10;

int main() {
  ll h, w, k;
  cin >> h >> w >> k;
  auto dp_village = vector<vector<ll>>(h * w, vector<ll>(k + 1, INF<ll>));
  auto dp_maou = vector<vector<ll>>(h * w, vector<ll>(k + 1, INF<ll>));
  auto dp_hokora = vector<vector<ll>>(h * w, vector<ll>(k + 1, INF<ll>));

  vector<string> s(h);
  ll st, ed, lct;
  vector<ll> teki;
  rep(i,h){
      cin >> s[i];
    rep(j,w){
      if(s[i][j]=='S')st = i*w+j;
      if(s[i][j]=='G')ed = i*w+j;
      if(s[i][j]=='C')lct = i*w+j;
      if(s[i][j]=='E')teki.push_back(i*w+j);
    }
  }
  deque<tuple<ll, ll, ll>> dq;
  dq.eb(0, 0, st);
  dp_village[st][0] = 0;
  while(dq.size()){
      auto[cost,cnt,cur] = dq.front();dq.pop_front();
      if(dp_village[cur][cnt] < cost)continue;
      ll x = cur/w, y = cur%w;
      rep(i,4){
        ll nx = x+ dx[i];
        ll ny = y+ dy[i];
        if(nx<0||nx>=h||ny<0||ny>=w||s[nx][ny]=='T')continue;
        ll next = nx*w+ny;
        if(s[nx][ny]=='E'){
          if(cnt==k)continue;
          if(chmin(dp_village[next][cnt+1],cost+1)){
            dq.emplace_back(cost+1,cnt+1,next);
          }
        }else{
          if(chmin(dp_village[next][cnt],cost+1)){
            dq.emplace_back(cost+1,cnt,next);
          }
        }
      }
    }
 
    dq.emplace_back(0,0,ed);
    dp_maou[ed][0] = 0;
    while(dq.size()){
      auto[cost,cnt,cur] = dq.front();dq.pop_front();
      if(dp_maou[cur][cnt] < cost)continue;
      ll x = cur/w, y = cur%w;
      rep(i,4){
        ll nx = x+ dx[i];
        ll ny = y+ dy[i];
        if(nx<0||nx>=h||ny<0||ny>=w||s[nx][ny]=='T')continue;
        ll next = nx*w+ny;
        if(s[nx][ny]=='E'){
          if(cnt==k)continue;
          if(chmin(dp_maou[next][cnt+1],cost+1)){
            dq.emplace_back(cost+1,cnt+1,next);
          }
        }else{
          if(chmin(dp_maou[next][cnt],cost+1)){
            dq.emplace_back(cost+1,cnt,next);
          }
        }
      }
    }
 
    dq.emplace_back(0,0,lct);
    dp_hokora[lct][0] = 0;
    while(dq.size()){
      auto[cost,cnt,cur] = dq.front();dq.pop_front();
      if(dp_hokora[cur][cnt] < cost)continue;
      ll x = cur/w, y = cur%w;
      rep(i,4){
        ll nx = x+ dx[i];
        ll ny = y+ dy[i];
        if(nx<0||nx>=h||ny<0||ny>=w||s[nx][ny]=='T')continue;
        ll next = nx*w+ny;
        if(s[nx][ny]=='E'){
          if(cnt==k)continue;
          if(chmin(dp_hokora[next][cnt+1],cost+1)){
            dq.emplace_back(cost+1,cnt+1,next);
          }
        }else{
          if(chmin(dp_hokora[next][cnt],cost+1)){
            dq.emplace_back(cost+1,cnt,next);
          }
        }
      }
    }
 
    rep(i,h*w){
      rep(j,k){
        chmin(dp_village[i][j+1],dp_village[i][j]);
      }
    }
 
    ll ans = INF<ll>;
 
    rep(j,k+1){
      chmin(ans,dp_maou[lct][j]+dp_village[lct][k-j]);
    }
 
    for(auto e:teki){
    rep(i,k+1){
      rep(j,min(k+1,k+3-i)){
        chmin(ans,dp_hokora[e][i]*2+dp_maou[e][j]+dp_village[e][min(k,k+2-i-j)]);
      }
    }
    }
 
    if(ans>=INF<ll>)ans=-1;
 
    cout << ans << endl;
}