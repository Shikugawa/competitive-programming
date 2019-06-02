#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

using ll = long long int;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
  }
  return os;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, q, tmp, l, r;
  vector<int> m;
  m.emplace_back(0);
  string s;
  cin >> n >> q;
  cin >> s;
  for (int i = 1; i < s.size(); ++i)
  {
    if (s[i] == 'C' && s[i - 1] == 'A')
      ++tmp;
    m.emplace_back(tmp);
  }
  rep(i, q)
  {
    cin >> l >> r;
    cout << m[r - 1] - m[l - 1] << endl;
  }
}