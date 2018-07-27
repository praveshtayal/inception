#include<iostream>
#include<stack>
#include<queue>
//using namespace std;

class Node{
public:
    int data;
    Node *next;
    Node(int data){
        this -> data = data;
        this -> next = nullptr;
    }
};

int length(Node *head) {
  /* Given a linked list, find and return the length of input LL. */
  int result=0;
  while(head!=nullptr)
  {
    result++;
    head = head->next;
  }
  return result;
}

void printIthNode(Node *head, int i) {
  /* Given a linked list and a position i, print the node at ith position. If
   * position i is greater than length of LL, then don't print anything.*/
  int result=0;
  while(head!=nullptr && i!=result)
  {
    result++;
    head = head->next;
  }
  if(i==result)
    std::cout << head->data; 
}

Node* insertNode(Node *head, int pos, int data) {
  /* Given a linked list, an integer n and a position i, insert that node
   * n into Linked List at ith position. If position i is greater than length
   * of LL, you should return the same LL without any change. Indexing starts
   * from 0. You don't need to print the elements, just insert and return the
   * head of updated LL. */ 
  Node *curr=head;
  if(head==nullptr&&pos!=0) return nullptr;
  if(pos==0)
  {
    // Insert data at pos 0 
    Node *p = new Node(data);
    p->next = head;
    return p;
  }
  int result=0;
  while(curr!=nullptr && pos-1!=result)
  {
    result++;
    curr = curr->next;
  }
  if(pos-1==result)
  {
    // Insert data at pos. curr points to pos-1 index.
    Node *p = new Node(data);
    p->next = curr->next;
    curr->next = p;
  }
  return head;
}

Node* deleteNode(Node *head, int i) {
  /* Given a linked list and a position i, delete the node of ith position from
   * Linked List iteratively. If position i is greater than length of LL, then
   * you should return the same LL without any change. Indexing starts from 0.
   * You don't need to print the elements, just delete the node and return the
   * head of updated LL.*/
  Node *curr=head;
  if(head==nullptr) return nullptr;
  if(i==0)
  {
    Node *p = curr->next;
    delete curr;
    return p;
  }
  int result=0;
  while(curr!=nullptr && i-1!=result)
  {
    result++;
    curr = curr->next;
  }
  if(i-1==result)
  {
    Node *p = curr->next;
    if(p==nullptr)
      return head;
    curr->next = p->next;
    delete p;
  }
  return head;
}

int lengthRecursive(Node *head) {
  /* Given a linked list, find and return the length of input LL recursively.*/
  if(head==nullptr)
    return 0;
  int result=lengthRecursive(head->next);
  return result+1;
}

Node* insertNodeRec(Node *head, int i, int data) {
  /* Given a linked list, an integer n and a position i, Insert that node
   * n into Linked List at ith position recursively. If position i is greater
   * than length of LL, then you should return the same LL without any change.
   * And if position i is equal to length of input LL, insert the node at last
   * position. */
  if(head==nullptr&&i!=0) return nullptr;
  if(i==0)
  {
    // Insert data at i 0 
    Node *p = new Node(data);
    p->next = head;
    return p;
  }
  head->next=insertNodeRec(head->next,i-1,data);
  return head;
}

Node* deleteNodeRec(Node *head, int i) {
  /* Given a linked list and a position i, delete the node of ith position from
   * Linked List recursively. If position i is greater than length of LL, then
   * you should return the same LL without any change.*/
  Node *curr=head;
  if(head==nullptr) return nullptr;
  if(i==0)
  {
    Node *p = curr->next;
    delete curr;
    return p;
  }
  head->next=deleteNodeRec(head->next,i-1);
  return head;
}

Node* mergeTwoLLs(Node *head1, Node *head2) {
  /* Given two linked lists sorted in increasing order. Merge them in such
   * a way that the result list is also sorted (in increasing order). Try
   * solving with O(1) auxiliary space (in-place). You just need to return the
   * head of new linked list, don't print the elements.*/
  Node *head = nullptr;
  if(head1==nullptr)
    return head2;
  if(head2==nullptr)
    return head1;
  if(head1->data<=head2->data)
  {
    head=head1;
    head1=head1->next;
  }
  else
  {
    head=head2;
    head2=head2->next;
  }
  Node *curr=head;
  while(head1!=nullptr && head2!=nullptr)
  {
    if(head1->data<=head2->data)
    {
      curr->next=head1;
      head1=head1->next;
    }
    else
    {
      curr->next=head2;
      head2=head2->next;
    }
    curr=curr->next;
  }
  if(head1==nullptr)
    curr->next=head2;
  else
    curr->next=head1;
  return head;
}

