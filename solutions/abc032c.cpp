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
  ll k, n, left = 0, right = 0;
  cin >> n >> k;
  vector<ll> a(n);
  ll max_len = 0;
  rep(i, n)
  {
    cin >> a[i];
  }
  rep(i, n)
  {
    if (a[i] == 0)
    {
      cout << n << endl;
      return 0;
    }
  }
  ll min_res = a[0], res = 1;
  rep(left, n)
  {
    while (right < n && res * a[right] <= k)
    {
      res *= a[right];
      ++right;
    }
    if (right - left > max_len)
    {
      max_len = right - left;
    }
    if (left == right)
    {
      ++right;
    }
    else
    {

      res /= a[left];
    }
  }
  std::cout << max_len << endl;
}