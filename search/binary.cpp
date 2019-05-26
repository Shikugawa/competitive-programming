#include <bits/stdc++.h>

using namespace std;

template <typename T>
bool bSearch(const vector<T>& s, T v)
{
  int mid = s.size() / 2;

  if(s.size() == 0) return false;
  
  if(v < s[mid])
  {
    vector<int> _s(s.begin(), s.begin() + mid);
    if(bSearch(_s, v)) return true;
  }
  else if(v > s[mid])
  {
    vector<int> _s(s.begin() + mid + 1, s.end());
    if(bSearch(_s, v)) return true;
  }
  else
  {
    return true;
  }
  return false;
}

int main(void)
{
  int n;
  vector<int> s;
  cin >> n;
  for(int i = 0; i < n; ++i)
  {
    int q;
    cin >> q;
    s.push_back(q);
  }
  
  vector<int> c;
  cin >> n;
  for(int i = 0; i < n; ++i)
  {
    int q;
    cin >> q;
    c.push_back(q);
  }

  int _c;
  for(const auto& a: c)
  {
    if(bSearch(s, a)) ++_c;
  }
  cout << _c << endl;
}