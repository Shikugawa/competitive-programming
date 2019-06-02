#include <bits/stdc++.h>

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

using namespace std;

using ll = long long int;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
  for (ll i = 0; i < vec.size(); i++)
  {
    os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
  }
  return os;
}

double c(ll a)
{
  return a * (a - 1) / 2;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n, tmp, cnt = 0, l;
  map<ll, ll> p;
  cin >> n;
  vector<ll> a(n);
  vector<ll> s(n + 1, 0);
  for (int i = 0; i < n; ++i)
    cin >> a[i];
  rep(i, n)
  {
    s[i + 1] = s[i] + a[i];
  }
  ll o = -999;
  for (ll i = 0; i <= n; ++i)
  {
    p[s[i]]++;
  }

  for (const auto &a : p)
  {
    if (a.second >= 2)
    {
      cnt += static_cast<ll>(c(a.second));
    }
  }
  std::cout << cnt << endl;
}