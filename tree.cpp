#include <iostream>
#include <vector>
#include <queue>
#define THOUSAND 1000
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

TreeNode<int> *makeTree(int arr[], int size) {
    if(arr==nullptr || size<=0) return nullptr;
    int i=0;
    queue<TreeNode<int>*> q;
    TreeNode<int> *root = new TreeNode<int>(arr[i++]);
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int> *curr = q.front();
        q.pop();
        int child = arr[i++];
        for(int j=0;j<child;j++)
        {
            TreeNode<int> *node = new TreeNode<int>(arr[i++]);
            curr->children.push_back(node);
            q.push(node);
        }
    }

    return root;
}

void printLevelWise(TreeNode<int>* root) {
    /* Given a generic tree, print the input tree in level wise order. ####For
     * printing a node with data N, you need to follow the exact format:
     * N:x1,x2,x3,...,xn
     * wherer, N is data of any node present in the binary tree. x1, x2, x3,
     * ...., xn are the children of node N. There is no space in between. You
     * need to print all nodes in the level order form in different lines.
     * Input: 10 3 20 30 40 2 40 50 0 0 0 0 
     * 10:20,30,40
     * 20:40,50
     * 30:
     * 40:
     * 40:
     * 50:
     * */
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
    /* Given a generic tree, count and return the total number of nodes present
     * in the given tree.*/
    if(root==nullptr) return 0;
    int result = 1; // root node
    int childCount = root->children.size();
    for(int i=0; i<childCount; i++)
        result += countOfNodes(root->children[i]);
    return result;
}

int sumOfNodes(TreeNode<int>* root) {
    /* Given a generic tree, count and return the sum of all nodes present in the
     * given tree.*/
    if(root==nullptr) return 0;
    int result = root->data; // root node
    int childCount = root->children.size();
    for(int i=0; i<childCount; i++)
        result += sumOfNodes(root->children[i]);
    return result;
}

TreeNode<int>* maxDataNode(TreeNode<int>* root) {
    /* Given a generic tree, find and return the node with maximum data. You need
     * to return the complete node which is having maximum data. Return null if
     * tree is empty. */
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

void printNodesAtDepthK(TreeNode<int>* root, int k) {
    /* Given a generic tree and an integer k, print all the nodes which are at
     * depth k. Root is at depth 0. */
    if(root==nullptr || k<0) return;
    if(k==0)  /* Base Case */
    {
        cout << root->data << ' ';
        return;
    }
    int childCount = root->children.size();
    for(int i=0; i<childCount; i++)
        printNodesAtDepthK(root->children[i], k-1);
}

int nodesGreaterThanX(TreeNode<int> *root, int x) {
    /* Given a tree and an integer x, find and return number of Nodes which are
     * greater than x.*/
    if(root==nullptr) return 0;
    int result = 0;
    if(root->data>x) result++;
    int childCount = root->children.size();
    for(int i=0; i<childCount; i++)
        result += nodesGreaterThanX(root->children[i], x);
    return result;
}

int numLeafNodes(TreeNode<int>* root) {
    /* Given a generic tree, count and return the number of leaf nodes present in
     * the given tree.*/
    if(root==nullptr) return 0;
    int childCount = root->children.size();
    if(childCount==0) return 1;  // Base case

    int result = 0;
    for(int i=0; i<childCount; i++)
        result += numLeafNodes(root->children[i]);
    return result;
}

void postOrder(TreeNode<int>* root) {
    /* post Order Traversal recursive */
    if(root==nullptr) return;
    int result = root->data; // root node
    int childCount = root->children.size();
    for(int i=0; i<childCount; i++)
        postOrder(root->children[i]);
    cout << root->data << ' ';
}

bool containsX(TreeNode<int>* root, int x) {
    /* Given a generic tree and an integer x, check if x is present in the given
     * tree or not. Return true if x is present, return false otherwise. */
    if(root==nullptr) return false;
    if(root->data==x) return true;
    int childCount = root->children.size();
    for(int i=0; i<childCount; i++)
        if(containsX(root->children[i], x)) return true;
    return false;
}

int sumNode(TreeNode<int> *root){
    /* Called by maxSumNode */
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

TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    /* Given a generic tree and an integer n. Find and return the node with next
     * larger element in the Tree i.e. find a node with value just greater than
     * n. */
    /* Solution: We need to traverse all the nodes and check for next larger
     * Node. Here we are using post Order Traversal but we may use any
     * traversal technique. */
    if(root==nullptr) return nullptr;
    int childCount = root->children.size();
    if(childCount==0) // Base Case
    {
        if(root->data>n) return root; // Found node with value greater than n
        return nullptr;
    }
    TreeNode<int> *result = nullptr;
    if(root->data>n) result=root; // Found node with value greater than n
    for(int i=0; i<childCount; i++)
    {
        TreeNode<int> *temp = nextLargerElement(root->children[i], n);
        if(temp==nullptr) continue;
        if(result==nullptr || result->data>temp->data)
            result = temp;
    }
    return result;
}

TreeNode<int>* nextLargerElement2(TreeNode<int> *root, int n) {
    /* Given a generic tree and an integer n. Find and return the node with next
     * larger element in the Tree i.e. find a node with value just greater than
     * n. */
    if(root==nullptr) return nullptr;
    if(root->data>n) return root;
    int childCount = root->children.size();
    TreeNode<int> *result;
    for(int i=0; i<childCount; i++)
        if((result=nextLargerElement(root->children[i], n))!=nullptr)
            return result;

    return nullptr;
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    /* Given a generic tree, find and return the node with second largest value
     * in given tree. Return NULL if no node with required value is present. */
    if(root==nullptr) return nullptr;
    int childCount = root->children.size();
    if(childCount==0) return nullptr;

    // we have atleast two nodes: root node and one child node
    TreeNode<int> *largest = root, *secLargest=root->children[0];
    if(largest->data<secLargest->data)
    {
        secLargest = root;
        largest=root->children[0];
    }
    queue<TreeNode<int>*> q;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int> *curr = q.front();
        q.pop();
        childCount = curr->children.size();
        for(int i=0; i<childCount; i++)
        {
            q.push(curr->children[i]);
            if(curr->children[i]->data > secLargest->data)
            {
                if(curr->children[i]->data > largest->data)
                {
                    secLargest = largest;
                    largest = curr->children[i];
                }
                else
                {
                    secLargest = curr->children[i];
                }
            }
        }
    }
    return secLargest;
}

void replaceWithDepthValueHelper(TreeNode<int> *root, int value){
    /* In a given Generic Tree, replace each node with its depth value. You need
     * to just update the data of each node, no need to return or print anything.
     * */
    if(root==nullptr) return;
    root->data = value; // root node
    int childCount = root->children.size();
    for(int i=0; i<childCount; i++)
        replaceWithDepthValueHelper(root->children[i],value+1);
}

void replaceWithDepthValue(TreeNode<int> *root){
    /* In a given Generic Tree, replace each node with its depth value. You need
     * to just update the data of each node, no need to return or print anything.
     * */
    replaceWithDepthValueHelper(root,0);
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
    int arr[THOUSAND];
    int n = getArray(arr, THOUSAND);
    TreeNode<int> *root = makeTree(arr, n);
    TreeNode<int> *temp = secondLargest(root);
    cout << temp->data;
    return 0;
}
