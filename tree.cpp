#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
class TreeNode {
public:
    T data;
    vector<TreeNode<T>*> children;
    
    TreeNode(T data) {
        this->data = data;
    }
    
    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

void printLevelWise(TreeNode<int>* root) {
  if(root==nullptr) return;
  queue<TreeNode<int>*> q;
  q.push(root);
  while(!q.empty())
  {
    TreeNode<int> *curr = q.front();
    q.pop();
    cout << curr->data << ':';
    int childCount = curr->children.size();
    if(childCount)
    {
      cout << curr->children[0]->data;
      q.push(curr->children[0]);
    }
    for(int i=1; i<childCount; i++)
    {
      cout << ',' <<  curr->children[i]->data; 
      q.push(curr->children[i]);
    }
    cout << endl;
  }
}

int countOfNodes(TreeNode<int>* root) {
  if(root==nullptr) return 0;
  int result = 1; // root node
  int childCount = root->children.size();
  for(int i=0; i<childCount; i++)
    result += countOfNodes(root->children[i]);
  return result;
}

int sumOfNodes(TreeNode<int>* root) {
  if(root==nullptr) return 0;
  int result = root->data; // root node
  int childCount = root->children.size();
  for(int i=0; i<childCount; i++)
    result += sumOfNodes(root->children[i]);
  return result;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
  if(root==nullptr) return nullptr;
  TreeNode<int> *result = root; // root node
  int max = root->data; // root node
  int childCount = root->children.size();
  for(int i=0; i<childCount; i++)
  {
    TreeNode<int> *temp = maxDataNode(root->children[i]);
    if(temp->data > max)
    {
      max = temp->data;
      result = temp;
    }
  }
  return result;
}

void postOrder(TreeNode<int>* root) {
  if(root==nullptr) return;
  int result = root->data; // root node
  int childCount = root->children.size();
  for(int i=0; i<childCount; i++)
    postOrder(root->children[i]);
  cout << root->data << ' ';
}

int sumNode(TreeNode<int> *root){
  if(root==nullptr) return 0;
  int sum = root->data; // Calculate sumNode for root Node
  int childCount = root->children.size();
  for(int i=0; i<childCount; i++)
    sum += root->children[i]->data;
  return sum;
}

TreeNode<int>* maxSumNode(TreeNode<int> *root){
  /* Given a tree, find and return the node for which sum of data of all its
   * immideate children and the node itself is maximum. In the sum, data of node
   * itself and data of immediate children is to be taken. */
  /* Solution: We need to traverse all the nodes and calculate the Sum for each
   * Node. Also, we can check if maximum Sum is greater than maximum calculated
   * till now. Here we are using post Order Traversal but we may use any
   * traversal technique. */
  if(root==nullptr) return nullptr;
  TreeNode<int> *result = root; // root node
  int maxSum = sumNode(root); // Calculate sumNode for root Node
  int childCount = root->children.size();
  for(int i=0; i<childCount; i++)
  {
    TreeNode<int> *temp = maxSumNode(root->children[i]);
    int sum = sumNode(temp);
    if(sum > maxSum)
    {
      maxSum = sum;
      result = temp;
    }
  }
  return result;
}

bool isIdentical(TreeNode<int> *root1, TreeNode<int> * root2) {
  /* Given two Generic trees, return true if they are structurally identical
   * i.e. they are made of nodes with the same values arranged in the same
   * way.*/
  if(root1==nullptr)
  {
    if(root2==nullptr) return true;
    else return false;
  }
  /* Both root1 and root2 are non null */
  if(root1->data != root2->data) return false;
  int childCount1 = root1->children.size();
  int childCount2 = root2->children.size();
  if(childCount1 != childCount2) return false;
  for(int i=0; i<childCount1; i++)
    if(!isIdentical(root1->children[i],root2->children[i]))
      return false;
  return true;
}

void replaceWithDepthValueHelper(TreeNode<int> *root, int value){
  if(root==nullptr) return;
  root->data = value; // root node
  int childCount = root->children.size();
  for(int i=0; i<childCount; i++)
    replaceWithDepthValueHelper(root->children[i],value+1);
}
void replaceWithDepthValue(TreeNode<int> *root){
    replaceWithDepthValueHelper(root,0);
}
