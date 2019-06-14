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

  int n;
  cin >> n;
  vector<int> v(n);
  for(int i = 0; i < n; ++i)
    cin >> v[i];
  int dp[n+1] = {0};
  for(int i = 1; i <= n; ++i)
  {
    // cout << v[i] + dp[i-1] << endl;
    if(v[i-1]+dp[i-1] > dp[i-1])
    {
      dp[i] = dp[i-1] + v[i-1];
    }
    else
    {
      dp[i] = dp[i-1];
    }
  }
  cout << dp[n] << endl;
}