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

template <typename T>
void print_table(ostream& os, const T dp[], int m, int n)
{
  for(int i = 0; i < m; ++i)
  {
    for(int j = 0; j < n; ++j)
    {
      cout << dp[i][j] << " ";
    }
    cout << endl;
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s1, s2;
  cin >> s1;
  cin >> s2;
  int dp[s1.size()][s2.size()] = {0};
  char* m;
  rep(i, s1.size())
  {
    if (s2[0] == s1[i])
    {
      dp[i][0] = 1;
    }
    else
    {
      dp[i][0] = dp[i-1][0];
    }
  }
  rep(i, s2.size())
  {
    if (s1[0] == s2[i])
    {
      dp[0][i] = 1;
    }
    else
    {
      dp[0][i] = dp[0][i-1];
    }
  }
  for(int i = 1; i < s1.size(); ++i)
  {
    for(int j = 1; j < s2.size(); ++j)
    {
      if (s1[i] != s2[i])
      {
        dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
      }
      else
      {
        dp[i][j] = dp[i-1][j-1] + 1;
        m[dp[i-1][j-1]] = s1[i];
      }
    }
  }
}