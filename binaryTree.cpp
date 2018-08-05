#include <iostream>
#include <stack>
#include <queue>
#include <unordered_map>
#include <vector>
#include <list>
using namespace std;
template <typename T>
class node{
public:
    T data;
    node<T> * next;
    node(T data){
        this->data=data;
        this->next=nullptr;
    }
};
template <typename T>
class nodelist{
public:  // Exposing Everything which is not the best way. But the idea over
        //  here is only to modularize the code
  node<T> *start, *end;
  nodelist(node<T> *p=nullptr)
    :start(p), end(p)
  {
    if(p==nullptr) return;
    p->next = nullptr;
  }
  void pushnode(node<T> *p)
  {
    if(p==nullptr) return;
    p->next = nullptr;
    if(start==nullptr)
    {
      /* First Node to insert */
      start = end = p;
      return;
    }
    end->next = p;
    end = p;
  }
  void popEndnode()
  {
    if(end==nullptr) return;
    if(end==start)
    {
      /* last node to return */
      delete end;
      start = end = nullptr;
      return;
    }
    node<T> *curr=start;
    while(curr->next!=end) curr = curr->next;
    curr->next = nullptr;
    delete end;
    end = curr;
  }
};
template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data) {
        this -> data = data;
        left = nullptr;
        right = nullptr;
    }
};
class PairAns {
    public :
        int min;
        int max;
 };

int sumOfAllNodes(BinaryTreeNode<int>* root) {
  /* Given a binary tree, find and return the sum of all nodes. */
  if(root==nullptr) return 0;
  int result = root->data; // root node
  result += sumOfAllNodes(root->left);
  result += sumOfAllNodes(root->right);
  return result;
}

BinaryTreeNode<int>* maxDataNode(BinaryTreeNode<int>* root) {
  /* Given a Binary Tree, find and return the node with maximum data. Return
   * the complete node. Return null is binary tree is empty.*/
  if(root==nullptr) return nullptr;
  BinaryTreeNode<int>* left = maxDataNode(root->left);
  BinaryTreeNode<int>* right = maxDataNode(root->right);
  // We are using root as temporary pointer to hold the resultant node
  if(left!=nullptr && root->data < left->data) root = left;
  if(right!=nullptr && root->data < right->data) root = right;
  return root;
}

