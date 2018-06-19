#include <iostream>
#include <string>
#include <map>
#define NODE_COUNT 1000
using namespace std;

template<typename V>
class MapNode
{
public:
  string key;
  V value;
  MapNode *next;
  MapNode(string _key, V _value)
    : key(_key), value(_value), next(nullptr)
  {
  }
  ~MapNode()
  {
    delete next;
  }
};
template<typename V>
class myMap
{
  MapNode<V> **bucket;
  int numBuckets;
  int count;
  //const static float load_factor = 0.7;

  int hash(const string &key) const
  {
    const int prime  = 37;
    int hashcode = 0;
    int coff = prime;
    for(int i=key.length()-1; i>0; i--)
    {
      hashcode += key[i] * prime;
      coff *= prime;
    }
    return hashcode % numBuckets;
  }
  void rehash()
  {
    MapNode<V> **old_bucket = bucket;
    int old_numBuckets = numBuckets;
    int old_count = count;

    count = 0;
    numBuckets *= 2;
    bucket = new MapNode<V>*[numBuckets];
    for(int i=0; i<numBuckets; i++)
      bucket[i] = nullptr;
    for(int i=0; i<old_numBuckets; i++)
    {
      MapNode<V> *head=old_bucket[i];
      while(head!=nullptr)
      {
        insert(head->key, head->value);
        head = head->next;
      }
    }
    for(int i=0; i<old_numBuckets; i++)
      if(old_bucket[i] != nullptr)  // Most probably this is not required
        delete old_bucket[i];
    delete [] old_bucket;
  }
public:
  // 19 is a prime number. It is a good idea to have numBuckets as prime No
  myMap(int _numBuckets=19)
    : numBuckets(_numBuckets), count(0)
  {
    bucket = new MapNode<V>*[numBuckets];
    for(int i=0; i<numBuckets; i++)
      bucket[i] = nullptr;
  }
  ~myMap()
  {
    for(int i=0; i<numBuckets; i++)
      if(bucket[i] != nullptr)  // Most probably this is not required
        delete bucket[i];
    delete [] bucket;
  }
  
  int size() const
  {
    return count;
  }

  V getValue(string key)
  {
    // This functions inserts the deafault value if key not present
    int index = hash(key);
    MapNode<V> *head = bucket[index];
    while(head!=nullptr)
    {
      if(head->key == key)
        return head->value;
      head = head->next;
    }
    // return default value
    V defaultValue;
    return defaultValue;
  }

  double loadFactor() const
  {
    return 1.0*count/numBuckets;
  }
  void insert(string key, V value)
  {
    if(1.0*count/numBuckets > 0.7)
      rehash();
    int index = hash(key);
    MapNode<V> *head = bucket[index];
    while(head!=nullptr)
    {
      if(head->key == key)
      {
        head->value = value;
        return;
      }
      head = head->next;
    }
    MapNode<V> *curr = new MapNode<V>(key, value);
    curr->next = bucket[index];
    bucket[index] = curr;


    // Update count
    count++;
  }

  V remove(string key)
  {
    int index = hash(key);
    V defaultValue;
    MapNode<V> *head = bucket[index], *prev=nullptr;
    while(head!=nullptr)
    {
      if(head->key == key)
      {
        count--;
        defaultValue = head->value;
        if(prev==nullptr)
        {
          /* first node in link list */
          bucket[index] = head->next;
        }
        else
        {
          prev->next = head->next;
        }
        head->next = nullptr;
        delete head;
        return defaultValue;
      }
      prev = head;
      head = head->next;
    }
    // return default value
    return defaultValue;
  }

};
//const static float myMap::load_factor = 0.7;

void intersection(int input1[], int input2[], int size1, int size2) {
   /* Given two random integer arrays, print their intersection. That is, print
   * all the elements that are present in both the given arrays. Input arrays
   * can contain duplicate elements. */
  if(input1==nullptr || size1<=0) return;
  if(input2==nullptr || size2<=0) return;
  unordered_map<int,int> count;
  for(int i=0; i<size1; i++)
  {
      count[input1[i]] += 1;
  }
  for(int i=0; i<size2 && count.count(input2[i]); i++)
  {
    cout << input2[i] << endl;
    if(count[input2[i]]==1)
      count.erase(input2[i]);
  }
}

int main()
{
  myMap<int> map(5); 
  for(int i=0; i<100; i++)
  {
    string key = "abc";
    char c1 = i+'0';
    key = key+c1;
    map.insert(key,i);
    //cout << i << ' ' << map.loadFactor() << endl;
  }
  map.remove("abc2");
  map.remove("abc9");
  for(int i=0; i<100; i++)
  {
    string key = "abc";
    char c1 = i+'0';
    key = key+c1;
    cout << key << ' ' << map.getValue(key) << endl;
  }
  cout << map.size() << endl;
}