Node* eliminate_duplicate(Node* head)
{
  /* Given a sorted linked list (elements are sorted in ascending order).
   * Eliminate duplicates from the given LL, such that output LL contains only
   * unique elements. */
  Node *curr=head;
  if(curr==nullptr) return head;
  Node *next=curr->next;
  while(next!=nullptr)
  {
    if(curr->data == next->data)
    {
      // Delete next node
      Node *p=next;
      curr->next = p->next;
      delete p;
      next = curr->next;
    }
    else
    {
      curr=next;
      next = curr->next;
    }
  }
  return head;
}

bool check_palindrome(Node* head)
{
  /* Note: This check for nullptr is redundant */
  if(head==nullptr) return true;
  std::stack<int> s;
  std::queue<int> q;
  while(head!=nullptr)
  {
    s.push(head->data);
    q.push(head->data);
    head = head->next;
  }
  int halfSize = s.size()/2;
  while(s.size()>halfSize)
  {
    int top = s.top();
    int front = q.front();
    if(top!=front) return false;
    s.pop(); q.pop();
  }
  return true;
}

Node* midpoint_linkedlist(Node *head)
{
  /* Given a linked list, find and return the midpoint. */
  Node *curr=head;
  int result=0;
  while(curr!=nullptr)
  {
    result++;
    curr = curr->next;
  }
  curr=head;
  for(int i=1;i<result/2;i++)
    curr = curr->next;
  return curr;
}

Node* midpoint_linkedlist2(Node *head)
{
  /* Given a linked list, find and return the midpoint. */
  Node *curr=head, *curr2=head;
  if(curr==nullptr) return nullptr; // 0 Node
  if(curr->next==nullptr || curr->next->next==nullptr) return curr; // 1 or 2 Node
  int result=0;
  while(curr!=nullptr)
  {
    result++;
    curr = curr->next;
  }
  curr=head;
  for(int i=1;i<result/2;i++)
    curr = curr->next;
  return curr;
}

void print_linkedlist_spl(Node *head)
{
  /* Print a given linked list in reverse order. You need to print the tail
   * first and head last. You can’t change any pointer in the linked list, just
   * print it in reverse order. */
  // GOOD PROBLEM for RECURSION
  if(head==nullptr) return;
  print_linkedlist_spl(head->next);
  std::cout << head->data << ' ';
}

Node* rev_linkedlist_itr(Node* head)
{
  /* Given a linked list, reverse it iteratively. */
  if(head==nullptr) return nullptr;
  else if(head->next==nullptr) return head;
  Node *prev=head, *curr=prev->next, *next=curr->next;
  /* Create Reversed List */
  prev->next =nullptr;
  while(next!=nullptr)
  {
    curr->next = prev;
    prev = curr;
    curr = next;
    next = next->next;
  }
  curr->next = prev;
  return curr;
}

Node *reverse_linked_list_rec(Node *head)
{
  /* Given a linked list, reverse it recursively. */
  if(head==nullptr) return nullptr;
  else if(head->next==nullptr) return head;
  Node *result=reverse_linked_list_rec(head->next);
  head->next->next=head;
  head->next=nullptr;
  return result;
}

Node* swap_nodes(Node *head,int i,int j)
{
  Node *prev, *curr=head, *previ, *curri, *prevj, *currj;
  prev = previ = curri = prevj = currj = nullptr;
  int count = 0;
  while(curr != nullptr)
  {
    if(count==i)
    {
      previ = prev;
      curri = curr;
    }
    else if(count==j)
    {
      prevj = prev;
      currj = curr;
    }
    prev = curr;
    curr = curr->next;
    count++;
  }
  if(curri==nullptr || currj==nullptr)
    return;

  if(previ==nullptr)
    head = currj;
  else
    previ->next = currj;

  if(prevj==nullptr)
    head = curri;
  else
    prevj->next = curri;

  curr = curri->next;
  curri->next = currj->next;
  currj->next = curr;

  return head;
}

Node* swap_nodes2(Node *head,int i,int j)
{
  /* Given a linked list, i & j, swap the nodes that are present at
   * i & j position in the LL. You need to swap the entire nodes, not just the
   * data. */
  if(i==j) return head; 
  if(i>j)
  {
    int temp=i;
    i=j;
    j=temp;
  }
  // Here i<j
  Node *curr=head, *prevI, *prevJ, *I, *J, *nextI, *nextJ;
  int result=0;
  if(i==0)
  {
    prevI = nullptr;
    I = head;
    nextI = I->next;
  }
  else
  {
    while(curr!=nullptr && i-1!=result)
    {
      result++;
      curr = curr->next;
    }
    prevI = curr;
    I = curr->next;
    nextI = I->next;
  }
  if(j==i+1)
  {
    /* Special Case: i and j are consecutive */
    J = nextI;
    nextJ = J->next;

    /* Swap */
    if(prevI!=nullptr) prevI->next = J;
    J->next = I;
    I->next = nextJ;
    if(i==0) return J;
    return head;
  }
  do {
    result++;
    curr = curr->next;
  } while(curr!=nullptr && j-1!=result);
  prevJ = curr;
  J = curr->next;
  nextJ = J->next;

  /* Swap I & J */
  if(prevI!=nullptr) prevI->next = J;
  J->next = nextI;
  prevJ->next = I;
  I->next = nextJ;

  //cout<< "i " << I->data << endl; 
  //cout<< "j " << J->data << endl; 
  if(i==0)
    return J;
  return head;
}

