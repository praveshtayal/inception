#include<iostream>
#include<stack>
#define TRIE_SIZE 26
#define STRING_SIZE 1024
using namespace std;

template<typename V>
class trie {
private:
  class trieNode {
  public:
    char c;
    trieNode **child;
    bool terminal;
    V value;
    trieNode(char _c='\0', V _value=0)
      : c(_c), terminal(false), value(_value)
    {
      child = new trieNode*[TRIE_SIZE];
      for(int i=0; i<TRIE_SIZE; i++)
        child[i] = nullptr;
    }
    ~trieNode()
    {
      if(child==nullptr) return;
      for(int i=0; i<TRIE_SIZE; i++)
        if(child[i]!=nullptr)
          delete child[i];
      delete [] child;
    }
  };
  trieNode *root;
public:
  trie()
  {
    root = new trieNode();
  }
  ~trie()
  {
    delete root;
  }
  void print() const
  {
    for(int i=0; i<TRIE_SIZE; i++)
    {
      trieNode *curr=root->child[i],*prev=nullptr;
      if(curr==nullptr) continue;
      char string[STRING_SIZE];
      int len=0;
      while(curr!=nullptr)
      {
        string[len++]=curr->c;
      }
      cout << string << endl;
    }
  }
  void remove(string key)
  {
    trieNode *curr=root,*prev=nullptr;
    stack<trieNode*> s;
    int len=key.length(), i;
    for(i=0; i<len;i++)
    {
      int index = key[i] - 'a';
      if(curr->child[index]==nullptr)
        return;
      curr = curr->child[index];
      s.push(curr);
      prev = curr;
    }
    /* curr holds the node to be deleted */
    s.pop();
    while(curr && curr->terminal==true)
    {
      delete curr;
      curr = nullptr;
      int index = key[--i] - 'a';
      if(!s.empty())
      {
        curr = s.top();
        s.pop();
        curr->child[index] = nullptr;
      }
      else
        root->child[index] = nullptr;
    }
  }
  V& operator[](string key)
  {
    trieNode *curr=root;
    int len=key.length();
    for(int i=0; i<len;i++)
    {
      int index = key[i] - 'a';
      if(curr->child[index]==nullptr)
        return root->value;
      curr = curr->child[index];
    }
    return curr->value;
  }
  void insert(string key, V value)
  {
    /* ToDo: key only has small characters from a to z */
    trieNode *curr=root, *prev=nullptr;
    int len=key.length();
    for(int i=0; i<len;i++)
    {
      int index = key[i] - 'a';
      if(curr->child[index]==nullptr)
        curr->child[index] = new trieNode(key[i], 0);
      curr = curr->child[index];
      if(prev==nullptr)
        root->child[index] = curr;
      prev = curr;
    }
    curr->terminal = true;
    curr->value = value;
  }
};

int main()
{
  int option=1, nWords, value;
  string word;
  trie<int> t;
  while(option!=0)
  {
    cout << "Please input the option (1) Insert, (2) Search, (3) Remove : ";
    cin >> option;
    switch(option)
    {
      case 1:
        cout << "Word and Value: ";
        cin >> word >> value;
        t.insert(word, value);
        break;
      case 2:
        cin >> word;
        cout << t[word] << endl;
        break;
      case 3:
        cin >> word;
        t.remove(word);
        break;
    }
  }
  //t.print();
  return 0;
}