int countLeafNodes(BinaryTreeNode<int>* root) {
  /* Given a Binary Tree, find and return the count of leaf nodes. Leaf nodes
   * are those, who don't have any children. Root is also leaf node if both its
   * child are null. */
  if(root==nullptr) return 0;
  if(root->left == nullptr && root->right == nullptr) return 1; // root node
  return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int countNodesGreaterThanX(BinaryTreeNode<int>* root, int x) {
  /* Given a Binary Tree and an integer x, find and return the count of nodes
   * which are having data greater than x.*/
  if(root==nullptr) return 0;
  int result = 0;
  if(root->data > x) result += 1;
  result += countNodesGreaterThanX(root->left,x);
  result += countNodesGreaterThanX(root->right,x);
  return result;
}

bool isNodePresent(BinaryTreeNode<int>* root, int x) {
  /* Given a Binary Tree and an integer x, check if node with data x is present
   * in the input binary tree or not. Return true or false.*/
  if(root==nullptr) return false;
  if(root->data == x) return true;
  if(isNodePresent(root->left, x)) return true;
  if(isNodePresent(root->right, x)) return true;
  return false;
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
  /* Mirror the given binary tree. That is, right child of every nodes should
   * become left and left should become right.*/
  if(root==nullptr) return;
  BinaryTreeNode<int> *left = root->left;
  root->left = root->right;
  root->right = left;
  mirrorBinaryTree(root->left);
  mirrorBinaryTree(root->right);
}

int depth(BinaryTreeNode<int> *root) {
  /* Used internally by diameter and other functions */
  if(root==nullptr) return 0;
  int left = depth(root->left);
  int right = depth(root->right);
  return max(left,right)+1;
}

int depthDiff(BinaryTreeNode<int> *root) {
  /* Presently Unused. But may be used by isBalanced */
  if(root==nullptr) return 0;
  int left = depth(root->left);
  int right = depth(root->right);
  int diff = left-right;
  if (diff<0) diff *= -1;
  int max = (left>right?left:right);
  return max+1;
}

pair<int,int> diameterNDepth(BinaryTreeNode<int>* root) {
  /* First has diameter and second has depth */
  pair<int,int> ans(0,0);
  if(root==nullptr) return ans;
  pair<int,int> left = diameterNDepth(root->left);
  pair<int,int> right = diameterNDepth(root->right);
  ans.second = 1+max(left.second, right.second);  // Calculating depth
  int diameterwithRoot = left.second + right.second + 1;
  ans.first = max( max(left.first,right.first), diameterwithRoot);
  return ans;

}
int diameter2(BinaryTreeNode<int>* root) {
  return diameterNDepth(root).first;
}
int diameter(BinaryTreeNode<int>* root) {
  /* Given a Binary Tree, find and return the diameter of input binary tree.
   * Diameter is - largest count of nodes between any two leaf nodes in the
   * binary tree (both the leaf nodes are inclusive). 
   * if there is only one node, diameter = 1 
   * if there are two nodes, diameter = 2 */
  if(root==nullptr) return 0;
  int leftDia = diameter(root->left);
  int rightDia = diameter(root->right);
  int d = depth(root->left) + depth(root->right) + 1;
  return max(max(leftDia,rightDia),d);
}

PairAns minMax(BinaryTreeNode<int> *root) {
  /* Given a binary tree, find and return the min and max data value of given
   * binary tree. Return the output as an object of PairAns class, which is
   * already created. */
  PairAns answer;
  answer.min = INT_MAX;
  answer.max = INT_MIN;
  if(root==nullptr) return answer;
  // Initialize answer as root node data
  PairAns left = minMax(root->left);
  PairAns right = minMax(root->right);
  answer.min = min(root->data, min(left.min, right.min));
  answer.max = max(root->data, max(left.max, right.max));
  return answer;
}

void printLevelWise(BinaryTreeNode<int> *root) {
  /* Given a binary tree, print the tree in level wise order. For printing
   * a node with data N, you need to follow the exact format: 
   * N:L:x,R:y
   * wherer, N is data of any node present in the binary tree. x and y are the
   * values of left and right child of node N. Print -1. if any child is null.
   * There is no space in between. You need to print all nodes in the level
   * order form in different lines. */
  if(root==nullptr) return;
  queue<BinaryTreeNode<int>*> q;
  q.push(root);
  while(!q.empty())
  {
    BinaryTreeNode<int> *curr = q.front();
    q.pop();
    int currData=curr->data, left=-1,right=-1;
    if(curr->left!=nullptr)
    {
      left = curr->left->data;
      q.push(curr->left);
    }
    if(curr->right!=nullptr)
    {
      right = curr->right->data;
      q.push(curr->right);
    }
    cout << currData << ":L:" << left << ",R:" << right << endl;
  }
}

void inOrderRecursive(BinaryTreeNode<int> *root) {
  if(root==nullptr) return;
  inOrderRecursive(root->left);
  cout<< root->data << ' ';
  inOrderRecursive(root->right);
}
void preOrder(BinaryTreeNode<int> *root) {
  /* Given a binary tree, print the preorder traversal of given tree. Pre-order
   * traversal is: Root LeftChild RightChild */
  if(root==nullptr) return;
  cout<< root->data << ' ';
  preOrder(root->left);
  preOrder(root->right);
}
void postOrder(BinaryTreeNode<int> *root) {
  /* Given a binary tree, print the postorder traversal of given tree.
   * Post-order traversal is: LeftChild RightChild Root */
  if(root==nullptr) return;
  postOrder(root->left);
  postOrder(root->right);
  cout<< root->data << ' ';
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength,
    int *inorder, int inLength) 
{
  /* Given Preorder and Inorder traversal of a binary tree, create the binary
   * tree associated with the traversals.You just need to construct the tree
   * and return the root. For 12 Nodes with following input:
   * preOrder: 1 2 3 4 15 5 6 7 8 10 9 12
   * inOrder: 4 15 3 2 5 1 6 10 8 7 9 12 */
  if(preLength!=inLength || preorder==nullptr || inorder==nullptr ||
      preLength==0)
    return nullptr;
  int rootVal = preorder[0], leftCount, rightCount;
  // Search for rootVal in inorder
  for(leftCount=0; leftCount<inLength && inorder[leftCount]!=rootVal;
      leftCount++);
  // leftCount is no of nodes of left tree
  rightCount = preLength-leftCount-1;
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootVal);
  root->left = buildTree(preorder+1,leftCount,inorder,leftCount);
  root->right = buildTree(preorder+leftCount+1,rightCount,
      inorder+leftCount+1,rightCount);
  return root;
}
BinaryTreeNode<int>* getTreeFromPostorderAndInorder(int *postorder,
    int postLength, int *inorder, int inLength) {
  /* Given Postorder and Inorder traversal of a binary tree, create the binary
   * tree associated with the traversals.You just need to construct the tree
   * and return the root. For 8 Nodes with following input:
   * postOrder: 8 4 5 2 6 7 3 1
   * inOrder: 4 8 2 5 1 6 3 7 */
  if(postLength!=inLength || postorder==nullptr || inorder==nullptr ||
      postLength==0)
    return nullptr;
  int rootVal = postorder[postLength-1], leftCount, rightCount;
  // Search for rootVal in inorder
  for(leftCount=0; leftCount<inLength && inorder[leftCount]!=rootVal;
      leftCount++);
  // leftCount is no of nodes of left tree
  rightCount = postLength-leftCount-1;
  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootVal);
  root->left = getTreeFromPostorderAndInorder(postorder,leftCount,inorder,leftCount);
  root->right = getTreeFromPostorderAndInorder(postorder+leftCount,rightCount,
      inorder+leftCount+1,rightCount);
  return root;
}

