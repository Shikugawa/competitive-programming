#include <bits/stdc++.h>

using namespace std;

int main()
{
  int n = 10;
  int A = (1 << 2) | (1 << 3) | (1 << 5) | (1 << 7);

  for (int bit = A;; bit = (bit - 1) & A)
  {
    cout << bitset<8>(bit) << endl;
    vector<int> S;
    for (int i = 0; i < n; ++i)
    {
      if (bit & (1 << i))
      {
        S.push_back(i);
      }
    }

    for (int i = 0; i < (int)S.size(); ++i)
    {
      cout << S[i] << " ";
    }

    if (!bit)
      break;
  }
}