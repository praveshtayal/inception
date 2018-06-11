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
  for(int j=0;j<n;++j)
  {
    if(val==arr[j])
      return j;
  }
  return -1;
}

void swapAlternate(int arr[], int size)
{
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
  int i, j;
  int candidate, pair;
  for(i=0;i<size;++i)
  {
    candidate = input[i];
    pair = x - candidate;
    for(j=i+1;j<size;++j)
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
  if(a<b && a<c)
  {
    if(b<c)
      cout << a << ' ' << b << ' ' << c << endl;
    else
      cout << a << ' ' << c << ' ' << b << endl;
  }
  else if(b<a && b<c)
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
  int i, j, k;
  for(i=0;i<size;++i)
    for(j=i+1;j<size;++j)
      for(k=j+1;k<size;++k)
        if(arr[i]+arr[j]+arr[k] == x)
          printOrder(arr[i],arr[j],arr[k]);
}

void SortZeroesAndOne(int arr[], int n)
{
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

void arrays()
{
  int n;
  int arr[SIZE];
  //printTable(0,100,20);
  //cout << checkMember(n) <<endl;
  //arrange(arr, n);
  n=getArray(arr,SIZE);
  //cout << uniqueElement(arr,n) <<endl;
  int x; cin >> x; FindTriplet(arr, n, x);
  //SortZeroesAndOne(arr, n);
  //printArray(arr,n);
}
