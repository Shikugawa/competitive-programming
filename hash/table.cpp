#include <bits/stdc++.h>
#define NUM -1000
using namespace std;

template <class T, int N>
class HashTable
{
public:
  HashTable()
  {
    for(int i = 0; i < N; ++i)
      table[i] = NUM;
  }

  void insert(T val)
  {
    int i = 0;
    while(true)
    {
      if(occupied(hash(val, i)))
        ++i;
      else
      {
        table[hash(val, i)] = val;
        break;
      }
    }
  }

  optional<T> search(T val)
  {
    int i = 0;
    while(true)
    {
      if(occupied(hash(val, i)))
        return table[hash(val, i)];
      else
        ++i;
    }
    return NULL;
  }
private:
  std::array<T, N> table;

  bool occupied(int i)
  {
    if(table[i] == NUM)
      return false;
    else
      return true;
  }

  int hash(T val, int i)
  {
    auto h1 = [&val](){
      return val % N;
    };

    auto h2 = [&val](){
      return (val - 1) % (N + 1);
    };

    return h1() + i * h2();
  }
};

int main(void)
{
  int n;
  cin >> n;
  for(int i = 0; i < n; ++i)
  {
  }
}