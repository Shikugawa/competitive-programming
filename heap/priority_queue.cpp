
#include <bits/stdc++.h>

using namespace std;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec)
{
  for (int i = 0; i < vec.size(); i++)
  {
    os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
  }
  return os;
}

class PriorityQueue
{
public:
  PriorityQueue(std::initializer_list<int> l) : v(l)
  {
  }

  PriorityQueue() = default;

  void insert(int num)
  {
    v.emplace_back(num);
    for (int i = v.size() / 2; i >= 1; ++i)
    {
      heapify(i);
    }
  }

  int extract()
  {
    int val = v.front();
    for (int i = v.size() / 2; i >= 1; ++i)
    {
      heapify(i);
    }
    return val;
  }

  vector<int> v;

private:
  void heapify(int counter)
  {
    int target = counter, l_child = 2 * counter, r_child = 2 * counter + 1;
    if (v[l_child] > v[target] && v[l_child] > v[r_child])
      target = l_child;
    else if (v[r_child] > v[target] && v[r_child] > v[l_child])
      target = r_child;
    if (target != counter)
    {
      int tmp = v[target];
      v[target] = v[counter];
      v[counter] = v[target];
      heapify(target);
    }
  }

  void upHeapify()
  {
    
  }
};

int main()
{
}