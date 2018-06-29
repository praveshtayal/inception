#include"qsort.cpp"
#include <iostream>
#define SIZE 1000
using namespace std;

int getArray(int arr[], int size)
{
  cout << "Please enter the size of array: ";
  cin >> size;
  cout << "Please enter the elements of array: ";
  // Read the array
  for(int j=0;j<size;++j) 
    cin >> arr[j];
  return size;
}

void printArray(int arr[], int size)
{
  // Print Array
  cout << "The array of size " << size << " is: " << endl;
  for(int i=0;i<size;++i)
    cout << arr[i] << ' ';
  cout << endl;
}

void printTable(int start, int end, int step)
{
  /* Given three values - Start Fahrenheit Value (S), End Fahrenheit value (E)
   * and Step Size (W), you need to convert all Fahrenheit values from Start to
   * End at the gap of W, into their corresponding Celsius values and print the
   * table. */
  for(int fahr=start; fahr<=end; fahr+=step)
      cout << fahr << '\t' << int((fahr-32)*5.0/9.0) << endl;
}

bool checkMember(int n)
{
  /* Check if n is fibonacci number */
  int i, fib[SIZE];
  fib[0]=0;
  fib[1]=1;
  for(i=2;fib[i-1]<n;++i)
  {
    fib[i] =fib[i-1]+fib[i-2];
  }
  if(n==0 || n==1 || n==fib[i-1]) return true;
  return false;
}

int sumArray()
{
  /* Given an array of length N, you need to find and print the sum of all
   * elements of the array. */
  int n,j,result, number;
  cin >> n;
    result = 0;
    for(j=1;j<=n;++j)
    {
      cin >> number;
      result += number;
    }
  cout << result << endl;
  return 0;
}

void reverseArray(int arr[], int size)
{
  /* An integer array is given. You need to reverse that array without using
   * any other extra array. That is, you need to change in the given array
   * itself. For eg: for input arrays of size 5:
   * Input: 1 2 3 4 5 
   * Output: 5 4 3 2 1 
   ***********************************************************************/
  int j,number;
  for(j=0;j<size/2;++j)
  {
    number = arr[j];
    arr[j] = arr[size-1-j];
    arr[size-1-j] = number;
  }
}

int diffEvenOddArray()
{
  /* Given an array A with N elements, you need to find difference of sum of
   * elements at even indices (E) and sum of elements at odd indices(O). Output
   * will be E - O */
  int n,j,even=0,odd=0;
  int arr[SIZE];
  cin >> n;
  // Read the array
  for(j=0;j<n;++j) 
    cin >> arr[j];
  for(j=0;j<n;j+=2) 
    even += arr[j];
  for(j=1;j<n;j+=2) 
    odd += arr[j];
  cout << even - odd << endl;
  return 0;
}

int linearSearch(int arr[], int n ,int val)
{
  /* Given a random integer array A and an element x. You need to search this
   * element x in the given array using linear search. Return the index of
   * element in the input. 
   * Linear search means, we need to compare elements from the array A one by
   * one with the element x, till we found the match or we reach the end of
   * array. If match found, return its index, and if not return -1. */
  for(int j=0;j<n;++j)
  {
    if(val==arr[j])
      return j;
  }
  return -1;
}

void swapAlternate(int arr[], int size)
{
  /* Given an array of length N, swap every pair of alternate elements in the
   * array. For eg for input array of size 6:
   * Input: 9 3 6 12 4 32
   * Output: 3 9 12 6 32 4
   ***********************************************************************/
  int j,number;
  for(j=0;j<size-1;j+=2)
  {
    number = arr[j];
    arr[j] = arr[j+1];
    arr[j+1] = number;
  }
}

void arrange(int arr[], int n)
{
  /* Given a number n, put all elements from 1 to n in an array in order
   * 1,3,.......4,2. */
  int j,k;
  for(j=0;j<n/2;++j)
    arr[j]=j*2+1;
  k=n;
  if(n%2)
    arr[j++]=k--;
  for(;j<n;++j,k-=2)
    arr[j]=k;
}

void arrange2(int arr[], int n)
{
  /* Given a number n, put all elements from 1 to n in an array in order
   * 1,3,.......4,2. */
  int si = 0, ei = n-1, val=1;
  while(si<ei)
  {
    arr[si++]=val++;
    arr[ei--]=val++;
  }
  if(n%2==1)  // if(si==ei)
    arr[si] = val;
}

