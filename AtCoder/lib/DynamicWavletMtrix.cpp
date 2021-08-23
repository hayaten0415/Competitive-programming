#define MOD_TYPE 2

#pragma region Macros

#include <bits/stdc++.h>
using namespace std;

#if 1
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#endif

#if 0
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
template <typename T>
using extset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
#endif

#if 0
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
using Int = boost::multiprecision::cpp_int;
using lld = boost::multiprecision::cpp_dec_float_100;
#endif

using ll = long long int;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pld = pair<ld, ld>;
template <typename T>
using smaller_queue = priority_queue<T, vector<T>, greater<T>>;

constexpr ll MOD = (MOD_TYPE == 1 ? (ll)(1e9 + 7) : 998244353);
constexpr int INF = (int)1e9 + 10;
constexpr ll LINF = (ll)4e18;
constexpr ld PI = acos(-1.0);
constexpr ld EPS = 1e-7;
constexpr int Dx[] = {0, 0, -1, 1, -1, 1, -1, 1, 0};
constexpr int Dy[] = {1, -1, 0, 0, -1, -1, 1, 1, 0};

#define REP(i, m, n) for (ll i = m; i < (ll)(n); ++i)
#define rep(i, n) REP(i, 0, n)
#define REPI(i, m, n) for (int i = m; i < (int)(n); ++i)
#define repi(i, n) REPI(i, 0, n)
#define MP make_pair
#define MT make_tuple
#define YES(n) cout << ((n) ? "YES" : "NO") << "\n"
#define Yes(n) cout << ((n) ? "Yes" : "No") << "\n"
#define possible(n) cout << ((n) ? "possible" : "impossible") << "\n"
#define Possible(n) cout << ((n) ? "Possible" : "Impossible") << "\n"
#define all(v) v.begin(), v.end()
#define NP(v) next_permutation(all(v))
#define dbg(x) cerr << #x << ":" << x << "\n";

