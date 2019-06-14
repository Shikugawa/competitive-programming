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
  int n, a;
  cin >> n >> a;
  vector<int> num(n);
  rep(i, n) cin >> num[i];
  int dp[n+1][a+1] = {0};
  rep(i, a) dp[0][i] = -1;
  rep(i, n) dp[i][0] = -1;
  for(int i = 1; i <= n; ++i)
  {
    for(int j = 1; j <= a; ++j)
    {
      if (num[i-1] < j)
      {
        dp[i][j] = min(dp[i-1][j-num[i-1]] + dp[i-1][j], dp[i-1][j]);
      }
      else
      {
        dp[i][j] = dp[i-1][j];
      }
    }
  }
  cout << dp[n][a] << endl;
}