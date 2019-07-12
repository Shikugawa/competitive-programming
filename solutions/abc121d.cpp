#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define MOD 1000000009

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
  ll a, b;
  cin >> a >> b;
  vector<int> v(40, 0);
  ll div = 2;
  rep(i, 40)
  {
    ll count = 0;
    for(ll j = a; j <= b; ++j)
    {
      cout << j << endl;
      ll rem = j % div;
      if (rem >= div / 2) ++count;
    }
    if (count % 2 == 0) v[i] = 0;
    else v[i] = 1;
    div *= 2;
  }
  string s;
  for(int i = v.size() - 1; i >= 0; --i)
  {
    s += to_string(v[i]);
  }
  cout << stol(s, nullptr, 2) << endl;
}