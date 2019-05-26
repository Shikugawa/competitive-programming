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
  int n, m, k, tmp, result = 0;
  cin >> n >> m;
  vector<vector<int>> v;
  vector<int> s;
  rep(i, m)
  {
    cin >> k;
    vector<int> _v;
    rep(i, k)
    {
      cin >> tmp;
      _v.emplace_back(tmp);
    }
    v.emplace_back(_v);
  }
  for (int i = 0; i < m; ++i)
  {
    cin >> tmp;
    s.emplace_back(tmp);
  }

  for (int i = 0; i < (1 << n); ++i)
  {
    int flag = 0;
    rep(j, v.size())
    {
      int num = 0;
      rep(k, v[j].size())
      {
        rep(l, n)
        {
          if (i & (1 << l))
          {
            if (l + 1 == v[j][k])
              ++num;
          }
        }
      }
      if (num % 2 == s[j])
        ++flag;
    }
    if (flag == m)
      ++result;
  }
  cout << result << endl;
}