bool isBalanced(BinaryTreeNode<int> *root) {
  /* Given a binary tree, check if its balanced i.e. depth of left and right
   * subtrees of every node differ by at max 1. Return true if given binary
   * tree is balanced, false otherwise. */
  if(root==nullptr) return true;
  int left = depth(root->left);
  int right = depth(root->right);
  int diff = abs(left-right);
  if(diff>1) return false;
  if(!isBalanced(root->left)) return false;
  if(!isBalanced(root->right)) return false;
  return true;
}

void printLevelATNewLine(BinaryTreeNode<int> *root) {
  /* Given a binary tree, print the level order traversal. Make sure each level
   * start in new line.*/
  if(root==nullptr) return;
  queue<BinaryTreeNode<int>*> *inputQ, *outputQ, *temp;
  inputQ = new queue<BinaryTreeNode<int>*>();
  outputQ = new queue<BinaryTreeNode<int>*>();
  inputQ->push(root);
  do
  {
    while(!inputQ->empty())
    {
      BinaryTreeNode<int> *curr = inputQ->front();
      inputQ->pop();
      cout << curr->data << ' ';
      if(curr->left!=nullptr)
        outputQ->push(curr->left);
      if(curr->right!=nullptr)
        outputQ->push(curr->right);
    }
    cout << endl;
    temp = inputQ;
    inputQ = outputQ;
    outputQ = temp;
  } while(!inputQ->empty());
  // Clean up: delete queues created on heap
  delete inputQ;
  delete outputQ;
}

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
  /* Remove all leaf nodes from a given Binary Tree. Leaf nodes are those
   * nodes, which don't have any children. */
  if(root==nullptr) return nullptr;
  if(root->left==nullptr && root->right==nullptr)
  {
    delete root;
    return nullptr;
  }
  root->left = removeLeafNodes(root->left);
  root->right = removeLeafNodes(root->right);
  return root;
}

