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

  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i, n) cin >> a[i];

  ll right = 0, cnt = n;

  rep(left, n - 1)
  {
    while (right < n - 1 && a[right + 1] > a[right])
    {
      ++right;
      ++cnt;
      cnt += (right - left) - 1;
    }
    if (left == right)
    {
      ++right;
    }
  }
  cout << cnt << endl;
}