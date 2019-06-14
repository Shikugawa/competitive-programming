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
  vector<int> s(n);
  rep(i, n) {
    cin >> s[i];
  }
  vector<int> cul(n);
  rep(i, n){
    if (i == 0) cul[i] = s[i];
    else cul[i] = cul[i-1]+s[i];
  }
  ll val = 10000000;
  rep(i, n){
    int tmp = abs(cul[i] - (cul[n-1] - cul[i]));
    if(tmp < val) {
      val = tmp;
    }
  }
  cout << val << endl;
}