#include <bits/stdc++.h>

using namespace std;

int main()
{
  vector<pair<string, int>> a;
  int result = 500;
  a.emplace_back(make_pair("みかん", 100));
  a.emplace_back(make_pair("りんご", 200));
  a.emplace_back(make_pair("ぶどう", 300));
  for (int i = 0; i < (1 << a.size()); ++i)
  {
    int sum;
    for (int j = 0; j < a.size(); ++j)
    {
      if (i & (1 << j)) // flag j is 1 on i
        sum += a[i].second;
    }
    cout << sum << endl;
    if (sum == result)
    {
      cout << "true" << endl;
      exit(0);
    }
  }
  cout << "false" << endl;
}