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
  int n, w, v, _w;
  cin >> n >> w;
  vector<pair<int, int>> item(n);
  int dp[n+1][w] = {0};
  rep(i, n)
  {
    cin >> v >> _w;
    item[i] = make_pair(v, _w);
  }
  for(int i = 1; i <= n; ++i)
  {
    for(int j = 1; j <= w; ++j)
    {
      auto [_w, _v] = item[i-1];
      if (_w > j)
      {
        dp[i][j] = dp[i-1][j];
      }
      else
      {
        dp[i][j] = max(_v + dp[i - 1][j - _w], dp[i - 1][j]);
      }
    }
  }
  cout << dp[n][w-1] << endl;
}
