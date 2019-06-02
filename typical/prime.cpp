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

vector<int> prime(int num)
{
  vector<int> g(num - 1);
  vector<int> r;
  int i = 1;
  generate(g.begin(), g.end(), [&i]() { i++; return i; });
  i = 2;
  while (i < sqrt(num))
  {
    r.emplace_back(i);
    for (auto j = g.begin(); j < g.end(); ++j)
    {
      if (*j % i == 0)
        g.erase(j);
    }
    i = g[0];
  }
  copy(r.begin(), r.end(), front_inserter(g));
  return g;
}

int main()
{
  cout << prime(100) << endl;
}