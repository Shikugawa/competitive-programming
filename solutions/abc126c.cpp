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
  ll n, k;
  double result;
  cin >> n >> k;
  for(int i = 1; i <= n; ++i)
  {
    double r = 1.0/n;
    ll cur = i;
    while (cur < k)
    {
      cur *= 2;
      r /= 2;
    }
    result += r;
  }
  printf("%.12f\n", result); //「絶対・相対誤差10^(-n)以下」と指定された場合は「小数点以下n+1桁目」まで出力すればよい
}
