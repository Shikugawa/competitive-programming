#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

using ll = unsigned long long int;

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
  int n, m;
  cin >> n >> m;
  vector<ll> s(n, 0);
  rep(i, m)
  {
    int tmp;
    cin >> tmp;
    s[tmp] = 1;
  }
  ll dp[n+1] = {0};
  ll mod = 1000000007;
  dp[0] = 1;
  if (s[1] == 1) dp[1] = 0;
  else dp[1] = 1;
  for(int i = 2; i <= n; ++i){
    if (s[i - 1] == 1) dp[i - 1] = 0;
    if (s[i - 2] == 1) dp[i - 2] = 0;
    dp[i] = dp[i - 1] + dp[i - 2];
  }
  cout << dp[n] % mod << endl;
}