vector<node<int>*> createLLForEachLevel(BinaryTreeNode<int> *root) {
  /* Given a binary tree, write code to create a separate linked list for each
   * level. You need to return the array which contains head of each level
   * linked list. */
  vector<node<int>*> result;
  if(root==nullptr) return result;
  queue<BinaryTreeNode<int>*> *inputQ, *outputQ, *temp;
  inputQ = new queue<BinaryTreeNode<int>*>();
  outputQ = new queue<BinaryTreeNode<int>*>();
  inputQ->push(root);
  /* Here we want to add a link list into result */
  node<int> *ptr = new node<int>(root->data);
  ptr->next=nullptr;
  result.push_back(ptr);
  do
  {
    //nodelist<int> *list = new nodelist<int>();
    nodelist<int> list;
    while(!inputQ->empty())
    {
      BinaryTreeNode<int> *curr = inputQ->front();
      inputQ->pop();
      if(curr->left!=nullptr)
      {
        outputQ->push(curr->left);
        ptr = new node<int>(curr->left->data);
        list.pushnode(ptr);
      }
      if(curr->right!=nullptr)
      {
        outputQ->push(curr->right);
        ptr = new node<int>(curr->right->data);
        list.pushnode(ptr);
      }
    }
    temp = inputQ;
    inputQ = outputQ;
    outputQ = temp;
    result.push_back(list.start);
  } while(!inputQ->empty());
  // Clean up: delete queues created on heap
  delete inputQ;
  delete outputQ;
  return result;
}

void zigZagOrder(BinaryTreeNode<int> *root) {
  /* Given a binary tree, print the zig zag order i.e print level 1 from left
   * to right, level 2 from right to left and so on. This means odd levels
   * should get printed from left to right and even level right to left. */
  vector<node<int>*> v = createLLForEachLevel(root);
  int size= v.size();
  for(int i=0; i<size; i++)
  {
    node<int> *list = v[i];
    if(i%2==0)
    {
      /* Print the list in forward order */
      while(list!=nullptr)
      {
        cout << list->data << ' ';
        list = list->next;
      }
      cout << endl; 
    }
    else
    {
      vector<int> stack;
      /* Print the list in backward order */
      while(list!=nullptr)
      {
        stack.push_back(list->data);
        list = list->next;
      }
      for(int j=stack.size()-1; j>=0; j--)
        cout << stack[j] << ' ';
      cout << endl; 
    }
  }
}

void nodesWithoutSibling(BinaryTreeNode<int> *root) {
  /* Given a binary tree, print all nodes that don’t have a sibling. Print the
   * elements in different lines. And order of elements doesn't matter. */
  if(root==nullptr) return;
  if(root->left==nullptr && root->right!=nullptr)
  {
    /* right node has no sibling. Print right node and call recursion */
    cout << root->right->data << endl;
    nodesWithoutSibling(root->right);
    return;
  }
  if(root->left!=nullptr && root->right==nullptr)
  {
    /* left node has no sibling. Print left node and call recursion */
    cout << root->left->data << endl;
    nodesWithoutSibling(root->left);
    return;
  }
  nodesWithoutSibling(root->right);
  nodesWithoutSibling(root->left);
}


int getArray(int arr[], int size)
{
  cin >> size;
  // Read the array
  for(int j=0;j<size;++j) 
    cin >> arr[j];
  return size;
}

void updateMap(BinaryTreeNode<int>* root, int level,
    unordered_map<int, queue<int> > &map)
{
  if(root==nullptr) return;
  map[level].push(root->data);
  updateMap(root->left, level-1, map);
  updateMap(root->right, level+1, map);
}

