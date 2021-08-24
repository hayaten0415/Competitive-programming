#pragma region Macros
// #pragma GCC target("avx2")
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
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
const auto INF = numeric_limits<T>::max()/2;

template< typename SemiGroup, typename F >
struct SlidingWindowAggregation {

  struct Node {
    SemiGroup val, sum;

    Node(const SemiGroup &val, const SemiGroup &sum) : val(val), sum(sum) {}
  };

  SlidingWindowAggregation(F f) : f(f) {}


  const F f;
  stack< Node > front, back;

  bool empty() const {
    return front.empty() && back.empty();
  }

  size_t size() const {
    return front.size() + back.size();
  }

  SemiGroup fold_all() const {
    if(front.empty()) {
      return back.top().sum;
    } else if(back.empty()) {
      return front.top().sum;
    } else {
      return f(front.top().sum, back.top().sum);
    }
  }

  void push(const SemiGroup &x) {
    if(back.empty()) {
      back.emplace(x, x);
    } else {
      back.emplace(x, f(back.top().sum, x));
    }
  }

  void pop() {
    if(front.empty()) {
      front.emplace(back.top().val, back.top().val);
      back.pop();
      while(!back.empty()) {
        front.emplace(back.top().val, f(back.top().val, front.top().sum));
        back.pop();
      }
    }
    front.pop();
  }
};


template< typename T, typename F >
SlidingWindowAggregation< T, F > get_sliding_window_aggregation(F f) {
  return SlidingWindowAggregation< T, F >(f);
}

// verify https://onlinejudge.u-aizu.ac.jp/problems/DSL_3_D

int main() {
  int n, l;
  cin >> n >> l;
  vector<int> A(n);
  rep(i, n) cin >> A[i];
  auto f = [](int a, int b) { return min(a, b); };
  auto SWAG = get_sliding_window_aggregation<int>(f);
  for(int i = 0; i < l - 1; i++) SWAG.push(A[i]);
  vector< int > ans;
  for(int i = l - 1; i < n; i++) {
    SWAG.push(A[i]);
    ans.emplace_back(SWAG.fold_all());
    SWAG.pop();
  }
  int c = ans.size();
  rep(i, c){
    cout << ans[i] << (i == c - 1 ? "\n" : " ");
  }
}