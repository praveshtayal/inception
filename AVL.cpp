#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

template <typename T>
class BinaryTreeNode {
    public : 
    T data;
    int bf;  // This is only calculated in height function. Thus most of the
             // time this value is incorrect.
             // Note that we call rotate function after height function is 
             // called. And rotate function uses this value, which is correct.
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T _data=0)
        : data(_data), bf(0), left(nullptr), right(nullptr)
    {
    }
};

class AVL {
  public:
    AVL()
      :AVLroot(nullptr)
    {
    }
    ~AVL()
    {
        if(AVLroot) {
            delete AVLroot->left;
            delete AVLroot->right;
            delete AVLroot;
        }
    }
    void insert(int data)
    {
        insert(AVLroot, data);
    }
    bool deleteData(int value)
    {
      if(AVLroot==nullptr) return false;
      BinaryTreeNode<int> *curr=AVLroot, *prev=nullptr;
      while(curr!=nullptr && curr->data != value)
      {
        prev = curr;
        if(value<curr->data)
          curr = curr->left;
        else
          curr = curr->right;
      }
      // value not found
      if(curr==nullptr) return false;
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
        return true;
      }
      // At least One subtree is empty
      if(curr->left)
      {
        // Right subtree is empty
        BinaryTreeNode<int> *temp = curr->left;
        if(prev==nullptr)
        {
            // We are deleting the root node
            AVLroot = temp;
            curr->left = curr->right = nullptr; delete curr;
            return true;
        }
        if(prev->left==curr) prev->left = temp;
        else prev->right = temp;
        curr->left = curr->right = nullptr; delete curr;
        return true;
      }
      BinaryTreeNode<int> *temp = curr->right;
      if(prev==nullptr)
      {
          // We are deleting the root node
          AVLroot = temp;
          curr->left = curr->right = nullptr; delete curr;
          return true;
      }
      if(prev->left==curr) prev->left = temp;
      else prev->right = temp;
      curr->left = curr->right = nullptr; delete curr;
      return true;
    }

    bool hasData(int value) const
    {
      if(AVLroot==nullptr) return false;
      BinaryTreeNode<int> *curr=AVLroot, *prev=AVLroot;
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
      printTree(AVLroot);
    }
  private:
    BinaryTreeNode<int> *AVLroot;
    void printTree(BinaryTreeNode<int> *root) const
    {
      if(root==nullptr) return;
      printTree(root->left);
      cout << root->data << ':';
      if(root->left) cout << "L:" << root->left->data << ",";
      if(root->right) cout << "R:" << root->right->data;
      cout << endl;
      printTree(root->right);
    }
    int height(BinaryTreeNode<int>* root)
    {
        if(root==nullptr) return 0;
        int hl = height(root->left);
        int hr = height(root->right);
        root->bf = hl-hr;
        return max(hl, hr) + 1;
    }
    BinaryTreeNode<int>* rotateLL(BinaryTreeNode<int>* root)
    {
        cout << "Calling rotateLL on " << root->data << endl;
        BinaryTreeNode<int>* left = root->left;
        BinaryTreeNode<int>* balancedRight = left->right;
        root->left = balancedRight;
        left->right = root;
        return left;
    }
    BinaryTreeNode<int>* rotateRR(BinaryTreeNode<int>* root)
    {
        cout << "Calling rotateRR on " << root->data << endl;
        BinaryTreeNode<int>* right = root->right;
        BinaryTreeNode<int>* balancedLeft = right->left;
        root->right = balancedLeft;
        right->left = root;
        return right;
    }
    BinaryTreeNode<int>* rotateLR(BinaryTreeNode<int>* root)
    {
        cout << "Calling rotateLR on " << root->data << endl;
        BinaryTreeNode<int>* left = root->left;
        BinaryTreeNode<int>* right = left->right;
        BinaryTreeNode<int>* balancedLeft = right->left;
        BinaryTreeNode<int>* balancedRight = right->right;
        left->right = balancedLeft;
        root->left = balancedRight;
        right->left = left;
        right->right = root;
        return right;
    }
    BinaryTreeNode<int>* rotateRL(BinaryTreeNode<int>* root)
    {
        cout << "Calling rotateRL on " << root->data << endl;
        BinaryTreeNode<int>* right = root->right;
        BinaryTreeNode<int>* left = right->left;
        BinaryTreeNode<int>* balancedLeft = left->left;
        BinaryTreeNode<int>* balancedRight = left->right;
        right->left = balancedRight;
        root->right = balancedLeft;
        left->left = root;
        left->right = right;
        return left;
    }
    BinaryTreeNode<int>* rotate(BinaryTreeNode<int>* root)
    {
        //cout << "Calling rotate on " << root->data << endl;
        if(root->bf==-2)
        {
            if(root->right->bf==-1)
                root = rotateRR(root);
            else
                root = rotateRL(root);
        }
        else
        {
            if(root->left->bf==-1)
                root = rotateLR(root);
            else
                root = rotateLL(root);
        }
        
        return root;
    }
    // true represents Rotation is already done. Thus, we dont need to
    // calculate height and do rotation.
    // false reprsents Rotation is not done yet.
    bool insert(BinaryTreeNode<int>* &root, int data)
    {
        if(root==nullptr) {
            root = new BinaryTreeNode<int>(data);
            return false;
        }
        bool rotated = false;
        if(root->data < data) {
            rotated = insert(root->right, data);
        }
        else {
            rotated = insert(root->left, data);
        }

        if(rotated) return true;
        int ht = height(root);
        if(root->bf < -1 || 1 < root->bf)
        {
            root = rotate(root);
            return true;
        }

        return rotated;
    }
};

int main()
{
    AVL *tree = new AVL();
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
                break;
        }
    }  
}
