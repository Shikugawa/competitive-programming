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
  ll n, k, right = 0, result = 0, sum = 0, tmp;
  cin >> n >> k;
  vector<ll> d(n);
  rep(i, n)
  {
     cin >> d[i];
  }
  rep(left, n)
  {
    while (sum + d[right] < k && right < n)
    {
      sum += d[right];
      ++right;
    }
    
    result += n - right;
    if (left == right)
    {
      ++right;
    }
    else
    {
      sum -= d[left];
    }
  }
  cout << result << endl;
}