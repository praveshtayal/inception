#include<iostream>
#include<vector>
#include<stack>
#define TRIE_SIZE 26
#define STRING_SIZE 1024
using namespace std;

template<typename V>
class trie {
private:
  class trieNode {
  public:
    char data;
    trieNode **children;
    V value;
    trieNode(char _c='\0', V _value=0)
      : data(_c), value(_value)
    {
      children = new trieNode*[TRIE_SIZE];
      for(int i=0; i<TRIE_SIZE; i++)
        children[i] = nullptr;
    }
    ~trieNode()
    {
      if(children==nullptr) return;
      for(int i=0; i<TRIE_SIZE; i++)
        if(children[i]!=nullptr)
          delete children[i];
      delete [] children;
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
      trieNode *curr=root->children[i],*prev=nullptr;
      if(curr==nullptr) continue;
      char string[STRING_SIZE];
      int len=0;
      while(curr!=nullptr)
      {
        string[len++]=curr->data;
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
      if(curr->children[index]==nullptr)
        return;
      curr = curr->children[index];
      s.push(curr);
    }
    /* curr holds the node to be deleted */
    s.pop();
    while(curr)
    {
      delete curr;
      curr = nullptr;
      int index = key[--i] - 'a';
      if(!s.empty())
      {
        curr = s.top();
        s.pop();
        curr->children[index] = nullptr;
      }
      else
        root->children[index] = nullptr;
    }
  }
  V& operator[](string key)
  {
    trieNode *curr=root;
    int len=key.length();
    for(int i=0; i<len;i++)
    {
      int index = key[i] - 'a';
      if(curr->children[index]==nullptr)
        return root->value;
      curr = curr->children[index];
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
      if(curr->children[index]==nullptr)
        curr->children[index] = new trieNode(key[i], 0);
      curr = curr->children[index];
      if(prev==nullptr)
        root->children[index] = curr;
      prev = curr;
    }
    curr->value = value;
  }
  bool patternMatching(vector<string> vect, string pattern) {
    /* Given a list of n words and a pattern p that we want to search. Check if
     * the pattern p is present the given words or not. Return true or false */
    for(int i=0; i<vect.size(); i++)
    {
      int wordLength = vect[i].size();
      for(int j=0; j<wordLength; j++)
        t.insert(vect[i].substr(i,wordLength), 1);
    }
    return t[pattern]==1;
  }
};


bool findIfPalindromePair(vector<string> arr) {
  /* Givan n number of words, you need to find if there exist any two words
   * which can be joined to make a palindrome or any word itself is
   * a palindrome. Return true or false */
  return true;
}

void autoComplete(vector<string> input, string pattern) {
  /* Givan n number of words and an incomplete word w. You need to
   * auto-complete that word w. That means, find and print all the possible
   * words which can be formed using the incomplete word w. */
  trie<int> t;
  for(int i=0; i<input.size(); i++)
  {
    int wordLength = input[i].size();
    for(int j=0; j<wordLength; j++)
      t.insert(input[i].substr(i,wordLength), 1);
  }

}

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
