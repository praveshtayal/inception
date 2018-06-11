#include<iostream>

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
  int result=0;
  while(head!=nullptr)
  {
    result++;
    head = head->next;
  }
  return result;
}

void printIthNode(Node *head, int i) {
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
  if(head==nullptr)
    return 0;
  int result=lengthRecursive(head->next);
  return result+1;
}

Node* insertNodeRec(Node *head, int i, int data) {
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
  return false;
    //write your code here
}

Node* midpoint_linkedlist(Node *head)
{
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
  if(head==nullptr) return nullptr;
  else if(head->next==nullptr) return head;
  Node *result=reverse_linked_list_rec(head->next);
  head->next->next=head;
  head->next=nullptr;
  return result;
}

Node* swap_nodes(Node *head,int i,int j)
{
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
  if(head==nullptr) return nullptr;
  if(head->next==nullptr) return head;
  /* We have atleast 2 Nodes. Split the list into two parts equally */
  Node *nodei,*nodej;
  int i,j;
  for(i=0, nodei=head; nodei!=nullptr; i++, nodei=nodei->next)
    for(j=0, nodej=head; nodej->next!=nullptr; j++, nodej=nodej->next)
      if(nodej->data > nodej->next->data)  // if(arr[j]>arr[j+1])
        head = swap_nodes(head,j,j+1);
  return head;
  /*   
  for(int i=0;i<n;++i)
    for(int j=0;j<n-i-1;++j)
      if(arr[j]>arr[j+1])
  */
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
  //ll = mergeSort(ll);
  ll = bubble_sort_LinkedList_itr(ll);
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
