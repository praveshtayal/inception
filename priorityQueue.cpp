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

bool checkMaxHeap(int arr[], int n){
  /* Given an array of integers, check whether it represents max-heap or not.
   * Return true or false. */
  if(arr==nullptr || n<2) return true;
  int i;
  // Check for parent nodes having 2 children
  for(i=0; 2*(i+1)<n; i++)
    if( arr[i]<arr[2*(i+1)] || arr[i]<arr[2*i+1] )
      return false;
  // Check for last parent node which may have 1 child
  if( 2*i+1<n && arr[i]<arr[2*i+1] )
    return false;
  return true;
}

int kthLargest (vector<int> arr, int n, int k){
  /* Given an array A of random integers and an integer k, find and return the
   * kth largest element in the array. Try to do this question in less than
   * O(nlogn) time. */
  // Note that we have size available from vector as well as n
  // priority queue of STL is maxHeap by default. To make it minHeap:
  priority_queue<int, vector<int>, greater<int> > pq;
  k %= n;  // k is smaller than n now
  int i;
  for(i=0; i<k; i++)
    pq.push(arr[i]);
  for(; i<n; i++)
    if(arr[i]>pq.top())
    {
      pq.pop();
      pq.push(arr[i]);
    }
  return pq.top();
}

vector<int> mergeKSortedArrays(vector<vector<int>*> input){
  /* Given k different arrays, which are sorted individually (in ascending
   * order). You need to merge all the given arrays such that output array
   * should be sorted (in ascending order).*/
  vector<int> result;
  // priority queue of STL is maxHeap by default. To make it minHeap:
  // We are storing the element and its index in the pair
  priority_queue< pair<int, int>,
    vector< pair<int,int> >, 
    greater< pair<int, int> > > pq;
  pair<int, int> top;
  int arrayCount = input.size();
  // add 0th element of each array to pq
  vector<vector<int>::iterator> it;
  for(int i=0; i<arrayCount; i++)
  {
    it.push_back(input[i]->begin());
    if(it[i] != input[i]->end())
    {
      top.first = *it[i];
      top.second = i;
      pq.push(top);
      it[i]++;
    }
  }
  while(!pq.empty())
  {
    pair<int, int> top = pq.top();
    pq.pop();
    result.push_back(top.first);
    if(it[top.second] != input[top.second]->end())
    {
      top.first = *it[top.second];
      pq.push(top);
      it[top.second]++;
    }
  }

  return result;
}

void findMedian(int arr[], int n){
  /* You are given a stream of n integers. For every ith integer, add it to the
   * running list of integers and print the resulting median (of the list till
   * now). Print the only integer part of median. */
  /* Here we will use two heaps: minHeap and maxHeap. We will also store last
   * median value. minHeap will store values bigger than median and maxHeap
   * will store values smaller than median. We also have to ensure that number
   * of values in each heap is equal or differ by at max 1. */

  if(n<=0) return; // Nothing to do

  // The deafult is maxHeap, for minHeap we use
  priority_queue<int, vector<int>, greater<int> > minHeap;
  priority_queue<int> maxHeap;
  int median=arr[0];
  for(int i=0; i<n; i++)
  {
    if(minHeap.size()==maxHeap.size())
    {
      if(arr[i]<median)
      {
        maxHeap.push(arr[i]);
        median = maxHeap.top();
      }
      else
      {
        minHeap.push(arr[i]);
        median = minHeap.top();
      }
    }
    else if(minHeap.size()>maxHeap.size())
    {
      if(arr[i]<median)
      {
        maxHeap.push(arr[i]);
        median = (maxHeap.top() + minHeap.top())/2;
      }
      else
      {
        maxHeap.push(minHeap.top());
        minHeap.pop();
        minHeap.push(arr[i]);
        median = (maxHeap.top() + minHeap.top())/2;
      }
    }
    else
    {
      // Here minHeap.size()<maxHeap.size()
      if(arr[i]<median)
      {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        maxHeap.push(arr[i]);
        median = (maxHeap.top() + minHeap.top())/2;
      }
      else
      {
        minHeap.push(arr[i]);
        median = (maxHeap.top() + minHeap.top())/2;
      }
    }
    cout << median << endl;
  }
}

int buyTicket (int *arr, int n, int k){
  /* You want to buy a ticket for a well-known concert which is happening in
   * your city. But the number of tickets available is limited. Hence the
   * sponsors of the concert decided to sell tickets to customers based on some
   * priority.
   * A queue is maintained for buying the tickets and every person has attached
   * with a priority (an integer, 1 being the lowest priority). The tickets are
   * sold in the following manner -
   * 1. The first person (pi) in the queue asked to comes out.
   * 2. If there is another person present in the queue who has higher priority
   *    than pi, then ask pi to move at end of the queue without giving him the
   *    ticket.
   * 3. Otherwise, give him the ticket (and don't make him stand in queue again).
   * Giving a ticket to a person takes exactly 1 minutes and it takes no time
   * for removing and adding a person to the queue. And you can assume that no
   * new person joins the queue.
   * Given a list of priorities of N persons standing in the queue and the
   * index of your priority (indexing starts from 0). Find and return the time
   * it will take until you get the ticket.*/
  /* We can easily ignore the numbers whose priority is less than mine. Also,
   * all those who have priority more than mine will get the ticket before me.
   * So, I can count them. Now, it boils down to how many persons of same
   * priority will get the ticket before me. 
   * We will need maxHeap so that we can find out which will person will get
   * the ticket first */
  if(arr==nullptr) return 0;
  k %= n;  // k is smaller than n
  priority_queue< pair<int, int>,
    vector< pair<int,int> >, 
    less< pair<int, int> > > maxHeap;
  //pair<int, int> p;
  for(int i=0; i<n; i++)
    if(arr[i] >= arr[k])
    {
      pair<int, int> p(arr[i], i);
      maxHeap.push(p);
    }

  int time=0;
  // maxHeap will have atleast one element that is arr[k]
  while(maxHeap.top().second!=k)
  {
    time++;
    maxHeap.pop();
  }

  return time+1;
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
