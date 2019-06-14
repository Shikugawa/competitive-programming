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
}