int uniqueElement(int arr[], int size)
{
  /* Given an integer array of size 2N + 1. In this given array, N numbers are
   * present twice and one number is present only once in the array. You need
   * to find and return that number which is unique in the array. For eg for
   * input array of size 7
   * Input: 2 3 1 6 3 6 2
   * Output: 1 */
  int i, j;
  for(i=0;i<size;++i)
  {
    for(j=0;j<size;++j)
      if(arr[i] == arr[j] && i!=j) break;
    if(j==size)
      return arr[i];
  }
  // Note that this return will never be excecuted but provided fro compiler
  // warning suppression.
  return arr[size-1];
}

int missingNumber(int arr[], int size)
{
  /* Find duplicate: Given an array of integers of size n which contains
   * numbers from 0 to n - 2. Each number is present at least once. That is, if
   * n = 5, numbers from 0 to 3 is present in the given array at least once and
   * one number is present twice. You need to find and return that duplicate
   * number present in the array. Assume, duplicate number is always present in
   * the array. */
  int i, j;
  for(i=0;i<size;++i)
  {
    for(j=0;j<size;++j)
      if(arr[i] == arr[j] && i!=j) return arr[i];
  }
  return arr[0];
}

void intersection(int input1[], int input2[], int size1, int size2)
{
  /* Given two random integer arrays of size m and n, print their intersection.
   * That is, print all the elements that are present in both the given
   * arrays. Input arrays can contain duplicate elements. */
  int i, j;
  int *input3=new int[size2];

  for(j=0;j<size2;++j)
    input3[j] = input2[j];
  for(i=0;i<size1;++i)
  {
    for(j=0;j<size2;++j)
      if(input1[i] == input3[j])
      {
        input3[j]=INT_MAX;
        cout << input1[i] << endl;
        break;
      }
  }
  delete [] input3;
}

void pairSum(int input[], int size, int x)
  /* Given a random integer array A and a number x. Find and print the pair of
   * elements in the array which sum to x. Array A can contain duplicate
   * elements. While printing a pair, print the smaller element first. That is,
   * if a valid pair is (6, 5) print "5 6". There is no constraint that out of
   * 5 pairs which have to be printed in 1st line. You can print pairs in any
   * order, just be careful about the order of elements in a pair. */
{
  for(int i=0;i<size;++i)
  {
    int candidate = input[i];
    int pair = x - candidate;
    for(int j=i+1;j<size;++j)
      if(pair == input[j])
      {
        if(candidate < pair)
        	cout << candidate << ' ' << pair << endl;
        else
      		cout << pair << ' ' << candidate << endl;
      }
  }
}

void printOrder(int a, int b, int c)
{
  if(a<=b && a<=c)
  {
    if(b<c)
      cout << a << ' ' << b << ' ' << c << endl;
    else
      cout << a << ' ' << c << ' ' << b << endl;
  }
  else if(b<=a && b<=c)
  {
    if(a<c)
      cout << b << ' ' << a << ' ' << c << endl;
    else
      cout << b << ' ' << c << ' ' << a << endl;
  }
  else
  {
    if(a<b)
      cout << c << ' ' << a << ' ' << b << endl;
    else
      cout << c << ' ' << b << ' ' << a << endl;
  }
}

void FindTriplet(int arr[], int size, int x)
{
  /* Triplet Sum: Given a random integer array and a number x. Find and print
   * the triplets of elements in the array which sum to x. While printing
   * a triplet, print the smallest element first. That is, if a valid triplet
   * is (6, 5, 10) print "5 6 10". There is no constraint that out of
   * 5 triplets which have to be printed on 1st line. You can print triplets in
   * any order, just be careful about the order of elements in a triplet. */
  int i, j, k;
  for(i=0;i<size;++i)
    for(j=i+1;j<size;++j)
      for(k=j+1;k<size;++k)
        if(arr[i]+arr[j]+arr[k] == x)
          printOrder(arr[i],arr[j],arr[k]);
}

void SortZeroesAndOne(int arr[], int n)
{
  /* You are given an integer array A that contains only integers 0 and 1.
   * Write a function to sort this array. Find a solution which scans the array
   * only once. Don't use extra array. You need to change in the given array
   * itself. So no need to return or print anything. */
  int i, j, k;
  i=0;j=n-1;
  while(i<j)
  {
    while(arr[i]==0 && i<n) i++;
    while(arr[j]==1 && j>i) j--;
    if(i<j)
    {
      k=arr[i];
      arr[i] = arr[j];
      arr[j] = k;
    }
  }
}

int main()
{
  int n;
  int arr[SIZE];
  //printTable(0,100,20);
  //cout << checkMember(n) <<endl;
  //arrange(arr, n);
  n=getArray(arr,SIZE);
  quickSort(arr,n);
  //cout << uniqueElement(arr,n) <<endl;
  //int x; cin >> x; FindTriplet(arr, n, x);
  //SortZeroesAndOne(arr, n);
  printArray(arr,n);
  return 0;
}
