#include <iostream>
#include <queue>
#include <vector>
#include <list>
#define NODE_COUNT 1000
using namespace std;

template <typename T>
 class Node{
    public:
    T data;
    Node<T> *next;

    Node(T data){
        this -> data = data;
        this -> next = nullptr;
    }
 };
template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data=0) {
        this -> data = data;
        left = nullptr;
        right = nullptr;
    }
};

BinaryTreeNode<int>* searchInBST(BinaryTreeNode<int> *root , int k){
  /* Given a BST and an integer k. Find if the integer k is present in given
   * BST or not. Return the node with data k if it is present, return null
   * otherwise. Assume that BST contains all unique elements. */
  if(root==nullptr) return nullptr;
  if(root->data==k) return root;
  BinaryTreeNode<int>* left = searchInBST(root->left, k);
  if(left!=nullptr) return left;
  BinaryTreeNode<int>* right = searchInBST(root->right, k);
  return right;
}

void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
  /* Given a Binary Search Tree and two integers k1 and k2, find and print the
   * elements which are in range k1 and k2 (both inclusive). Print the elements
   * in increasing order. */
  /* Solution: Since the elemnts have to be printed in increasing oder we will
   * use in-order traversal and print the node only if it lies between range */
  if(root==nullptr) return;
  elementsInRangeK1K2(root->left, k1, k2);
  if(k1<=root->data && root->data<=k2)
    cout<< root->data << ' ';
  elementsInRangeK1K2(root->right, k1, k2);
}

bool areElementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
  /* Given a Binary Search Tree and two integers k1 and k2, find and print the
   * elements which are in range k1 and k2 (both inclusive). Print the elements
   * in increasing order. */
  /* Solution: Since the elemnts have to be printed in increasing oder we will
   * use in-order traversal and print the node only if it lies between range */
  if(root==nullptr) return true;
  if(root->data<k1 || k2<root->data) return false;
  if(!areElementsInRangeK1K2(root->left, k1, k2)) return false;
  if(!areElementsInRangeK1K2(root->right, k1, k2)) return false;
  return true;
}

Node<int>* constructBST(BinaryTreeNode<int>* root) {
  /* Given a BST, convert it into a sorted linked list. Return the head of
   * LL.*/
  if(root==nullptr) return nullptr;
  Node<int> *list = constructBST(root->left);
  Node<int> *curr = new Node<int>(root->data);
  curr->next = constructBST(root->right);
  if(list==nullptr) return curr;
  /* Append curr at end of list and return list */
  Node<int> *ptr = list;
  while(ptr->next!=nullptr) ptr = ptr->next;
  ptr->next = curr;
  return list;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
  /* Given a sorted integer array A of size n which contains all unique
   * elements. You need to construct a balanced BST from this input array.
   * Return the root of constructed BST. If array size is even, take first mid
   * as root. */
  if(input==nullptr || n<=0) return nullptr;
  int rootIndex = (n-1)/2;
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[rootIndex]);
  root->left = constructTree(input,rootIndex);
  root->right = constructTree(input+rootIndex+1,n-rootIndex-1);
  return root;
}

bool isBST(BinaryTreeNode<int> *root){
  /* Given a binary tree with N number of nodes, check if that input tree is
   * BST (Binary Search Tree) or not. If yes, return true, return false
   * otherwise. Duplicate elements should be in right subtree. */
  if(root==nullptr) return true;
  if(!isBST(root->left)) return false;
  if(!isBST(root->right)) return false;
  if(!areElementsInRangeK1K2(root->left, INT_MIN, root->data-1)) return false;
  if(!areElementsInRangeK1K2(root->right, root->data, INT_MAX)) return false;
  return true;
}

BinaryTreeNode<int>* searchInBinaryTree(BinaryTreeNode<int> *root , int x){
  if(root==nullptr) return nullptr;
  if(root->data == x) return root;
  BinaryTreeNode<int>* result = searchInBinaryTree(root->left, x);
  if(result!=nullptr) return result;
  result = searchInBinaryTree(root->right, x);
  return result;
}

