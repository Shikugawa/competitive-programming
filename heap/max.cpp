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

void buildMaxHeap(vector<int> &heap, int counter)
{
  if (counter > heap.size() / 2)
  {
    return;
  }
  int target = counter;
  int l_child = 2 * counter;
  int r_child = 2 * counter + 1;
  if (heap[l_child] > heap[counter] && heap[l_child] > heap[r_child])
    target = l_child;
  else if (heap[r_child] > heap[l_child] && heap[r_child] > heap[counter])
    target = r_child;
  if (target != counter)
  {
    int tmp = heap[counter];
    heap[counter] = heap[target];
    heap[target] = tmp;
    buildMaxHeap(heap, target);
  }
}

int main()
{
  int len, tmp;
  scanf("%d", &len);
  vector<int> heap(len + 1);
  for (int i = 1; i <= len; ++i)
  {
    cin >> tmp;
    heap[i] = tmp;
  }
  for (int i = heap.size() / 2; i >= 1; --i)
    buildMaxHeap(heap, i);
  cout << heap << endl;
}