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
  int n, a;
  cin >> n >> a;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  int dp[n+1][a+1] = {0};
  rep(i, n+1) dp[i][0] = 1;
  for(int i = 1; i <= n; ++i)
  {
    for(int j = 1; j <= a; ++j)
    {
      if (v[i-1] < j)
      {
        if (dp[i-1][j-v[i-1]] == 1)
        {
          dp[i][j] = 1;
        }
        else if(dp[i-1][j] == 1)
        {
          dp[i][j] == 1;
        }
        else
        {
          dp[i][j] = 0;
        }
      }
      else
      {
        dp[i][j] = 0;
      }
    }
  }
  if(dp[n][a] == 1)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
}