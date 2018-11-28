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
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode(T _data=0);

};

template <typename T>
BinaryTreeNode<T>::BinaryTreeNode(T _data)
    : data(_data), bf(0), left(nullptr), right(nullptr)
{
}

class AVL {
    public:
        AVL();
        ~AVL();
        void insert(int data);
        bool deleteData(int value);
        bool hasData(int value) const;
        void printTree() const; // Inorder along with child info
    private:
        BinaryTreeNode<int> *AVLroot;

        bool insert(BinaryTreeNode<int>* &root, int data);
        bool deleteData(BinaryTreeNode<int>* &root, int value);
        bool deleteDataRec(BinaryTreeNode<int>* &root, int value);
        void printTree(BinaryTreeNode<int> *root) const;
        int height(BinaryTreeNode<int>* root) const;
        // Functions for roations used by insert
        BinaryTreeNode<int>* rotateLL(BinaryTreeNode<int>* root);
        BinaryTreeNode<int>* rotateRR(BinaryTreeNode<int>* root);
        BinaryTreeNode<int>* rotateLR(BinaryTreeNode<int>* root);
        BinaryTreeNode<int>* rotateRL(BinaryTreeNode<int>* root);
        BinaryTreeNode<int>* rotate(BinaryTreeNode<int>* root);

        BinaryTreeNode<int>* balance(BinaryTreeNode<int>* root);
        BinaryTreeNode<int>* rotateR0(BinaryTreeNode<int>* root);
        BinaryTreeNode<int>* rotateR1(BinaryTreeNode<int>* root);
        BinaryTreeNode<int>* rotateR_1(BinaryTreeNode<int>* root);
        BinaryTreeNode<int>* rotateL0(BinaryTreeNode<int>* root);
        BinaryTreeNode<int>* rotateL1(BinaryTreeNode<int>* root);
        BinaryTreeNode<int>* rotateL_1(BinaryTreeNode<int>* root);
};

AVL::AVL()
    : AVLroot(nullptr)
{
}
AVL::~AVL()
{
    if(AVLroot) {
        delete AVLroot->left;
        delete AVLroot->right;
        delete AVLroot;
    }
}
void AVL::insert(int data)
{
    insert(AVLroot, data);
}
bool AVL::deleteData(int value)
{
    if(AVLroot==nullptr) return false;
    return deleteDataRec(AVLroot, value);
}
bool AVL::hasData(int value) const
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
void AVL::printTree() const
{
    printTree(AVLroot);
}
// This is recursive Delete
bool AVL::deleteDataRec(BinaryTreeNode<int>* &root, int value)
{
    bool deleted=false;
    if(root==nullptr) return false;
    else if(root->data==value) {
        // Delete Root
        if(root->left && root->right)
        {
            // Special case where both subtrees of node to deleted exist
            // We can delete either largest of left subtree or 
            // smallest of right subtree. And replace the contents of curr
            // with content of deleted node.
            // Here, we calculate height of root. And if some subtree has more
            // hight, we delete the node from that part.
            int ht = height(root);
            if(root->bf > 0)
            {
                // Delete largest value of left subtree
                BinaryTreeNode<int> *temp = root->left;
                int largest = temp->data;
                while(temp!=nullptr)
                {
                    largest = temp->data;
                    temp = temp->right;
                }
                deleteDataRec(root, largest);
                root->data = largest;
                return true;
            }
            // Here, we are deleting smallest of right subtree.
            BinaryTreeNode<int> *temp = root->right;
            int smallest = temp->data;
            while(temp!=nullptr)
            {
                smallest = temp->data;
                temp = temp->left;
            }
            deleteDataRec(root, smallest);
            root->data = smallest;
        }
        // At least One subtree is empty
        else if(root->left)
        {
            // Right subtree is empty
            BinaryTreeNode<int> *temp = root->left;
            delete root;
            root = temp;
        }
        else 
        {
            // Left subtree is empty
            BinaryTreeNode<int> *temp = root->right;
            delete root;
            root = temp;
        }
        deleted = true;
    }
    else if(root->data>value){
        deleted = deleteDataRec(root->left, value);
    }
    else{
        deleted = deleteDataRec(root->right, value);
    }
    if(deleted && root)
    {
        int ht=height(root);
        if(root->bf < -1 || 1 < root->bf)
            root = balance(root);
    }
    return deleted;
}
bool AVL::deleteData(BinaryTreeNode<int>* &root, int value)
{
    BinaryTreeNode<int> *curr=root, *prev=nullptr;
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
        deleteData(curr, smallest);
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
            root = temp;
            delete curr;
            return true;
        }
        if(prev->left==curr) prev->left = temp;
        else prev->right = temp;
        delete curr;
        return true;
    }
    // Left subtree is empty
    BinaryTreeNode<int> *temp = curr->right;
    if(prev==nullptr)
    {
        // We are deleting the root node
        root = temp;
        delete curr;
        return true;
    }
    if(prev->left==curr) prev->left = temp;
    else prev->right = temp;
    delete curr;
    return true;
}
void AVL::printTree(BinaryTreeNode<int> *root) const
{
    if(root==nullptr) return;
    printTree(root->left);
    cout << root->data << ':';
    if(root->left) cout << "L:" << root->left->data << ",";
    if(root->right) cout << "R:" << root->right->data;
    cout << endl;
    printTree(root->right);
}
int AVL::height(BinaryTreeNode<int>* root) const
{
    if(root==nullptr) return 0;
    int hl = height(root->left);
    int hr = height(root->right);
    root->bf = hl-hr;
    return max(hl, hr) + 1;
}
BinaryTreeNode<int>* AVL::rotateLL(BinaryTreeNode<int>* root)
{
    cout << "Calling rotateLL on " << root->data << endl;
    BinaryTreeNode<int>* left = root->left;
    BinaryTreeNode<int>* balancedRight = left->right;
    root->left = balancedRight;
    left->right = root;
    return left;
}
BinaryTreeNode<int>* AVL::rotateRR(BinaryTreeNode<int>* root)
{
    cout << "Calling rotateRR on " << root->data << endl;
    BinaryTreeNode<int>* right = root->right;
    BinaryTreeNode<int>* balancedLeft = right->left;
    root->right = balancedLeft;
    right->left = root;
    return right;
}
BinaryTreeNode<int>* AVL::rotateLR(BinaryTreeNode<int>* root)
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
BinaryTreeNode<int>* AVL::rotateRL(BinaryTreeNode<int>* root)
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
BinaryTreeNode<int>* AVL::balance(BinaryTreeNode<int>* root)
{
    cout << "Calling balance on " << root->data << endl;
    if(root->bf==-2)
    {
        switch(root->right->bf)
        {
            case -1:
                root = rotateL_1(root);
                break;
            case 0:
                root = rotateL0(root);
                break;
            case 1:
                root = rotateL1(root);
                break;
            default:
                cout << "This should not be printed" << endl;
                break;
        }
    }
    else
    {
        switch(root->left->bf)
        {
            case -1:
                root = rotateR_1(root);
                break;
            case 0:
                root = rotateR0(root);
                break;
            case 1:
                root = rotateR1(root);
                break;
            default:
                cout << "This should not be printed" << endl;
                break;
        }
    }

    return root;
}
BinaryTreeNode<int>* AVL::rotate(BinaryTreeNode<int>* root)
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
bool AVL::insert(BinaryTreeNode<int>* &root, int data)
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