Node* nthNodeFromLastIter(Node *head, int n) {
  /* Given a linked list and an integer n you need to find and return the nth
   * node from last without calculating length of input linked list. Return
   * null if length of LL is smaller than n. Counting of nodes starts from 0 */
  int result=0;
  Node *curr=head, *next;
  while(curr!=nullptr && n!=result)
  {
    result++;
    curr = curr->next;
  }
  /* Here curr is n nodes ahead of head. Now we will move both head and curr
   * simultaneously untill curr is nullptr */
  if(curr==nullptr) return nullptr;
  next = curr->next;
  while(next!=nullptr)
  {
    curr = next;
    next = curr->next;
    head = head->next;
  }
  return head;
}

int indexOfNIter(Node *head, int n) {
  /* Given a linked list and an integer n you need to find and return index
   * where n is present in the LL. Do this iteratively. Return -1 if n is not
   * present in the LL. Indexing of nodes starts from 0. */
  int result=0;
  Node *curr=head, *next;
  while(curr!=nullptr && curr->data!=n)
  {
    result++;
    curr = curr->next;
  }
  if(curr==nullptr)
    return -1;
  return result;
}
int indexOfNRecursive(Node *head, int n) {
  /* Given a linked list and an integer n you need to find and return index
   * where n is present in the LL. Do this iteratively. Return -1 if n is not
   * present in the LL. Indexing of nodes starts from 0. */
  if(head==nullptr) return -1;
  if(head->data==n) return 0;
  int result=indexOfNRecursive(head->next,n);
  if(result==-1)
    return -1;
  return 1+result;
}

Node* mergeSort(Node *head) {
  /* Sort a given linked list using Merge Sort. */
  if(head==nullptr) return nullptr;
  if(head->next==nullptr) return head;
  /* We have atleast 2 Nodes. Split the list into two parts equally */
  Node* mid, *head2;
  mid = midpoint_linkedlist(head);
  head2 = mid->next;
  mid->next = nullptr;

  /* MegreSort the two lists */
  head = mergeSort(head);
  head2 = mergeSort(head2);
  head = mergeTwoLLs(head, head2);
  return head;
}

Node* bubble_sort_LinkedList_itr(Node* head)
{
  /* Sort a given linked list using Bubble Sort (iteratively). While sorting,
   * you need to swap the entire nodes, not just the data.*/
  if(head==nullptr || head->next==nullptr) return head;
  /* We have atleast 2 Nodes. Split the list into two parts equally */
  Node *nodei,*nodej;
  int i,j;
  for(i=0, nodei=head; nodei!=nullptr && nodei->next!=nullptr; i++, nodei=nodei->next)
    for(j=0, nodej=head; nodej->next!=nullptr; j++, nodej=nodej->next)
      if(nodej->data > nodej->next->data)  // if(arr[j]>arr[j+1])
        head = swap_nodes(head,j,j+1);
  return head;
  /*   
  for(int i=0;i<n-1;++i)
    for(int j=0;j<n-i-1;++j)
      if(arr[j]>arr[j+1])
  */
}

Node* append_LinkedList(Node* head,int n)
{
  /* Given a linked list and an integer n, append the last n elements of the LL
   * to front. */
    if(head==NULL || n<0) return NULL;
    int result=0;
    Node *curr=head, *next, *prev=head;
    while(curr!=NULL && n!=result)
    {
        result++;
        curr = curr->next;
    }   
    /* Here curr is n nodes ahead of prev. Now we will move both prev and curr
     * simultaneously untill curr is NULL */
    if(curr==NULL) return NULL;
    next = curr->next;
    while(next!=NULL)
    {   
        curr = next;
        next = curr->next;
        prev = prev->next;
    }   

    /* curr is last node and prev is prev node */
    curr->next = head;
    curr = prev->next;
    prev->next = NULL;
    return curr;
}

