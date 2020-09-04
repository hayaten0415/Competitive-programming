#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rrep(i, n) for (int i = (n - 1); i >= 0; i--)
#define ALL(v) v.begin(), v.end()
using namespace std;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
  int n, m;
  cin >> n >> m;
  Graph G(n);
  vector<vector<int>> dist(n, vector<int>(3,-3));
  rep(i, m){
    int a, b;
    cin >> a >> b;
    a--, b--;
    G[a].emplace_back(b);
  }
  int s, t;
  cin >> s >> t;
  s--, t--;
	queue<P> que;
  dist[s][0] = 0;
  que.push(P(s, 0));
  while (!que.empty()){
  	P p = que.front();
		que.pop();
		int x = p.first;
		int ny = p.second;
		for(auto e : G[x]){
			int nt = (ny + 1) % 3;
			if(dist[e][nt] != -3)continue;
			dist[e][nt] = dist[x][ny] + 1;
			que.push(P(e, nt));
		}
  }
	cout << dist[t][0] / 3 << endl;
}
