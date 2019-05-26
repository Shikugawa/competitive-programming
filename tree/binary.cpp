#include <bits/stdc++.h>

using namespace std;

template <class T>
class Node
{
public:
  Node(T value_, Node *parent_ = nullptr) : value(value_), parent(parent_)
  {
  }

  ~Node()
  {
    delete parent;
    delete left;
    delete right;
  }

  int child_size()
  {
    if (left == nullptr && right == nullptr)
      return 0;
    else if (left != nullptr && right != nullptr)
      return 2;
    else
      return 1;
  }

  Node *parent;
  Node *left;
  Node *right;
  T value;
};

template <class T>
class Tree
{
public:
  Node<T> *root;

protected:
  using value_t = T;

  Tree()
  {
  }

  virtual void insert(const T &v) = 0;

  virtual pair<bool, decltype(root)> find(const T &v) = 0;

  virtual void del(const T &v) = 0;

public:
  void inorder()
  {
    const function<void(Node<T> *)> inorderImpl = [&inorderImpl](auto r) -> void {
      if (r == nullptr)
        return;
      inorderImpl(r->left);
      cout << r->value << " ";
      inorderImpl(r->right);
    };
    inorderImpl(root->left);
    cout << root->value << " ";
    inorderImpl(root->right);
  }

  void preorder()
  {
    const function<void(Node<T> *)> preorderImpl = [&preorderImpl](auto r) -> void {
      if (r == nullptr)
        return;
      cout << r->value << " ";
      preorderImpl(r->left);
      preorderImpl(r->right);
    };
    cout << root->value << " ";
    preorderImpl(root->left);
    preorderImpl(root->right);
  }
};

template <class T>
class BTree : public Tree<T>
{
public:
  using Base = Tree<T>;
  using value_t = T;

  BTree()
  {
  }

  void insert(const T &value)
  {
    auto nextNode = Base::root;
    while (true)
    {
      if (nextNode->value < value)
      {
        if (nextNode->right == nullptr)
        {
          nextNode->right = new Node<T>(value, nextNode);
          break;
        }
        else
          nextNode = nextNode->right;
      }
      else
      {
        if (nextNode->left == nullptr)
        {
          nextNode->left = new Node<T>(value, nextNode);
          break;
        }
        else
          nextNode = nextNode->left;
      }
    }
  }

  pair<bool, decltype(Base::root)> find(const T &value)
  {
    auto node = Base::root;
    while (true)
    {
      if (node->value == value)
        return make_pair(true, node);
      else if (node->left != nullptr && value > node->left->value)
        node = node->left;
      else if (node->right != nullptr && value < node->right->value)
        node = node->right;
      else
        return make_pair(false, node);
    }
  }

  void del(Node<T> *t)
  {
    auto target = t;
    if (target->child_size() == 0)
    {
      delete t;
    }
    else if (target->child_size() == 1)
    {
      if (t->value < t->parent->value)
      {
        if (t->left != nullptr)
          t->parent->left = t->left;
        else
          t->parent->left = t->right;
      }
      else if (t->value >= t->parent->value)
      {
        if (t->left != nullptr)
          t->parent->right = t->left;
        else
          t->parent->right = t->right;
      }
    }
    else
    {
      auto minNode = t;
      while (t->left != nullptr)
        minNode = minNode->left;
      target->value = minNode->value;
      del(minNode);
    }
  }

  void del(const T &value)
  {
    auto [result, node_p] = find(value);
    if (result)
    {
      del(node_p);
    }
  }
};

int main()
{
  BTree<int> tree;
  int times;
  string instruction;
  int value;
  scanf("%d", &times);
  for (int i = 0; i < times; ++i)
  {
    cin >> instruction;
    if (instruction == "insert")
    {
      scanf("%d", &value);
      if (tree.root == nullptr)
        tree.root = new Node<decltype(tree)::value_t>(value);
      else
      {
        tree.insert(value);
      }
    }
    else if (instruction == "find")
    {
      scanf("%d", &value);
      auto [result, _] = tree.find(value);
      if (result)
        cout << "Yes" << endl;
      else
        cout << "No" << endl;
    }
    else if (instruction == "delete")
    {
      scanf("%d", &value);
      tree.del(value);
    }
    else if (instruction == "print")
    {
      cout << "inorder" << endl;
      tree.inorder();
      cout << endl;
      cout << "preorder" << endl;
      tree.preorder();
      cout << endl;
    }
  }
}