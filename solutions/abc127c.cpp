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
  ll n, m, min = 0, max = MOD, tmp_a, tmp_b;
  cin >> n >> m;
  rep(i, m)
  {
    cin >> tmp_a >> tmp_b;
    if (min < tmp_a)
    {
      min = tmp_a;
    }
    if (max > tmp_b)
    {
      max = tmp_b;
    }
  }
  
  if (max >= min)
  {
    cout << max - min + 1 << endl;
  }
  else
  {
    cout << 0 << endl;
  }
}