Node* kReverse(Node *head, int n)
{
  /* Implement kReverse( int k ) in a linked list i.e. you need to reverse
   * first K elements then reverse next k elements and join the linked list and
   * so on. Indexing starts from 0. If less than k elements left in the last,
   * you need to reverse them as well. If k is greater than length of LL,
   * reverse the complete LL. If n is 4 and LL is:
   * Input: 1 2 3 4 5 6 7 8 9 10
   * Output: 4 3 2 1 8 7 6 5 10 9 */
  if(head==nullptr || n<=1) return head;
  else if(head->next==nullptr) return head;
  // n is atleast 2 and we have atleast 2 nodes
  Node *prev=head, *curr=prev->next, *next;
  /* Create Reversed List */
  int i=1;
  prev->next =nullptr;
  while(curr!=nullptr && i<n)
  {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
    i++;
  }
  head->next = kReverse(curr, n);
  return prev;
}

Node* arrange_LinkedList(Node* head)
{
  /* Even after Odd LinkedList: Arrange elements in a given Linked List such
   * that, all even numbers are placed after odd numbers. Respective order of
   * elements should remain same.*/
  if(head==nullptr) return head;
  Node *even=nullptr, *odd=nullptr, *evenLast, *oddLast, *next;
  while(head!=nullptr)
  {
    next = head->next;
    if(head->data%2==0)
    {
      // add node to evenList
      if(even==nullptr)
        even = evenLast = head;
      else
        evenLast = evenLast->next = head;
    }
    else
    {
      // add node to oddList
      if(odd==nullptr)
        odd = oddLast = head;
      else
        oddLast = oddLast->next = head;
    }
    head->next = nullptr;
    head = next;
  }
  if(odd==nullptr) return even;
  oddLast->next = even;
  return odd;
}

Node* skipMdeleteN(Node *head, int M, int N) {
  /* Given a linked list and two integers M and N. Traverse the linked list
   * such that you retain M nodes then delete next N nodes, continue the same
   * until end of the linked list. That is, in the given linked list you need
   * to delete N nodes after every M nodes.*/
  if(head==nullptr || N<=0 || M<0)  return head;
  Node *curr=head, *prev, *next;
  int i;
  while(curr!=nullptr)
  {
    // skip M-1 nodes
    for(i=0; i<M-1 && curr!=nullptr; i++, curr = curr->next);
    if(curr==nullptr) return head;
    prev = curr; curr = curr->next;
    // delete N nodes
    for(i=0; i<N && curr!=nullptr; i++) 
    {
      next = curr->next;
      delete curr;
      curr = next;
    }
    prev->next = curr;
  }
  return head;
}

Node* rearrange(Node *head)
{
  /* Given a singly linked list L : L0→L1→…→Ln-1→Ln . Rearrange the nodes in
   * the list so that the new formed list is : L0→Ln→L1→Ln-1→L2→Ln-2→… 
   * You are required do this in-place without altering the nodes' values.
   * Input: 2 5 8 12
   * Output: 2 12 5 8 */
  if(head==nullptr) return head;
  Node *second=head->next, *prev=second, *last;
  if(prev==nullptr) return head;
  last = prev->next;
  if(last==nullptr) return head;
  // atleast 3 nodes are present
  while(last->next!=nullptr)
  {
    prev = last;
    last = last->next;
  }
  // here we have 4 pointers poing to head node, second node, last node and
  // 2nd last node(pointed to by prev). Note that second and prev may point to
  // same node
  head->next = last;
  last->next = second;
  prev->next = nullptr;
  last->next = rearrange(last->next);
  return head;
}

int main()
{
  Node *ll=nullptr, *pNode1;
  int i, data, len;
  std::cin >> data;
  for(i=0; data!=-1; i++)
  {
    ll = insertNode(ll,i,data);
    std::cin >> data;
  }
  //pNode1 = arrange_LinkedList(ll);
  //ll = mergeSort(ll);
  //ll = bubble_sort_LinkedList_itr(ll);
  ll = kReverse(ll, 4);
  len = length(ll);
  std::cout << "The link list has " << len << " elements\n";
  for(i=0; i<len; i++)
  {
    printIthNode(ll,i);
    std::cout << ' ';
  }
  std::cout << std::endl;

  /*
  std::cout << "The elements to swap have index "; 
  std::cin >> i >> data;
  std::cout << "The elements to swap have index " << i << " and " << data
    << "\n";
  ll = swap_nodes(ll,i,data);
  len = length(ll);
  std::cout << "The link list has " << len << " elements\n";
  for(i=0; i<len; i++)
  {
    printIthNode(ll,i);
    std::cout << ' ';
  }
  std::cout << std::endl;
  std::cin >> data;
  pNode1 = nthNodeFromLastIter(ll, data);
  std::cout << pNode1->data << std::endl;
  */
}
