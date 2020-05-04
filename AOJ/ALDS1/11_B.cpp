#define rep(i, n) for (int i = 0; i < (n); i++)
#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

vector<bool> visited;
vector<int> first_order;
vector<int> last_order;

//行き掛け順と帰りかけ順
void dfs(Graph &G, int v, int& first_ptr, int& last_ptr) {
  first_order[v] = first_ptr++;
  visited[v] = true;

  for(auto next_v : G[v]) {
    if(visited[next_v]) continue;
    dfs(G, next_v, first_ptr, last_ptr);
  }
  last_order[v] = last_ptr++;
}

//タイムスタンプ
void dfs(Graph &G, int v, int& ptr) {
  first_order[v] = ptr++;
  visited[v] = true;

  for(auto next_v : G[v]) {
    if(visited[next_v]) continue;
    dfs(G, next_v, ptr);
  }
  last_order[v] = ptr++;
}

int main() {
  int n;
  cin >> n;
  Graph G(n);
  rep(i,n) {
    int num, degree;
    cin >> num >> degree;
    num--;
    rep(j,degree){
      int b;
      cin >> b;
      b--;
      G[num].push_back(b);
    }
  }
  visited.assign(n, false);
  first_order.resize(n);
  last_order.resize(n);
  int ptr = 1;
  dfs(G, 0, ptr);
  for (int v = 0; v < n; v++){
    cout << v + 1 << " " << first_order[v] << " " << last_order[v] << endl;
  }
}