struct io_init
{
  io_init()
  {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << setprecision(30) << setiosflags(ios::fixed);
  };
} io_init;
template <typename T>
inline bool chmin(T &a, T b)
{
  if (a > b)
  {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
inline bool chmax(T &a, T b)
{
  if (a < b)
  {
    a = b;
    return true;
  }
  return false;
}
inline ll CEIL(ll a, ll b)
{
  return (a + b - 1) / b;
}
template <typename A, size_t N, typename T>
inline void Fill(A (&array)[N], const T &val)
{
  fill((T *)array, (T *)(array + N), val);
}
template <typename T, typename U>
constexpr istream &operator>>(istream &is, pair<T, U> &p) noexcept
{
  is >> p.first >> p.second;
  return is;
}
template <typename T, typename U>
constexpr ostream &operator<<(ostream &os, pair<T, U> &p) noexcept
{
  os << p.first << " " << p.second;
  return os;
}
#pragma endregion

// --------------------------------------

enum
{
  NOTFOUND = 0xFFFFFFFFFFFFFFFFLLU
};

uint64_t NODE_NO = 0;

class Node
{
public:
  uint64_t no; // node番号

  // internal nodeのときに使用
  uint64_t num;  // 左の子の部分木のもつbitの数
  uint64_t ones; // 左の子の部分木のもつ1の数
  Node *left;
  Node *right;
  int64_t balance; // 右の子の高さ - 左の子の高さ．+なら右の子の方が高い，-なら左の子の方が高い

  // leafのときに使用
  uint64_t bits;      // bit
  uint64_t bits_size; // bitのサイズ(debug用)

  bool is_leaf;

  Node(uint64_t bits, uint64_t bits_size, bool is_leaf) : no(NODE_NO++), num(0), ones(0), bits(bits), bits_size(bits_size), is_leaf(is_leaf), left(nullptr), right(nullptr), balance(0) {}
};

class DynamicBitVector
{
public:
  Node *root;
  uint64_t size;                       // 全体のbitの数
  uint64_t num_one;                    // 全体の1の数
  const uint64_t bits_size_limit = 32; // 各ノードが管理するbitの長さ制限．2 * bits_size_limit以上になったらノードを分割し， 1/2*bits_size_limit以下になったらノードを結合する

  DynamicBitVector() : root(nullptr), size(0), num_one(0) {}

  DynamicBitVector(std::vector<uint64_t> &v) : root(nullptr), size(0), num_one(0)
  {
    if (v.size() == 0)
    {
      return;
    }

    std::deque<std::pair<Node *, uint64_t>> leaves;
    for (int i = 0; i < v.size(); i += this->bits_size_limit)
    {
      uint64_t bits = 0;
      const uint64_t bits_size = std::min(this->bits_size_limit, (uint64_t)v.size() - i);
      for (int j = 0; j < bits_size; ++j)
      {
        assert(v[i + j] == 0 or v[i + j] == 1);
        if (v[i + j] == 1)
        {
          bits |= (uint64_t)1 << j;
        }
      }

      leaves.emplace_back(std::make_pair(new Node(bits, bits_size, true), bits_size));
    }

    std::deque<std::tuple<Node *, uint64_t, uint64_t, uint64_t>> nodes; // (node, 全体のbit数, 全体の1の数, 高さ)
    while (not leaves.empty())
    {
      const auto node = leaves.front().first;
      const auto bits_size = leaves.front().second;
      leaves.pop_front();
      nodes.emplace_back(std::make_tuple(node, bits_size, popCount(node->bits), 0));
    }

    while (nodes.size() > 1)
    {

      std::deque<std::tuple<Node *, uint64_t, uint64_t, uint64_t>> next_nodes;
      while (not nodes.empty())
      {
        // あまりがでたときは，最後に作った中間ノードと結合させるためにnodesに戻す
        if (nodes.size() == 1)
        {
          nodes.push_front(next_nodes.back());
          next_nodes.pop_back();
        }

        Node *left_node;
        uint64_t left_num, left_ones, left_height;
        std::tie(left_node, left_num, left_ones, left_height) = nodes.front();
        nodes.pop_front();

        Node *right_node;
        uint64_t right_num, right_ones, right_height;
        std::tie(right_node, right_num, right_ones, right_height) = nodes.front();
        nodes.pop_front();

        const auto internal_node = new Node(0, 0, false);
        internal_node->num = left_num;
        internal_node->ones = left_ones;
        internal_node->left = left_node;
        internal_node->right = right_node;
        internal_node->balance = right_height - left_height;

        next_nodes.emplace_back(std::make_tuple(internal_node, left_num + right_num, left_ones + right_ones, std::max(left_height, right_height) + 1));
      }

      nodes = next_nodes;
    }

    uint64_t height;
    std::tie(this->root, this->size, this->num_one, height) = nodes.front();
    nodes.pop_front();
    assert(this->size == v.size());
  }

  // B[pos]
  uint64_t access(uint64_t pos)
  {
    assert(pos < this->size);

    return access(this->root, pos);
  }

  // B[0, pos)にある指定されたbitの数
  uint64_t rank(uint64_t bit, uint64_t pos)
  {
    assert(bit == 0 or bit == 1);
    assert(pos <= this->size);

    if (bit)
    {
      return rank1(this->root, pos, 0);
    }
    else
    {
      return pos - rank1(this->root, pos, 0);
    }
  }

  // rank番目の指定されたbitの位置 + 1(rankは1-origin)
  uint64_t select(uint64_t bit, uint64_t rank)
  {
    assert(bit == 0 or bit == 1);
    assert(rank > 0);

    if (bit == 0 and rank > this->size - this->num_one)
    {
      return NOTFOUND;
    }
    if (bit == 1 and rank > this->num_one)
    {
      return NOTFOUND;
    }

    if (bit)
    {
      return select1(this->root, 0, rank);
    }
    else
    {
      return select0(this->root, 0, rank);
    }
  }

  // posにbitを挿入する
  void insert(uint64_t pos, uint64_t bit)
  {
    assert(bit == 0 or bit == 1);
    assert(pos <= this->size); // 現在もってるbitsの末尾には挿入できる

    if (root == nullptr)
    {
      root = new Node(bit, 1, true);
    }
    else
    {
      insert(this->root, nullptr, bit, pos, this->size);
    }
    this->size++;
    this->num_one += (bit == 1);
  }

  // posを削除する
  void erase(uint64_t pos)
  {
    assert(pos < this->size);

    uint64_t bit = this->remove(this->root, nullptr, pos, this->size, 0, true).first;
    this->size--;
    this->num_one -= (bit == 1);
  }

private:
  uint64_t access(const Node *node, uint64_t pos)
  {
    if (node->is_leaf)
    {
      assert(pos <= 2 * this->bits_size_limit);
      return (node->bits >> pos) & (uint64_t)1;
    }

    if (pos < node->num)
    {
      return this->access(node->left, pos);
    }
    else
    {
      return this->access(node->right, pos - node->num);
    }
  }

  uint64_t rank1(const Node *node, uint64_t pos, uint64_t ones)
  {
    if (node->is_leaf)
    {
      assert(node->bits_size >= pos);
      const uint64_t mask = ((uint64_t)1 << pos) - 1;
      return ones + popCount(node->bits & mask);
    }

    if (pos < node->num)
    {
      return this->rank1(node->left, pos, ones);
    }
    else
    {
      return this->rank1(node->right, pos - node->num, ones + node->ones);
    }
  }

  uint64_t select1(const Node *node, uint64_t pos, uint64_t rank)
  {
    if (node->is_leaf)
    {
      return pos + this->selectInBlock(node->bits, rank) + 1;
    }

    if (rank <= node->ones)
    {
      return this->select1(node->left, pos, rank);
    }
    else
    {
      return this->select1(node->right, pos + node->num, rank - node->ones);
    }
  }

  uint64_t select0(const Node *node, uint64_t pos, uint64_t rank)
  {
    if (node->is_leaf)
    {
      return pos + this->selectInBlock(~node->bits, rank) + 1;
    }

    if (rank <= (node->num - node->ones))
    {
      return this->select0(node->left, pos, rank);
    }
    else
    {
      return this->select0(node->right, pos + node->num, rank - (node->num - node->ones));
    }
  }

  // bits(64bit)のrank番目(0-index)の1の数
  uint64_t selectInBlock(uint64_t bits, uint64_t rank)
  {
    const uint64_t x1 = bits - ((bits & 0xAAAAAAAAAAAAAAAALLU) >> (uint64_t)1);
    const uint64_t x2 = (x1 & 0x3333333333333333LLU) + ((x1 >> (uint64_t)2) & 0x3333333333333333LLU);
    const uint64_t x3 = (x2 + (x2 >> (uint64_t)4)) & 0x0F0F0F0F0F0F0F0FLLU;

    uint64_t pos = 0;
    for (;; pos += 8)
    {
      const uint64_t rank_next = (x3 >> pos) & 0xFFLLU;
      if (rank <= rank_next)
        break;
      rank -= rank_next;
    }

    const uint64_t v2 = (x2 >> pos) & 0xFLLU;
    if (rank > v2)
    {
      rank -= v2;
      pos += 4;
    }

    const uint64_t v1 = (x1 >> pos) & 0x3LLU;
    if (rank > v1)
    {
      rank -= v1;
      pos += 2;
    }

    const uint64_t v0 = (bits >> pos) & 0x1LLU;
    if (v0 < rank)
    {
      pos += 1;
    }

    return pos;
  }

  // nodeから辿れる葉のpos番目にbitをいれる(葉のbitの長さはlen)
  // 高さの変化を返す
  int64_t insert(Node *node, Node *parent, uint64_t bit, uint64_t pos, uint64_t len)
  {
    assert(bit == 0 or bit == 1);
    if (node->is_leaf)
    {
      assert(pos <= 2 * this->bits_size_limit);

      // posより左をとりだす
      const uint64_t up_mask = (((uint64_t)1 << (len - pos)) - 1) << pos;
      const uint64_t up = (node->bits & up_mask);

      // posより右をとりだす
      const uint64_t down_mask = ((uint64_t)1 << pos) - 1;
      const uint64_t down = node->bits & down_mask;

      node->bits = (up << (uint64_t)1) | (bit << pos) | down;
      node->bits_size++;
      assert(node->bits_size == len + 1);

      // bitsのサイズが大きくなったので分割する
      if (len + 1 >= 2 * bits_size_limit)
      {
        this->splitNode(node, len + 1); // 引数のlenはinsert後の長さなので+1する
        return 1;
      }

      return 0;
    }

    if (pos < node->num)
    {
      const int64_t diff = this->insert(node->left, node, bit, pos, node->num);
      node->num += 1;
      node->ones += (bit == 1);
      return achieveBalance(parent, node, diff, 0);
    }
    else
    {
      const int64_t diff = this->insert(node->right, node, bit, pos - node->num, len - node->num);
      return achieveBalance(parent, node, 0, diff);
    }
  }

  // nodeのpos番目のbitを削除する
  // 消したbitと高さの変化のpairを返す
  std::pair<uint64_t, int64_t> remove(Node *node, Node *parent, uint64_t pos, uint64_t len, uint64_t ones, bool allow_under_flow)
  {
    if (node->is_leaf)
    {
      // 消すとunder flowになるので消さない
      if (node != this->root and len <= bits_size_limit / 2 and not allow_under_flow)
      {
        return std::make_pair(NOTFOUND, 0);
      }

      assert(pos <= 2 * this->bits_size_limit);
      assert(pos < len);
      const uint64_t bit = (node->bits >> pos) & (uint64_t)1;

      // posより左をとりだす(posを含まないようにする)
      const uint64_t up_mask = (((uint64_t)1 << (len - pos - 1)) - 1) << (pos + 1);
      const uint64_t up = (node->bits & up_mask);

      // posより右をとりだす
      const uint64_t down_mask = ((uint64_t)1 << pos) - 1;
      const uint64_t down = node->bits & down_mask;

      node->bits = (up >> (uint64_t)1) | down;
      node->bits_size--;
      assert(node->bits_size == len - 1);

      return std::make_pair(bit, 0);
    }

    if (pos < node->num)
    {
      const auto bit_diff = this->remove(node->left, node, pos, node->num, node->ones, allow_under_flow);
      if (bit_diff.first == NOTFOUND)
      {
        return bit_diff;
      }

      node->ones -= (bit_diff.first == 1);
      // 左の子の葉のbitを1つ消したのでunder flowが発生している
      if (node->num == bits_size_limit / 2)
      {
        const auto b_d = remove(node->right, node, 0, len - bits_size_limit / 2, 0, false); // 右の葉の先頭bitを削る

        // 右の葉もunder flowになって消せない場合は2つの葉を統合する
        if (b_d.first == NOTFOUND)
        {
          assert(node->left->is_leaf);
          assert(node->left->bits_size == bits_size_limit / 2 - 1);
          // 右の子から辿れる一番左の葉の先頭にleftのbitsを追加する
          mergeNodes(node->right, 0, len - bits_size_limit / 2, node->left->bits, bits_size_limit / 2 - 1, node->ones, true);
          this->replace(parent, node, node->right); // parentの子のnodeをnode->rightに置き換える
          return std::make_pair(bit_diff.first, -1);
        }

        // 右の葉からとった先頭bitを左の葉の末尾にいれる
        assert(node->left->bits_size == bits_size_limit / 2 - 1);
        insert(node->left, node, b_d.first, bits_size_limit / 2 - 1, bits_size_limit / 2 - 1);
        node->ones += (b_d.first == 1);
      }
      else
      {
        node->num -= 1;
      }

      const int64_t diff = achieveBalance(parent, node, bit_diff.second, 0);
      return std::make_pair(bit_diff.first, diff);
    }
    else
    {
      const auto bit_diff = this->remove(node->right, node, pos - node->num, len - node->num, ones - node->ones, allow_under_flow);
      if (bit_diff.first == NOTFOUND)
      {
        return bit_diff;
      }

      ones -= (bit_diff.first == 1);
      // 右の子の葉のbitを1つ消したのでunder flowが発生する
      if ((len - node->num) == bits_size_limit / 2)
      {
        const auto b_d = remove(node->left, node, node->num - 1, node->num, 0, false); // 左の葉の末尾をbitを削る

        // 左の葉もunder flowになって消せない場合は2つの葉を統合する
        if (b_d.first == NOTFOUND)
        {
          assert(node->right->is_leaf);
          assert(node->right->bits_size == bits_size_limit / 2 - 1);
          // 左の子から辿れる一番右の葉の末尾にleftのbitsを追加する
          mergeNodes(node->left, node->num, node->num, node->right->bits, bits_size_limit / 2 - 1, ones - node->ones, false);
          this->replace(parent, node, node->left); // parentの子のnodeをnode->leftに置き換える
          return std::make_pair(bit_diff.first, -1);
        }

        // 左の葉からとった最後尾bitを右の葉の先頭にいれる
        insert(node->right, node, b_d.first, 0, bits_size_limit / 2 - 1);
        node->num -= 1;
        node->ones -= (b_d.first == 1);
      }

      const int64_t diff = achieveBalance(parent, node, 0, bit_diff.second);
      return std::make_pair(bit_diff.first, diff);
    }
  }

  // nodeを2つの葉に分割する
  void splitNode(Node *node, uint64_t len)
  {
    assert(node->is_leaf);
    assert(node->bits_size == len);

    // 左の葉
    const uint64_t left_size = len / 2;
    const uint64_t left_bits = node->bits & (((uint64_t)1 << left_size) - 1);
    node->left = new Node(left_bits, left_size, true);

    // 右の葉
    const uint64_t right_size = len - left_size;
    const uint64_t right_bits = node->bits >> left_size;
    node->right = new Node(right_bits, right_size, true);

    // nodeを内部ノードにする
    node->is_leaf = false;
    node->num = left_size;
    node->ones = this->popCount(left_bits);
    node->bits = 0;
    node->bits_size = 0;
  }

  // nodeから辿れる葉のpos番目にbitsを格納する
  void mergeNodes(Node *node, uint64_t pos, uint64_t len, uint64_t bits, uint64_t s, uint64_t ones, bool left)
  {
    if (node->is_leaf)
    {
      if (left)
      {
        node->bits = (node->bits << s) | bits;
      }
      else
      {
        assert(len == node->bits_size);
        node->bits = node->bits | (bits << len);
      }
      node->bits_size += s;
      return;
    }

    if (pos < node->num)
    {
      node->num += s;
      node->ones += ones;
      mergeNodes(node->left, pos, node->num, bits, s, ones, left);
    }
    else
    {
      mergeNodes(node->right, pos, len - node->num, bits, s, ones, left);
    }
  }

  // nodeの左の高さがleftHeightDiffだけ変わり，右の高さがrightHeightDiffだけ変わったときにnodeを中心に回転させる
  // 高さの変化を返す
  int64_t achieveBalance(Node *parent, Node *node, int64_t leftHeightDiff, int64_t rightHeightDiff)
  {
    assert(-1 <= node->balance and node->balance <= 1);
    assert(-1 <= leftHeightDiff and leftHeightDiff <= 1);
    assert(-1 <= rightHeightDiff and rightHeightDiff <= 1);

    if (leftHeightDiff == 0 and rightHeightDiff == 0)
    {
      return 0;
    }

    int64_t heightDiff = 0;
    // 左が高いときに，左が高くなる or 右が高いときに右が高くなる
    if ((node->balance <= 0 and leftHeightDiff > 0) or (node->balance >= 0 and rightHeightDiff > 0))
    {
      ++heightDiff;
    }
    // 左が高いときに左が低くなる or 右が高いときに右が低くなる
    if ((node->balance < 0 and leftHeightDiff < 0) or (node->balance > 0 and rightHeightDiff < 0))
    {
      --heightDiff;
    }

    node->balance += -leftHeightDiff + rightHeightDiff;
    assert(-2 <= node->balance and node->balance <= 2);

    // 左が2高い
    if (node->balance == -2)
    {
      assert(-1 <= node->left->balance and node->left->balance <= 1);
      if (node->left->balance != 0)
      {
        heightDiff--;
      }

      if (node->left->balance == 1)
      {
        replace(node, node->left, rotateLeft(node->left));
      }
      replace(parent, node, rotateRight(node));
    }
    // 右が2高い
    else if (node->balance == 2)
    {
      assert(-1 <= node->right->balance and node->right->balance <= 1);
      if (node->right->balance != 0)
      {
        heightDiff--;
      }

      if (node->right->balance == -1)
      {
        replace(node, node->right, rotateRight(node->right));
      }
      replace(parent, node, rotateLeft(node));
    }

    return heightDiff;
  }

  // node Bを中心に左回転する．新しい親を返す
  Node *rotateLeft(Node *B)
  {
    Node *D = B->right;

    const int64_t heightC = 0;
    const int64_t heightE = heightC + D->balance;
    const int64_t heightA = std::max(heightC, heightE) + 1 - B->balance;

    B->right = D->left;
    D->left = B;

    B->balance = heightC - heightA;
    D->num += B->num;
    D->ones += B->ones;
    D->balance = heightE - (std::max(heightA, heightC) + 1);

    assert(-2 <= B->balance and B->balance <= 2);
    assert(-2 <= D->balance and D->balance <= 2);

    return D;
  }

  // node Dを中心に右回転する．新しい親を返す
  Node *rotateRight(Node *D)
  {
    Node *B = D->left;

    const int64_t heightC = 0;
    const int64_t heightA = heightC - B->balance;
    const int64_t heightE = std::max(heightA, heightC) + 1 + D->balance;

    D->left = B->right;
    B->right = D;

    D->num -= B->num;
    D->ones -= B->ones;
    D->balance = heightE - heightC;
    B->balance = std::max(heightC, heightE) + 1 - heightA;

    assert(-2 <= B->balance and B->balance <= 2);
    assert(-2 <= D->balance and D->balance <= 2);

    return B;
  }

  // parentの子のoldNodeをnewNodeに置き換える
  void replace(Node *parent, Node *oldNode, Node *newNode)
  {
    if (parent == nullptr)
    {
      this->root = newNode;
      return;
    }

    if (parent->left == oldNode)
    {
      parent->left = newNode;
    }
    else if (parent->right == oldNode)
    {
      parent->right = newNode;
    }
    else
    {
      throw "old node is not child";
    }
  }

  uint64_t popCount(uint64_t x)
  {
    x = (x & 0x5555555555555555ULL) + ((x >> (uint64_t)1) & 0x5555555555555555ULL);
    x = (x & 0x3333333333333333ULL) + ((x >> (uint64_t)2) & 0x3333333333333333ULL);
    x = (x + (x >> (uint64_t)4)) & 0x0f0f0f0f0f0f0f0fULL;
    x = x + (x >> (uint64_t)8);
    x = x + (x >> (uint64_t)16);
    x = x + (x >> (uint64_t)32);
    return x & 0x7FLLU;
  }
};

class DynamicWaveletMatrix
{
public:
  std::vector<DynamicBitVector> bit_arrays;
  std::vector<uint64_t> begin_one; // 各bitの1の開始位置

  uint64_t size;            // 与えられた配列のサイズ
  uint64_t maximum_element; // 最大の文字
  uint64_t bit_size;        // 文字を表すのに必要なbit数

public:
  // max_element: 入ってくる中で一番大きい数値
  DynamicWaveletMatrix(uint64_t maximum_element) : size(0), maximum_element(maximum_element + 1)
  {
    this->bit_size = this->get_num_of_bit(maximum_element);
    if (bit_size == 0)
    {
      bit_size = 1;
    }
    this->begin_one.resize(bit_size);

    for (uint64_t i = 0; i < bit_size; ++i)
    {
      DynamicBitVector sv;
      bit_arrays.push_back(sv);
    }
  }

  DynamicWaveletMatrix(uint64_t num_of_alphabet, const std::vector<uint64_t> &array) : size(0), maximum_element(num_of_alphabet + 1)
  {
    this->bit_size = this->get_num_of_bit(num_of_alphabet);
    if (bit_size == 0)
    {
      bit_size = 1;
    }
    this->begin_one.resize(bit_size);

    if (array.size() == 0)
    {
      for (uint64_t i = 0; i < bit_size; ++i)
      {
        DynamicBitVector sv;
        bit_arrays.push_back(sv);
      }
      return;
    }

    size = array.size();

    std::vector<uint64_t> v(array), b(array.size(), 0);

    for (uint64_t i = 0; i < bit_size; ++i)
    {

      std::vector<uint64_t> temp;
      // 0をtempにいれてく
      for (uint64_t j = 0; j < v.size(); ++j)
      {
        uint64_t c = v.at(j);
        uint64_t bit = (c >> (bit_size - i - 1)) & 1; //　上からi番目のbit
        if (bit == 0)
        {
          temp.push_back(c);
          b[j] = 0;
        }
      }

      this->begin_one.at(i) = temp.size();

      // 1をtempにいれてく
      for (uint64_t j = 0; j < v.size(); ++j)
      {
        uint64_t c = v.at(j);
        uint64_t bit = (c >> (bit_size - i - 1)) & 1; //　上からi番目のbit
        if (bit == 1)
        {
          temp.push_back(c);
          b[j] = 1;
        }
      }

      DynamicBitVector dbv(b);
      bit_arrays.emplace_back(dbv);
      v = temp;
    }
  }

  // v[pos]
  uint64_t access(uint64_t pos)
  {
    if (pos >= this->size)
    {
      return NOTFOUND;
    }

    uint64_t c = 0;
    for (uint64_t i = 0; i < bit_arrays.size(); ++i)
    {
      uint64_t bit = bit_arrays.at(i).access(pos); // もとの数値がのi番目のbit
      c = (c <<= 1) | bit;
      pos = bit_arrays.at(i).rank(bit, pos);
      if (bit)
      {
        pos += this->begin_one.at(i);
      }
    }
    return c;
  }

  // i番目のcの位置 + 1を返す。rankは1-origin
  uint64_t select(uint64_t c, uint64_t rank)
  {
    assert(rank > 0);
    if (c >= maximum_element)
    {
      return NOTFOUND;
    }

    uint64_t left = 0;
    for (uint64_t i = 0; i < bit_size; ++i)
    {
      const uint64_t bit = (c >> (bit_size - i - 1)) & 1; // 上からi番目のbit
      left = bit_arrays.at(i).rank(bit, left);            // cのi番目のbitと同じ数値の数
      if (bit)
      {
        left += this->begin_one.at(i);
      }
    }

    uint64_t index = left + rank;
    for (uint64_t i = 0; i < bit_arrays.size(); ++i)
    {
      uint64_t bit = ((c >> i) & 1); // 下からi番目のbit
      if (bit == 1)
      {
        index -= this->begin_one.at(bit_size - i - 1);
      }
      index = this->bit_arrays.at(bit_size - i - 1).select(bit, index);
    }
    return index;
  }

  // posにcを挿入する
  void insert(uint64_t pos, uint64_t c)
  {
    assert(pos <= this->size);

    for (uint64_t i = 0; i < bit_arrays.size(); ++i)
    {
      const uint64_t bit = (c >> (bit_size - i - 1)) & 1; //　上からi番目のbit
      bit_arrays.at(i).insert(pos, bit);
      pos = bit_arrays.at(i).rank(bit, pos);
      if (bit)
      {
        pos += this->begin_one.at(i);
      }
      else
      {
        this->begin_one.at(i)++;
      }
    }

    this->size++;
  }

  // posを削除する
  void erase(uint64_t pos)
  {
    assert(pos < this->size);
    if (pos >= this->size)
    {
      throw "Segmentation fault";
    }

    for (uint64_t i = 0; i < bit_arrays.size(); ++i)
    {
      uint64_t bit = bit_arrays.at(i).access(pos); // もとの数値のi番目のbit

      auto next_pos = bit_arrays.at(i).rank(bit, pos);
      bit_arrays.at(i).erase(pos);

      if (bit)
      {
        next_pos += this->begin_one.at(i);
      }
      else
      {
        this->begin_one.at(i)--;
      }
      pos = next_pos;
    }
    this->size--;
  }

  // posにcをセットする
  void update(uint64_t pos, uint64_t c)
  {
    assert(pos < this->size);
    this->erase(pos);
    this->insert(pos, c);
  }

  // v[begin_pos, end_pos)で最小値のindexを返す
  uint64_t minRange(uint64_t begin_pos, uint64_t end_pos)
  {
    return quantileRange(begin_pos, end_pos, 0);
  }

  // v[begin_pos, end_pos)でk番目に小さい数値のindexを返す(kは0-origin)
  // つまり小さい順に並べてk番目の値
  uint64_t quantileRange(uint64_t begin_pos, uint64_t end_pos, uint64_t k)
  {
    if ((end_pos > size || begin_pos >= end_pos) || (k >= end_pos - begin_pos))
    {
      return NOTFOUND;
    }

    uint64_t val = 0;
    for (uint64_t i = 0; i < bit_size; ++i)
    {
      uint64_t num_of_zero_begin = bit_arrays.at(i).rank(0, begin_pos);
      uint64_t num_of_zero_end = bit_arrays.at(i).rank(0, end_pos);
      uint64_t num_of_zero = num_of_zero_end - num_of_zero_begin; // beginからendまでにある0の数
      uint64_t bit = (k < num_of_zero) ? 0 : 1;                   // k番目の値の上からi番目のbitが0か1か

      if (bit)
      {
        k -= num_of_zero;
        begin_pos = this->begin_one.at(i) + begin_pos - num_of_zero_begin;
        end_pos = this->begin_one.at(i) + end_pos - num_of_zero_end;
      }
      else
      {
        begin_pos = num_of_zero_begin;
        end_pos = num_of_zero_begin + num_of_zero;
      }

      val = ((val << 1) | bit);
    }

    uint64_t left = 0;
    for (uint64_t i = 0; i < bit_size; ++i)
    {
      const uint64_t bit = (val >> (bit_size - i - 1)) & 1; // 上からi番目のbit
      left = bit_arrays.at(i).rank(bit, left);              // cのi番目のbitと同じ数値の数
      if (bit)
      {
        left += this->begin_one.at(i);
      }
    }

    uint64_t rank = begin_pos + k - left + 1;
    return select(val, rank) - 1;
  }

private:
  uint64_t get_num_of_bit(uint64_t x)
  {
    if (x == 0)
      return 0;
    x--;
    uint64_t bit_num = 0;
    while (x >> bit_num)
    {
      ++bit_num;
    }
    return bit_num;
  }
};

/*
DynamicWaveletMatrix(uint64_t maximum_element)
入りうる一番大きい値を渡す(INT_MAX等)

DynamicWaveletMatrix(uint64_t num_of_alphabet, const vector<uint64_t> &array)
num_of_alphabet: 要素の最大値（上に同じ）

uint64_t access(uint64_t pos)
v[pos]

uint64_t select(uint64_t c, uint64_t rank)
i 番目の c の位置 +1 を返す。rank は 1-origin

void insert(uint64_t pos, uint64_t c)
posにcを挿入する

push_back(uint64_t c)
末尾にcを追加する

void erase(uint64_t pos)
posを削除する

void update(uint64_t pos, uint64_t c)
posにcをセットする

uint64_t maxRange(uint64_t begin_pos, uint64_t end_pos)
v[begin_pos, end_pos)で最大値のindexを返す

uint64_t minRange(uint64_t begin_pos, uint64_t end_pos)
v[begin_pos, end_pos)で最小値のindexを返す

uint64_t quantileRange(uint64_t begin_pos, uint64_t end_pos, uint64_t k)
v[begin_pos, end_pos)でk番目に小さい数値のindexを返す (kは0-origin)
つまり小さい順に並べてk番目の値

void rankAll(uint64_t c, uint64_t begin_pos, uint64_t end_pos, uint64_t &rank, uint64_t &rank_less_than, uint64_t &rank_more_than)
v[begin_pos, end_pos)でcと同じ値の数、cより小さい値の数、cより大きい値の数を求める

vector<pair<uint64_t, uint64_t>> topk(uint64_t s, uint64_t e, uint64_t k)
T[s1, e1)で出現回数が多い順にk個の値を返す

vector<tuple<uint64_t, uint64_t, uint64_t>> intersect(uint64_t _s1, uint64_t _e1, uint64_t _s2, uint64_t _e2)
T[s1, e1)とT[s2, e2)に共通して出現する要素を求める
*/

//verify https://mojacoder.app/users/someone/problems/rangesortquery
void solve(){
  int n, q;
  cin >> n >> q;
  vector<uint64_t> a(n);
  rep(i, n) cin >> a[i];
  DynamicWaveletMatrix wm(INT_MAX, a);
  rep(qi, q){
    int t;
    cin >> t;
    if (t == 1){
      int i, x;
      cin >> i >> x;
      wm.update(i, x);
    }else{
      int l, r, k;
      cin >> l >> r >> k;
      k--;
      cout << wm.access(wm.quantileRange(l, r, k)) << "\n";
    }
  }
}

int main(){
  solve();
}