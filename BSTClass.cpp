#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

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
    ~BinaryTreeNode() {
      delete left;
      delete right;
    }
};

class BST {
  public:
    BST()
      :root(nullptr)
    {
    }
    ~BST()
    {
      delete root;
    }
    void insert(int value)
    {
      BinaryTreeNode<int> *node = new BinaryTreeNode<int>(value);
      if(root==nullptr)
      {
        root = node;
        return;
      }
      BinaryTreeNode<int> *curr=root, *prev=root;
      while(curr!=nullptr)
      {
        prev = curr;
        if(value<curr->data)
          curr = curr->left;
        else
          curr = curr->right;
      }
      // prev will have node as child
      if(value < prev->data)
        // prev->left is nullptr
        prev->left = node;
      else 
        // prev->right is nullptr
        prev->right = node;
    }
    void deleteData(int value)
    {
      if(root==nullptr) return false;
      BinaryTreeNode<int> *curr=root, *prev=root;
      while(curr!=nullptr && curr->data != value)
      {
        prev = curr;
        if(value<curr->data)
          curr = curr->left;
        else
          curr = curr->right;
      }
      // value not found
      if(curr==nullptr) return;
      // we have to delete node curr
      if(curr->left && curr->right)
      {
        // Special case where both subtrees of node to deleted exist
        // We can delete either largest of left subtree or 
        // smallest of right subtree. And replace the contents of curr
        // with content of deleted node. Here, we are deleting smallest
        // of right subtree.
        BinaryTreeNode<int> *temp = curr->right;
        int smallest = temp->data;
        while(temp!=nullptr)
        {
          smallest = temp->data;
          temp = temp->left;
        }
        deleteData(smallest);
        curr->data = smallest;
        return;
      }
      // At least One subtree is empty
      if(curr->left)
      {
        // Right subtree is empty
        BinaryTreeNode<int> *temp = curr->left;
        if(prev->left==curr) prev->left = temp;
        else prev->right = temp;
        delete curr;
        return;
      }
      BinaryTreeNode<int> *temp = curr->right;
      if(prev->left==curr) prev->left = temp;
      else prev->right = temp;
      delete curr;
    }

    bool hasData(int value) const
    {
      if(root==nullptr) return false;
      BinaryTreeNode<int> *curr=root, *prev=root;
      while(curr!=nullptr && curr->data != value)
      {
        prev = curr;
        if(value<curr->data)
          curr = curr->left;
        else
          curr = curr->right;
      }
      // prev will have node as child
      if(curr==nullptr) return false;
      return true;
    }
    void printTree() const
    {
      printTree(root);
    }
  private:
    BinaryTreeNode<int> *root;
    void printTree(BinaryTreeNode<int> *root) const
    {
      if(root==nullptr) return;
      cout << root->data << ':';
      if(root->left) cout << "L:" << root->left->data << ",";
      if(root->right) cout << "R:" << root->right->data;
      cout << endl;
      printTree(root->left);
      printTree(root->right);
    }

};

int main()
{
    BST *tree = new BST();
    int choice, input;
    while(true){
        cin>>choice;
        switch(choice){
            case 1:
                cin >> input;
                tree->insert(input);
                break;
            case 2:
                cin >> input;
                tree->deleteData(input);
                break;
            case 3:
                cin >> input;
                if(tree->hasData(input)) {
                    cout << "true" << endl;
                }
                else {
                    cout << "false" << endl;
                }
                break;
            default:
                tree->printTree();
                return 0;
                break;
        }
    }  
}
