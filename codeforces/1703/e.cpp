// Template {{{

#include <bits/stdc++.h>

using namespace std;

// Type abbreviations {{{

using ll = long long;
using ld = long double;
using ii = pair<int, int>;
using llll = pair<ll, ll>;
using ldld = pair<ld, ld>;
using vi = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvld = vector<vld>;
using vii = vector<ii>;
using vllll = vector<llll>;
using vldld = vector<ldld>;
using vb = vector<bool>;

// }}}

// Easy debugging (https://codeforces.com/blog/entry/68809) {{{

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
void __print(vector<bool> v) {
  bool first = true;
  cerr << "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      cerr << ", ";
    }
    first = false;
    __print(v[i]);
  }
  cerr << "}";
}
template <size_t N> void __print(bitset<N> bs) {
  string res = "<";
  for (size_t i = 0; i < N; i++) {
    res += static_cast<char>('0' + bs[i]);
  }
  res += '>';
  cerr << res;
}
template <typename T> void __print(const T &x) {
  int j = 0;
  cerr << "{";
  for (auto &i : x)
    cerr << (j++ ? ", " : ""), __print(i);
  cerr << "}";
}
template <typename T, typename V> void __print(const pair<T, V> &x) {
  cerr << "(";
  __print(x.first);
  cerr << ", ";
  __print(x.second);
  cerr << ")";
}
template <typename A, typename B, typename C>
void __print(const tuple<A, B, C> t) {
  cerr << "(";
  __print(get<0>(t));
  cerr << ", ";
  __print(get<1>(t));
  cerr << ", ";
  __print(get<2>(t));
  cerr << ")";
}
template <typename A, typename B, typename C, typename D>
void __print(const tuple<A, B, C, D> t) {
  cerr << "(";
  __print(get<0>(t));
  cerr << ", ";
  __print(get<1>(t));
  cerr << ", ";
  __print(get<2>(t));
  cerr << ", ";
  __print(get<3>(t));
  cerr << ")";
}
void _print() { cerr << " ]\n"; }
template <typename T, typename... V> void _print(T t, V... v) {
  __print(t);
  if (sizeof...(v))
    cerr << ", ";
  _print(v...);
}

#ifndef ONLINE_JUDGE
#define deb(...)                                                               \
  cerr << "~ [ " << #__VA_ARGS__ << " ] => [ ";                                \
  _print(__VA_ARGS__)
#define debn(...)                                                              \
  cerr << "~ [ ";                                                              \
  _print(__VA_ARGS__)
#else
#define deb(...)
#define debn(...)
#endif

// }}}

// Macros {{{

#define ALL(DS) (DS).begin(), (DS).end()
#define RALL(DS) (DS).rbegin(), (DS).rend()
#define PB push_back
#define EB emplace_back
#define SZ(DS) (int)((DS).size())
#define fo(ITER, LO, UP) for (int ITER = (LO); ITER < (UP); ++ITER)
#define foll(ITER, LO, UP) for (ll ITER = (ll)(LO); ITER < (ll)(UP); ++ITER)
#define FO(ITER, UP, LO) for (int ITER = (UP); ITER > (LO); --ITER)
#define FOLL(ITER, UP, LOW) for (ll ITER = (ll)(UP); ITER > (ll)(LO); --ITER)
#define iter(ITER, DS) for (auto &&ITER : DS)
#define FASTIO                                                                 \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);
#define PRECISION                                                              \
  cout.setf(ios::fixed);                                                       \
  cout.precision(20);

// }}}

// }}}

const int MOD = 1e9 + 7;
const ll LLMOD = 1e18 + 7;

void init() {}

void solve(int testcase) {
  int n;
  cin >> n;
  vector<vb> m(n, vb(n, false));

  fo(i, 0, n) {
    string row;
    cin >> row;

    fo(j, 0, n) {
      if (row[j] == '1')
        m[i][j] = true;
    }
  }

  // deb(m);

  if (n == 1) {
    cout << 0 << '\n';
    return;
  }

  bool is_odd = n % 2 ? true: false;

  int ar = 0, ac = 0;
  int br = 0, bc = n-1;
  int cr = n-1, cc = n-1;
  int dr = n-1, dc = 0;

  int limit = n/2 + (is_odd ? 1: 0);
  auto step = [&]() {
    if (ac + 1 < limit) {
      ac++;
      br++;
      cc--;
      dr--;
    } else {
      ar++;
      bc--;
      cr--;
      dc++;

      ac = 0, br = 0, cc = n-1, dr = n-1;
    }
  };

  int steps = limit * (n/2);
  int res = 0;
  while (steps--) {
    // deb(ar, ac, br, bc, cr, cc, dr, dc);
    int count = m[ar][ac] + m[br][bc] + m[cr][cc] + m[dr][dc];
    // deb(count);

    if (count == 1 || count == 3) {
      res += 1;
    } else if (count == 2) {
      res += 2;
    }

    step();
  }

  cout << res << '\n';
}

// Main {{{

int main() {
  FASTIO PRECISION;
  init();
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t)
    solve(t);
}

// }}}

// vim: foldmarker={{{,}}} foldlevel=0 foldmethod=marker
