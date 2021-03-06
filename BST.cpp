#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <list>
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

bool isBSTandInRange(BinaryTreeNode<int> *root, int min, int max){
    /* Given a binary tree with N number of nodes, check if that input tree is
     * BST (Binary Search Tree) or not. If yes, return true, return false
     * otherwise. Duplicate elements should be in right subtree. */
    if(root==nullptr) return true;
    if(min > root->data || root->data > max) return false;
    if(!isBSTandInRange(root->left, min, root->data-1)) return false;
    if(!isBSTandInRange(root->right, root->data, max)) return false;
    return true;
}
bool isBST2(BinaryTreeNode<int> *root){
    return isBSTandInRange(root, INT_MIN, INT_MAX);
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

bool inOrder(BinaryTreeNode<int> *root, int& prevValue){
    if(root==nullptr) return true;
    if(false==inOrder(root->left, prevValue)) return false;
    if(root->data < prevValue) return false;
    prevValue = root->data;
    return inOrder(root->right, prevValue);
}

bool isBST(BinaryTreeNode<int> *root){
    /* Another approach where we check if inorder traversal is ascending */
    int prevValue=INT_MIN;
    return inOrder(root, prevValue);
}

bool findPathBinaryTree(BinaryTreeNode<int> *root , int data, vector<int>& v){
    /* Given a Binary Tree and integer k. Find and return path from the node with
     * data k and root (if a node with data k is present in given BST). Return
     * null otherwise. Assume that BST contains all unique elements. */
    if(root==nullptr) return false;
    v.push_back(root->data);
    if(root->data==data)
        return true;
    bool left = findPathBinaryTree(root->left, data, v);
    if(left == true) return true;
    bool right = findPathBinaryTree(root->right, data, v);
    if(right == true) return true;
    v.pop_back();
    return false;
}

vector<int>* findPath(BinaryTreeNode<int> *root , int data){
    /* Given a BST and an integer k. Find and return the path from the node with
     * data k and root (if a node with data k is present in given BST). Return
     * null otherwise. Assume that BST contains all unique elements. */
    vector<int>* path = new vector<int>;
    while(root!=nullptr)
    {
        path->push_back(root->data);
        if(root->data==data)
        {
            reverse(path->begin(),path->end());
            return path;
        }
        else if(root->data<data)
            root = root->right;
        else
            root = root->left;
    }
    delete path;
    return nullptr;
}

void insertDuplicateNode(BinaryTreeNode<int> *root) {
    /* Given a BST with N number of nodes, for each node create a new duplicate
     * node, and insert that duplicate as left child of the original node.*/
    if(root==nullptr) return;
    BinaryTreeNode<int>* node = new BinaryTreeNode<int>(root->data);
    node->left = root->left;
    root->left = node;
    insertDuplicateNode(node->left);
    insertDuplicateNode(root->right);
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

void updateMap(BinaryTreeNode<int>* root, unordered_map<int, int> &map)
{
    if(root==nullptr) return;
    map[root->data] = 1;
    updateMap(root->left, map);
    updateMap(root->right, map);
}

void nodesSumToS(BinaryTreeNode<int> *root, int sum) {
    /* Given a binary tree and an integer S, print all the pair of nodes whose
     * sum equals S. Assume binary tree contains all unique elements. Note : In
     * a pair, print the smaller element first. Order of different pair doesn't
     * matter.*/
    unordered_map<int, int> map;
    updateMap(root, map);
    unordered_map<int, int>:: iterator it = map.begin();
    while(it != map.end()){
        if( (it->first<=sum-it->first) && (map.count(sum-it->first)) )
            cout << it->first << ' ' << sum-it->first << endl;
        it++;
    }
}

void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k, vector<int>& v) {
    if(root==nullptr) return;
    if(root->left==nullptr && root->right==nullptr)
    {
        // Reached leaf node
        if(root->data==k)
        {
            //ostream_iterator<int> out(cout, " ");
            //copy(v.begin(), v.end(), out);
            copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
            // for(int i=0; i<v.size(); i++)
            //  cout << v[i] << ' ';
            cout << k << endl;
        }
        return;
    }
    v.push_back(root->data);
    rootToLeafPathsSumToK(root->left, k-root->data, v);
    rootToLeafPathsSumToK(root->right, k-root->data, v);
    v.pop_back();
}

void rootToLeafPathsSumToKIterative(BinaryTreeNode<int> *root, int k) {
    /* Given a binary tree and a number k, print out all root to leaf paths where
     * the sum of all nodes value is same as the given number k. */
    /* Here we will traverse the tree is inorder using stack */
    // if(root==nullptr) return; This check is not required
    vector<BinaryTreeNode<int> *> s, path;
    do {
        while(root!=nullptr) {
            s.push_back(root);
            path.push_back(root);
            root = root->left;
        }
        if(!s.empty())
        {
            root = s.back();
            s.pop_back();
            if(root->right==nullptr)
            {
                // root is leaf node, calculate sum
                int sum = 0;
                for(int i=0; i<path.size(); i++)
                    sum += path[i]->data;
                if(sum==k)
                {
                    for(int i=0; i<path.size(); i++)
                        cout << path[i]->data << ' ';
                    cout << endl;
                }
                // pop from path untill path is s
                if(!s.empty())
                {
                    while(path.back()!=s.back())
                        path.pop_back();
                }
            }
            root = root->right;
        }
    } while(!s.empty() || root!=nullptr);
}

int getArray(int arr[], int size)
{
    cin >> size;
    // Read the array
    for(int j=0;j<size;++j) 
        cin >> arr[j];
    return size;
}

bool largestBSTSubtree(BinaryTreeNode<int>*root, int&minV, int&maxV, int& ht) {
    // If function return true, subtree is BST with ht, minV and maxV updated
    // If function returns false, subtree is not BST but ht has max height of BST
    if(root==nullptr) {
        minV = INT_MAX; maxV = INT_MIN; ht = 0;
        return true;
    }
    if(root->left==nullptr && root->right==nullptr) {
        ht = 1; minV = root->data; maxV = root->data;
        return true;
    }
    int minLeft, maxLeft, htLeft;
    bool left = largestBSTSubtree(root->left, minLeft, maxLeft, htLeft); 
    int minRight, maxRight, htRight;
    bool right = largestBSTSubtree(root->right, minRight, maxRight, htRight); 
    if(left && right)
    {
        if(maxLeft < root->data && root->data <= minRight) {
            // We have a BST
            minV = minLeft; maxV = maxRight; ht = max(htLeft,htRight)+1;
            return true;
        }
    }

    ht = max(htLeft,htRight);
    return false;
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    /* Given a Binary tree, find the largest BST subtree. That is, you need to
     * find the BST with maximum height in the given binary tree. */
    int minV, maxV,  ht;
    largestBSTSubtree(root, minV, maxV, ht);
    return ht;
}

int replaceWithLargerNodesSum(BinaryTreeNode<int> *root, int increment) {
    if(root==nullptr) return 0;
    int sumRight = replaceWithLargerNodesSum(root->right, increment);
    int rootData = root->data;
    root->data += sumRight + increment;
    int sumLeft = replaceWithLargerNodesSum(root->left, root->data);
    return sumLeft + rootData + sumRight;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    /* Given a binary search tree, replace each nodes' data with the sum of all
     * nodes' which are greater or equal than it. You need to include the current
     * node's data also. 
     * That is, if in given BST there is a node with data 5, you need to replace
     * it with sum of its data (i.e. 5) and all nodes whose data is greater than
     * or equal to 5.*/
    replaceWithLargerNodesSum(root, 0);
}

/* This is my understanding of problem */
void replaceWithLargerNodesSumPravesh(BinaryTreeNode<int> *root) {
    /* Given a binary search tree, replace each nodes' data with the sum of all
     * nodes' which are greater or equal than it. You need to include the current
     * node's data also. 
     * That is, if in given BST there is a node with data 5, you need to replace
     * it with sum of its data (i.e. 5) and all nodes whose data is greater than
     * or equal to 5.*/
    if(root==nullptr) return;
    replaceWithLargerNodesSum(root->left);
    if(root->right)
    {
        replaceWithLargerNodesSum(root->right);
        root->data += root->right->data;
    }
}

void printNodesSumToS(BinaryTreeNode<int>*root,BinaryTreeNode<int>*node,int s){
}

void printNodesSumToS(BinaryTreeNode<int> *root, int s) {
    /* Given a binary search tree and a integer S, find pair of nodes in the BST
     * which sum to S. You can use extra space only O(log n).
     * Assume BST contains all unique elements.
     * Note : In a pair, print the smaller element first with utput format : Each
     * pair in different line (pair elements separated by space) */
    if(root==nullptr) return;
    int pair = s - root->data;
    if(pair<root->data && searchInBST(root->left, pair)!=nullptr )
        cout << pair << ' ' << root->data << endl;
    if(pair>=root->data && searchInBST(root->right, pair)!=nullptr )
        cout << root->data << ' ' << pair << endl;
}


int main()
{
    static int maxNodeCount = 1000;
    int nodeCount, levelOrder[maxNodeCount];
    nodeCount = getArray(levelOrder,maxNodeCount);
    BinaryTreeNode<int>* root=buildLevelTree(levelOrder, nodeCount);
    int val1, val2;
    //cin >> val1 >> val2; cout << lcaBinaryTree(root, val1, val2) << endl;
    cin >> val1; rootToLeafPathsSumToKIterative(root, val1);
}
