#include<iostream>
#include<cmath>
#define THOUSAND 1000
using namespace std;

int getArray(int arr[], int size)
{
  cin >> size;
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

void printSArray(string a[], int size)
{
  /* This function is for non null terminated strings */
    cout << "The Array of size " << size << " is ";
    for(int i=0;i<size;i++) cout << a[i] << ' ';
    cout << endl;
}

bool checkBB(char input[]);
bool checkA(char input[])
{
  /* Each 'a' is followed by nothing or an 'a' or "bb" */
  if(input[0]=='\0') return true;
  if(input[0]=='a') return checkA(input+1);
  if(input[0]=='b')
  {
    if(input[1]=='\0') return false;
    if(input[1]=='b') return checkBB(input+2);
  }
  return false;
}

bool checkBB(char input[])
{
  /* Each "bb" is followed by nothing or an 'a' */
  if(input[0]=='\0') return true;
  if(input[0]=='a') return checkA(input+1);
  return false;
}

bool checkAB(char input[])
{
  /* Suppose you have a string made up of only 'a' and 'b'. Write a recursive
   * function that checks if the string was generated using the following
   * rules:
   * a. The string begins with an 'a'
   * b. Each 'a' is followed by nothing or an 'a' or "bb"
   * c. Each "bb" is followed by nothing or an 'a' */
  if(input[0]!='a') return false;
  return checkA(input+1);
}

int staircase(int n)
{
  /* A child is running up a staircase with N steps, and can hop either 1 step,
   * 2 steps or 3 steps at a time. Implement a method to count how many
   * possible ways the child can run up to the stairs. You need to return
   * number of possible ways W. */
  if(n<3) return n;
  if(n==3) return 4;
  return staircase(n-1)+staircase(n-2)+staircase(n-3);
}

int binarySearchIndex(int arr[], int start, int end, int val)
{
  /* Given an integer sorted array (sorted in increasing order) and an element
   * x, find the x in given array using binary search. Return the index of x.
   * Return -1 if x is not present in the given array. Note : If given array
   * size is even, take first mid.*/
  if(start<end) return -1;
  int mid=(start+end)/2;
  if(val == arr[mid])
      return mid;
  else if(val>arr[mid])
      return binarySearchIndex(arr,mid+1,end,val);
  else
      return binarySearchIndex(arr,start,mid-1,val);
}

int binarySearch(int arr[], int n, int val)
{
  return binarySearchIndex(arr,0,n-1,val);
}

int subset(int input[], int n, int output[][20]) {
  /* Given an integer array (of length n), find and return all the subsets of
   * input array. Subsets are of length varying from 0 to n, that contain
   * elements of the array. But the order of elements should remain same as in
   * the input array. The order of subsets are not important. */
  return 0;
}

void printSubsetsOfArrayHelper(int input[], int num, string str) {
    if(num==0)
    {
        if(str.length()){
          str = str.substr(1);
        }
        cout <<str <<endl;
        return;
    }

    printSubsetsOfArrayHelper(input+1,num-1,str + " " + to_string(input[0]));
    printSubsetsOfArrayHelper(input+1,num-1,str);
}
void printSubsetsOfArray(int input[], int size) {
  /* Given an integer array (of length n), find and return all the subsets of
   * input array. Subsets are of length varying from 0 to n, that contain
   * elements of the array. But the order of elements should remain same as in
   * the input array. Note : The order of subsets are not important. For input
   * array of size 3 with elements 15 20 12 is:
   * 12
   * 20
   * 20 12
   * 15
   * 15 12
   * 15 20
   * 15 20 12
   **************************************************************************/
  printSubsetsOfArrayHelper(input, size, "");
}


int recursion3()
{
  int n;
  int arr[THOUSAND];
  int output[THOUSAND];
  //n=getArray(arr,THOUSAND);
  //printArray(output,n);
  return 0;
}