void printBinaryTreeVerticalOrder(BinaryTreeNode<int>* root)
{
  /* Print the binary tree in vertical order */
  unordered_map<int, queue<int> > map;
  updateMap(root, 0, map);
  unordered_map<int, queue<int> > :: iterator it = map.begin();
  while(it != map.end()){
    queue<int>& q=it->second;
    while(!q.empty())
    {
      cout << q.front() << ' ';
      q.pop();
    }
    cout << endl;
    it++;
  }
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

bool find(BinaryTreeNode<int>* root, int x, vector<BinaryTreeNode<int>*>& v) {
  /* Given a Binary Tree and an integer x, check if node with data x is present
   * in the input binary tree or not. Return true or false.*/
  if(root==nullptr) return false;
  v.push_back(root);
  if(root->data == x) return true;
  if(find(root->left, x, v)) return true;
  if(find(root->right, x, v)) return true;
  v.pop_back();
  return false;
}

void printNodesatDistanceK(BinaryTreeNode<int> *root, int k)
{
  if(root==nullptr || k<0) return;
  if(k==0)
  {
    cout << root->data << endl;
    return;
  }
  printNodesatDistanceK(root->left, k-1);
  printNodesatDistanceK(root->right, k-1);
}
int nodesAtDistanceKH(BinaryTreeNode<int> *root, int node, int k) {
  if(root==nullptr || k<0) return -1;
  if(root->data==node) {
    printNodesatDistanceK(root, k);
    return 0;
  }
  int distance = nodesAtDistanceKH(root->left, node, k);
  if(distance != -1) {
    // node found in left subtree
    if(distance+1==k) cout << root->data << endl;
    printNodesatDistanceK(root->right, k-distance-2);
    return distance+1;
  }
  distance = nodesAtDistanceKH(root->right, node, k);
  if(distance != -1) {
    // node found in right subtree
    if(distance+1==k) cout << root->data << endl;
    printNodesatDistanceK(root->left, k-distance-2);
    return distance+1;
  }
  return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
  nodesAtDistanceKH(root, node, k);
}
void nodesAtDistanceKOld(BinaryTreeNode<int> *root, int k) {
  /* Given a binary tree, a node and an integer K, print nodes which are at
   * K distance from the the given node. */
  if(root==nullptr || k<0) return;
  vector<BinaryTreeNode<int>*> v;
  //if(find(root, node, v)==false) return;  // Node doesn't exist
  BinaryTreeNode<int> *curr = v.back(), *parent=nullptr, *sibling;
  nodesAtDistanceKOld(curr,k);
  int distance = 0;
  while(!v.empty() && distance<k)
  {
    curr = v.back();
    v.pop_back();
    if(v.empty()) break;
    parent = v.back();
    if(parent->left==curr)
      sibling = parent->right;
    else 
      sibling = parent->left;
    distance += 2;
    nodesAtDistanceKOld(sibling,k-distance);
  }
  if(parent)
    cout << parent->data << endl;
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
  /* Given a binary search tree and a integer S, find pair of nodes in the BST
   * which sum to S. You can use extra space only O(log n). */
}

int main()
{
  static int maxNodeCount = 100;
  int nodeCount, preOrder[maxNodeCount], inOrder[maxNodeCount],
     postOrder[maxNodeCount];
  nodeCount = getArray(preOrder,maxNodeCount);
  BinaryTreeNode<int>* root = buildLevelTree(preOrder, nodeCount);
  printBinaryTreeVerticalOrder(root);
  //nodeCount = getArray(inOrder,maxNodeCount);
  //BinaryTreeNode<int>* root=buildTree(preOrder,nodeCount,inOrder,nodeCount);
  //BinaryTreeNode<int>* root=getTreeFromPostorderAndInorder(preOrder,nodeCount,inOrder,nodeCount);
  //vector<node<int>*> v = createLLForEachLevel(root);
}
