#include "BSTree.h"
#include <iostream>

using namespace std;

//input / output operators
ostream &operator<<(ostream &out, BSTree &tree)
{
  tree.print_level_by_level(out);
  return out;
}

ostream &operator<<(ostream &out, Node node)
{
  return out << "( " << node.value << ", "
             << node.search_time << " )";
}

istream &operator>>(istream &in, BSTree &tree)
{
  int next;
  while (in >> next)
    tree.insert(next);
  return in;
}

//////////////////// Implementation To Do ////////////////////

// copy constructor
BSTree::BSTree(const BSTree &other)
{
  if (other.get_root() != nullptr)
  {
    root = new Node(other.get_root()->value);
    root->search_time = 1;
  }
  copy_helper(root, other.get_root());
  size = other.get_size();
}

// move constructor
BSTree::BSTree(BSTree &&other)
{
  root = new Node(other.get_root()->value);
  size = other.get_size();
  copy_helper(root, other.get_root());
  other.root = nullptr; // deletes original tree 
  other.size = 0;
}

//copy assignment
BSTree &BSTree::operator=(const BSTree& other)
{
  if(this != &other)
  {
    delete_tree(root);
    if (other.get_root() != nullptr)
    {
      root = new Node(other.get_root()->value);
      root->search_time = 1;
    }
    copy_helper(root, other.get_root());
    size = other.get_size();
  }
  return *this;
}

// move assignment
BSTree BSTree::operator=(BSTree &&other)
{
  if(this != &other)
  {
    delete_tree(root);
    if (other.get_root() != nullptr)
    {
      root = new Node(other.get_root()->value);
      root->search_time = 1;
    }
    copy_helper(root, other.get_root());
    size = other.get_size();
    other.root = nullptr;
    other.size = 0;
  }
  return *this;
}

// destructor
BSTree::~BSTree()
{
  delete_tree(root);
}

void BSTree::delete_tree(Node *tree)
{
  if (tree == nullptr)
    return;
  delete_tree(tree->left);
  delete_tree(tree->right);
  delete tree;
  tree = nullptr; 
}

// recursive
void BSTree::copy_helper(Node *copy_to, const Node *copy_from) const
{
  if (copy_from == nullptr)
    return;

  if (copy_from->left != nullptr)
  {
    copy_to->left = new Node(*copy_from->left);
    copy_helper(copy_to->left, copy_from->left);
  }
  else
  {
    copy_to->left = nullptr;
  }

  if (copy_from->right != nullptr)
  {
    copy_to->right = new Node(*copy_from->right);
    copy_helper(copy_to->right, copy_from->right);
  }
  else
  {
    copy_to->right = nullptr;
  }
}

Node *BSTree::insert(int obj)
{
  size++;
  return insert_helper(obj, root, 1);
}

Node *BSTree::insert_helper(int obj, Node *&node, int st)
{
  if (node == nullptr)
  {
    node = new Node(obj);
    node->search_time = st;
    return node;
  }
  else if (obj < node->value)
  {
    return insert_helper(obj, node->left, st + 1);
  }
  else
  {
    return insert_helper(obj, node->right, st + 1);
  }
}

Node *BSTree::search(int obj)
{
  return search_helper(obj, root);
}

Node *BSTree::search_helper(int obj, Node *node)
{
  if (node == nullptr || obj == node->value)
    return node;
  else if (obj < node->value)
  {
    return search_helper(obj, node->left);
  }
  else
  {
    return search_helper(obj, node->right);
  }
}

void BSTree::update_search_times()
{
  return update_helper(root, 1);
}

void BSTree::update_helper(Node *tree, int st)
{
  if (tree == nullptr)
    return;
  tree->search_time = st;
  update_helper(tree->left, st + 1);
  update_helper(tree->right, st + 1);
}

ostream &BSTree::inorder(ostream &out)
{
  out << endl;
  print_tree(out, root);
  out << endl;
}

void BSTree::print_tree(ostream &out, Node *tree)
{
  if (tree == nullptr)
    return;
  print_tree(out, tree->left);
  out << tree->value << " ";
  print_tree(out, tree->right);
}

// implemented
void BSTree::pretty_print_node(ostream &out, Node *node)
{
  out << node->value << "[" << node->search_time << "] ";
}

// implemented
ostream &BSTree::print_level_by_level(ostream &out)
{
  if (root == nullptr)
    return out;

  bool hasNodes = true;
  vector<Node *> current_level;
  vector<Node *> next_level;
  current_level.push_back(root);
  while (hasNodes)
  {
    hasNodes = false;
    for (auto node : current_level)
    {
      if (node != nullptr)
      {
        pretty_print_node(out, node);
        if (node->left != nullptr)
          hasNodes = true;
        if (node->right != nullptr)
          hasNodes = true;

        next_level.push_back(node->left);
        next_level.push_back(node->right);
      }
      else
      {
        out << "X ";
        next_level.push_back(nullptr);
        next_level.push_back(nullptr);
      }
    }
    out << endl;
    current_level.clear();
    current_level = next_level;
    next_level.clear();
  }

  return out;
}

// implemented
int BSTree::get_total_search_time(Node *node)
{
  if (node == nullptr)
    return 0;

  return get_total_search_time(node->left) +
         get_total_search_time(node->right) + node->search_time;
}

// implemented
float BSTree::get_average_search_time()
{
  int total_search_time = get_total_search_time(root);
  if (total_search_time == 0)
    return -1;

  return ((float)total_search_time) / size;
}