int lcaBinaryTree(BinaryTreeNode <int>* root , int val1, int val2){
  /* Given a Binart Tree and two nodes, find LCA (Lowest Common Ancestor) of
   * the given two nodes in Binart Tree. Read about LCA if you are having
   * doubts about the definition. If out of 2 nodes only one node is present,
   * return that node. If both are not present, return -1. */
  if(root==nullptr) return -1;
  BinaryTreeNode <int>* node1 = searchInBinaryTree(root, val1);
  BinaryTreeNode <int>* node2 = searchInBinaryTree(root, val2);
  if(node1==nullptr)
  {
    if(node2==nullptr) return -1;
    else return node2->data;
  }
  // node1 is not null
  if(node2==nullptr)
    return node1->data;
  // node2 is not null
  if(node1 == node2) return node1->data;
  /* Here we are sure that we have two distinct nodes present in the tree. Now,
   * we can start from root and traverse the tree untill we get the LCA Node */
  BinaryTreeNode <int>* curr = root;
  while(curr != nullptr)
  {
    /* If both nodes are present in left tree */
    node1 = searchInBinaryTree(curr->left, val1);
    node2 = searchInBinaryTree(curr->left, val2);
    if(node1!=nullptr && node2!=nullptr)
    {
      curr = curr->left;
      continue;
    }
    /* If both nodes are present in right tree */
    node1 = searchInBinaryTree(curr->right, val1);
    node2 = searchInBinaryTree(curr->right, val2);
    if(node1!=nullptr && node2!=nullptr)
    {
      curr = curr->right;
      continue;
    }
    return curr->data;
  }
  /* This code should never be executed */
  return -1;
}
int lcaInBST(BinaryTreeNode <int>* root , int val1, int val2){
  /* Given a BST and two nodes, find LCA (Lowest Common Ancestor) of
   * the given two nodes in BST. Read about LCA if you are having
   * doubts about the definition. If out of 2 nodes only one node is present,
   * return that node. If both are not present, return -1. */
  if(root==nullptr) return -1;
  /* Ensure val1 <= val2. If not swap them */
  if(val1>val2)
  {
    int temp = val1;
    val1 = val2;
    val2 = temp;
  }
  BinaryTreeNode <int>* node1 = searchInBST(root, val1);
  BinaryTreeNode <int>* node2 = searchInBST(root, val2);
  if(node1==nullptr)
  {
    if(node2==nullptr) return -1;
    else return node2->data;
  }
  // node1 is not null
  if(node2==nullptr)
    return node1->data;
  // node2 is not null
  if(node1 == node2) return node1->data;
  /* Here we are sure that we have two distinct nodes present in the tree. Now,
   * we can start from root and traverse the tree untill we get the LCA Node */
  BinaryTreeNode <int>* curr = root;
  while(curr != nullptr)
  {
    if(val1 <= curr->data && curr->data <= val2) return curr->data;
    /* Both node1 and node 2 are in some subtree */
    if(val2 < curr->data)
      curr = curr->left;
    else
      curr = curr->right;
  }
  /* This code should never be executed if given tree is a BST */
  return -1;
}

BinaryTreeNode<int>* buildLevelTree(int *levelorder, int length)
{
  if(length<=0 || levelorder==nullptr)
    return nullptr;
  BinaryTreeNode<int> **nodes = new BinaryTreeNode<int>*[length];
  for(int i=0; i<length; i++)
  {
    if(levelorder[i]==-1)
      nodes[i] = nullptr;
    else
      nodes[i] = new BinaryTreeNode<int>(levelorder[i]);
  }
  for(int i=0; i<length && nodes[i]!=nullptr; i++)
  {
    int left = (i*2)+1;
    if(nodes[left]!=nullptr) nodes[i]->left = nodes[left];
    if(nodes[left+1]!=nullptr) nodes[i]->right = nodes[left+1];
  }
  return nodes[0];
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
  /* Given a binary tree and a number k, print out all root to leaf paths where
   * the sum of all nodes value is same as the given number k. */
  /* Here we will traverse the tree is inorder using stack */
  if(root==nullptr) return;
  BinaryTreeNode<int> **nodes = new BinaryTreeNode<int>*[NODE_COUNT];
  nodes[0] = root;
  int top = 1;  // This <nodes,top> act as a stack of pointer to nodes
  BinaryTreeNode<int> *curr = root;
  int sum = 0;
  while(top>0)
  {
    curr = nodes[--top];
    while(curr->left!=nullptr) {
      // left subtree exist
      nodes[top++] = curr;
      sum += curr->data;
      curr = curr->left;
    }
    // curr has no left subtree
    cout << curr->data << ' ';
    // push curr->right
    if(curr->right==nullptr)
    {
      // curr is leaf node
      /*
      if(sum==k)
      {
        // print the stack
        for(int i=0; i<top; i++)
          cout << nodes[i]->data << ' ';
        cout << endl;
      }
      else
        curr = curr->right;
      */
      // pop the last item from stack
      if(top==0) return;
      curr = nodes[--top];
    }
    else
      curr = curr->right;
  }
}

int getArray(int arr[], int size)
{
  cin >> size;
  // Read the array
  for(int j=0;j<size;++j) 
    cin >> arr[j];
  return size;
}

int main()
{
  static int maxNodeCount = 1000;
  int nodeCount, levelOrder[maxNodeCount];
  nodeCount = getArray(levelOrder,maxNodeCount);
  BinaryTreeNode<int>* root=buildLevelTree(levelOrder, nodeCount);
  int val1, val2;
  //cin >> val1 >> val2; cout << lcaBinaryTree(root, val1, val2) << endl;
  cin >> val1; rootToLeafPathsSumToK(root, val1);
}
