#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

class node {
  public:
  int freq;
  char c;
  node *left, *right;

  node(int _freq, int _c)
    :freq(_freq), c(_c), left(nullptr), right(nullptr)
  {
  }
};

class myless {
  public:
    bool operator()(const node* p1, const node* p2) {
      return p1->freq > p2->freq;
}
};
/* Why is function not working instead of function object
bool myless(const pair<int,node*>& p1, const pair<int,node*>& p2) {
      return p1.first<p2.first;
}
*/

void addCode(node *root, string code, unordered_map<char, string>& map)
{
  if(root==nullptr) return;
  if(root->left==nullptr && root->right==nullptr) {
    // Leaf node
    map[root->c] = code;
    return;
  }
  addCode(root->left, code+"0", map);
  addCode(root->right, code+"1", map);
}

void huffman(string &data, unordered_map<char, string>& map) {
  // We will create a frequency map using hashing
  unordered_map<char, int> frequency;
  for(int i=0; i<data.size(); i++)
    frequency[data[i]]++;

  // Now we need to sort the characters on frequency.
  // Thus we will use min priority queue with pair <frequency, char>
  priority_queue<node*, vector<node*>, myless> pq;

  // Add all the character nodes to priority queue
  for(unordered_map<char, int>::iterator it = frequency.begin();
      it!=frequency.end(); it++) {
    const pair<char,int>& p1 = *it;
    node *ptr = new node(it->second, it->first);
    pq.push(ptr);
  }

  // Create a tree
  while(pq.size()>=2)
  {
    node* p1 = pq.top();
    pq.pop();
    node* p2 = pq.top();
    pq.pop();
    node *ptr = new node(p1->freq+p2->freq, 'I');
    ptr->left = p1;
    ptr->right = p2;
    pq.push(ptr);
  }
  // Here size of pq is 1
  // update the map
  addCode(pq.top(), " ", map);
}

// abbcccddddeeeee
int main()
{
  string data;
  cin >> data;
  unordered_map<char, string> map; // Code for each character
  huffman(data, map);
  unordered_map<char, string>::iterator it=map.begin();
  while(it!=map.end())
  {
    cout << it->first << ':' << it->second << endl;
    it++;
  }
}