BinaryTreeNode<int>* AVL::rotateR0(BinaryTreeNode<int>* root)
{
    cout << "Calling rotateR0 on " << root->data << endl;
    BinaryTreeNode<int>* b = root->left;
    root->left = b->right;
    b->right = root;
    return b;
}
BinaryTreeNode<int>* AVL::rotateR1(BinaryTreeNode<int>* root)
{
    cout << "Calling rotateR1 on " << root->data << endl;
    BinaryTreeNode<int>* b = root->left;
    root->left = b->right;
    b->right = root;
    return b;
}
BinaryTreeNode<int>* AVL::rotateR_1(BinaryTreeNode<int>* root)
{
    cout << "Calling rotateR_1 on " << root->data << endl;
    BinaryTreeNode<int>* b = root->left;
    BinaryTreeNode<int>* c = b->right;
    BinaryTreeNode<int>* cl = c->left;
    BinaryTreeNode<int>* cr = c->right;
    b->right = cl;
    root->left = cr;
    c->left = b;
    c->right = root;
    return c;
}
BinaryTreeNode<int>* AVL::rotateL0(BinaryTreeNode<int>* root)
{
    cout << "Calling rotateL0 on " << root->data << endl;
    BinaryTreeNode<int>* b = root->right;
    root->right = b->left;
    b->left = root;
    return b;
}
BinaryTreeNode<int>* AVL::rotateL1(BinaryTreeNode<int>* root)
{
    cout << "Calling rotateL1 on " << root->data << endl;
    BinaryTreeNode<int>* b = root->right;
    root->right = b->left;
    b->left = root;
    return b;
}
BinaryTreeNode<int>* AVL::rotateL_1(BinaryTreeNode<int>* root)
{
    cout << "Calling rotateL_1 on " << root->data << endl;
    BinaryTreeNode<int>* b = root->right;
    BinaryTreeNode<int>* c = b->left;
    BinaryTreeNode<int>* cl = c->left;
    BinaryTreeNode<int>* cr = c->right;
    b->left = cr;
    root->right = cl;
    c->left = root;
    c->right = b;
    return c;
}
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
            case 4:
                tree->printTree();
                break;
            default:
                return 0;
        }
    }  
}
