#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class PriorityQueue
{
  vector<int> pq;
public:
  void insert(int value)
  {
    pq.push_back(value);
    int index = pq.size()-1;
    while(index>0 && pq[index]<pq[(index-1)/2])
    {
      pq[index] = pq[(index-1)/2];
      pq[(index-1)/2] = value;
      index = (index-1)/2;
    }
  }
  int removeMin()
  {
    if(pq.size()==0) return 0;
    int result = pq[0];
    pq[0] = pq[pq.size()-1];
    pq.pop_back();
    int index = 0, child1 = 2*index+1, child2 = child1+1;
    while(child2<pq.size())
    {
      /* Index has both child nodes */
      int swapIndex = pq[child1]<pq[child2] ? child1 : child2;
      if(pq[index]<pq[swapIndex]) return result;
      /* Swap index & swapIndex */
      int temp = pq[index];
      pq[index] = pq[swapIndex];
      pq[swapIndex] = temp;
      index = swapIndex;
      child1 = 2*index+1;
      child2 = child1+1;
    }
    /* Here: index does not have 2 children but may have left child */
    if(child1<pq.size() && pq[index]>pq[child1])
    {
      int temp = pq[index];
      pq[index] = pq[child1];
      pq[child1] = temp;
    }
    return result;
  }
  int min() const
  {
    if(pq.size()==0) return 0;
    return pq[0];
  }
  int size() const
  {
    return pq.size();
  }
  int capacity() const
  {
    return pq.capacity();
  }
  void print() const
  {
    for(vector<int>::const_iterator it=pq.begin(); it!=pq.end(); it++)
      cout << *it << ' ';
    cout << endl;
  }
};

void kSortedArray(int inout[], int n, int k) {
  /* Given a k-Sorted array, sort the array in descending order. For eg:
   * Input: 2 6 8 5 4 3
   * Output: 8 6 5 4 3 2 */
  if(inout==nullptr || n<=1 || k<=1) return;
  k %= n;  // k is smaller than n now
  //For descending order, we will use maxHeap
  priority_queue<int, vector<int>, greater<int> > pq;
  int i;
  for(i=0; i<k; i++)
    pq.push(inout[i]);
  for(i=0; i<n-k; i++)
  {
    inout[i] = pq.top();
    pq.pop();
    pq.push(inout[k+i]);
  }
  for(; i<n; i++)
  {
    inout[i] = pq.top();
    pq.pop();
  }
}

vector<int> kSmallest(int *input, int n, int k) {
  /* You are given with an integer k and an array of integers that contain
   * numbers in random order. Write a program to find k smallest numbers from
   * given array. You need to save them in an array and return it.
   * Time complexity should be O(nlogk) and space complexity should be not more
   * than O(k). For eg for array size 13 and k=4 :
   * Input: 2 12 9 16 10 5 3 20 25 11 1 8 6 
   * Output: 5 3 2 1 */
  // priority queue of STL is maxHeap by default. To make it minHeap:
  priority_queue<int, vector<int>, greater<int> > pq;
  for(int i=0; i<n; i++)
    pq.push(input[i]);
  vector<int> v;
  for(int i=0; i<k && !pq.empty(); i++)
  {
    v.push_back(pq.top());
    pq.pop();
  }
  return v;
}

void swap(int input[], int i, int j)
{
  int temp = input[i];
  input[i] = input[j];
  input[j] = temp;
}

void inplaceHeapSort(int input[], int n){
  /* Given an integer array of size n. Sort this array (in decreasing order)
   * using heap sort. Space complexity should be O(1). For eg:
   * Input: 2 6 8 5 4 3
   * Output: 8 6 5 4 3 2 */
  if(input==nullptr || n<2) return;
  // We already have a heap of size one. Create the minHeap of size n
  for(int i=1; i<n; i++)
  {
    // Add ith element to minHeap
    int index = i;
    while(index>0 && input[index]<input[(index-1)/2])
    {
      swap(input, index, (index-1)/2);
      //int temp = input[index];
      //input[index] = input[(index-1)/2];
      //input[(index-1)/2] = temp;
      index = (index-1)/2;
    }
  }
  // The minHeap is now created. pop the element using swap and reduce heapSize
  // by 1 everytime.
  for(int size=n-1; size>1; size--)
  {
    swap(input, 0, size);
    int index = 0, child1 = 2*index+1, child2 = child1+1;
    while(child2<size)
    {
      /* Index has both child nodes */
      int swapIndex = input[child1]<input[child2] ? child1 : child2;
      if(input[index]<input[swapIndex]) break;
      /* Swap index & swapIndex */
      swap(input, index, swapIndex);
      //int temp = input[index];
      //input[index] = input[swapIndex];
      //input[swapIndex] = temp;
      index = swapIndex;
      child1 = 2*index+1;
      child2 = child1+1;
    }
    /* Here: index does not have 2 children but may have left child */
    if(child1<size && input[index]>input[child1])
      swap(input, index, child1);
  }
}

int main()
{
  PriorityQueue h;
  int choice, value;
  cin >> choice;
  while(choice)
  {
    switch(choice)
    {
      case 1:
        // insert the value
        cin >> value;
        h.insert(value);
        break;
      case 2:
        h.removeMin();
    }
    h.print();
    cin >> choice;
  }
}

